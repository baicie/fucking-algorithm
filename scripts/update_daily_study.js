import { existsSync, readFileSync, writeFileSync } from "fs";
import { CliPrettify } from "markdown-table-prettify";
import { input, confirm, select } from "@inquirer/prompts";

// 配置项
const DAILY_MD_PATH = "daily.md";
const ALGORITHM_MD_PATH = "algorithm.md";

// 读取算法记录表，获取今日算法题完成数量
function getDailyAlgorithmCount() {
  if (!existsSync(ALGORITHM_MD_PATH)) {
    return 0;
  }

  const content = readFileSync(ALGORITHM_MD_PATH, "utf-8");
  const lines = content.split("\n");

  // 获取当前日期
  const today = new Date();
  const dateStr = `${String(today.getMonth() + 1).padStart(2, "0")}/${String(
    today.getDate()
  ).padStart(2, "0")}`;

  // 统计当天完成的算法题数量
  let count = 0;
  for (const line of lines) {
    if (line.includes(dateStr) && line.includes("✅")) {
      count++;
    }
  }

  return count;
}

// 更新日常学习记录
function updateDailyStudy(data) {
  let lines = [];

  if (!existsSync(DAILY_MD_PATH)) {
    lines = [
      "# 日常学习记录",
      "",
      "| 日期  | 算法题（完成情况） | 面试题（完成情况） | 英语学习（单词数） | 数学学习（章节） | 备注 |",
      "| ----- | ------------------ | ------------------ | ------------------ | ---------------- | ---- |",
    ];
  } else {
    lines = readFileSync(DAILY_MD_PATH, "utf-8").split("\n");
  }

  // 获取当前日期
  const today = new Date();
  const dateStr = `${String(today.getMonth() + 1).padStart(2, "0")}/${String(
    today.getDate()
  ).padStart(2, "0")}`;

  // 检查是否已存在今天的记录
  let existingEntryIndex = -1;
  for (let i = 0; i < lines.length; i++) {
    if (lines[i].includes(`| ${dateStr} |`)) {
      existingEntryIndex = i;
      break;
    }
  }

  // 构建记录行
  const algorithmCount = data.algorithmCount || getDailyAlgorithmCount();
  const interviewCount = data.interviewCount || 0;
  const englishWords = data.englishWords || 0;
  const mathChapter = data.mathChapter || "";
  const remark = data.remark || "——";

  const newEntry = `| ${dateStr} | ${
    algorithmCount > 0 ? "✅ " : ""
  }${algorithmCount} 道题 | ${
    interviewCount > 0 ? "✅ " : ""
  }${interviewCount} 道题 | ${englishWords} 单词 | ${mathChapter} | ${remark} |`;

  // 插入或更新记录
  if (existingEntryIndex >= 0) {
    lines[existingEntryIndex] = newEntry;
    console.log("已更新今日学习记录");
  } else {
    // 找到表格的位置（表头后一行）
    let insertPosition = lines.length;
    for (let i = 0; i < lines.length; i++) {
      if (lines[i].includes("| ----- |")) {
        insertPosition = i + 1;
        break;
      }
    }

    lines.splice(insertPosition, 0, newEntry);
    console.log("已添加今日学习记录");
  }

  // 格式化表格并写入文件
  try {
    const content = lines.join("\n");
    const formattedContent = CliPrettify.prettify(content);
    writeFileSync(DAILY_MD_PATH, formattedContent);
    console.log("文件已格式化并保存");
  } catch (error) {
    console.log(`格式化失败: ${error.message}`);
    writeFileSync(DAILY_MD_PATH, lines.join("\n"));
    console.log("文件已保存（未格式化）");
  }
}

// 交互式询问用户输入
async function promptUser() {
  console.log("📝 每日学习记录更新");
  console.log("==============================");

  // 获取自动计算的算法题数量
  const autoAlgorithmCount = getDailyAlgorithmCount();
  console.log(`检测到今日已完成算法题: ${autoAlgorithmCount} 道`);

  const useAutoCount = await confirm({
    message: "是否使用自动检测的算法题数量?",
    default: true,
  });

  const data = {};

  // 算法题完成数量
  if (useAutoCount) {
    data.algorithmCount = autoAlgorithmCount;
  } else {
    data.algorithmCount = Number(
      await input({
        message: "完成算法题数量:",
        default: String(autoAlgorithmCount),
      })
    );
  }

  // 面试题完成数量
  data.interviewCount = Number(
    await input({
      message: "完成面试题数量:",
      default: "0",
    })
  );

  // 英语学习单词数
  data.englishWords = Number(
    await input({
      message: "今日学习单词数:",
      default: "0",
    })
  );

  // 数学学习章节
  data.mathChapter = await input({
    message: "数学学习章节:",
    default: "",
  });

  // 今日学习评价
  const remarkOptions = ["优秀", "良好", "一般", "较差", "自定义"];
  const remarkChoice = await select({
    message: "今日学习评价:",
    choices: remarkOptions.map((option) => ({
      name: option,
      value: option,
    })),
  });

  if (remarkChoice === "自定义") {
    data.remark = await input({
      message: "请输入自定义评价:",
      default: "——",
    });
  } else {
    data.remark = remarkChoice;
  }

  return data;
}

// 主函数
async function main() {
  try {
    const data = await promptUser();
    updateDailyStudy(data);
  } catch (error) {
    console.error("发生错误:", error);
  }
}

// 执行主函数
main();
