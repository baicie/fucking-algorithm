import { existsSync, readFileSync, writeFileSync, readdirSync } from "fs";
import { CliPrettify } from "markdown-table-prettify";
import { select, confirm } from "@inquirer/prompts";

// 配置项
const ALGORITHM_MD_PATH = "algorithm.md";
const ALGORITHM_CPP_DIR = "src/algorithm-cpp";

// 难度选项
const DIFFICULTY_OPTIONS = [
  { name: "Easy", value: "Easy" },
  { name: "Medium", value: "Medium" },
  { name: "Hard", value: "Hard" },
];

// 模块选项
const MODULE_OPTIONS = [
  { name: "数组", value: "数组" },
  { name: "链表", value: "链表" },
  { name: "哈希表", value: "哈希表" },
  { name: "字符串", value: "字符串" },
  { name: "双指针", value: "双指针" },
  { name: "栈与队列", value: "栈与队列" },
  { name: "二叉树", value: "二叉树" },
  { name: "回溯算法", value: "回溯算法" },
  { name: "贪心算法", value: "贪心算法" },
  { name: "动态规划", value: "动态规划" },
  { name: "其他", value: "其他" },
];

// 难度映射表
const DIFFICULTY_MAP = {
  27: "Easy",
  704: "Easy",
  // 根据需要添加更多题目难度
};

// 默认难度
function getDifficulty(problemNum) {
  return DIFFICULTY_MAP[problemNum] || "Medium";
}

// 模块映射表
const MODULE_MAP = {
  27: "数组",
  704: "数组",
  // 根据需要添加更多模块映射
};

// 默认模块
function getModule(problemNum) {
  return MODULE_MAP[problemNum] || "其他";
}

// 从文件名提取题目编号
function getProblemNumber(filename) {
  const match = filename.match(/^(\d+)\./);
  if (match) {
    return match[1];
  }
  return null;
}

// 从文件名提取题目标题
function getProblemTitle(filename) {
  const match = filename.match(/^\d+\.(.*?)\.cpp$/);
  if (match) {
    return match[1];
  }
  return filename.replace(".cpp", "");
}

// 读取进度表，返回已有题目编号集合
function readAlgorithmMd() {
  const existingProblems = new Set();

  if (!existsSync(ALGORITHM_MD_PATH)) {
    return existingProblems;
  }

  const content = readFileSync(ALGORITHM_MD_PATH, "utf-8");
  const lines = content.split("\n");

  for (const line of lines) {
    if (line.includes("|")) {
      const parts = line.split("|").map((part) => part.trim());
      if (parts.length >= 4) {
        const title = parts[3] || "";
        const match = title.match(/^(\d+)\./);
        if (match) {
          existingProblems.add(match[1]);
        }
      }
    }
  }

  return existingProblems;
}

// 使用markdown-table-prettify API格式化表格
async function formatWithMarkdownTablePrettify(filePath) {
  try {
    // 读取文件内容
    const content = readFileSync(filePath, "utf-8");

    const formattedContent = CliPrettify.prettify(content);
    console.log(formattedContent);
    // 写回文件
    writeFileSync(filePath, formattedContent);

    console.log(`表格已使用markdown-table-prettify API格式化: ${filePath}`);
    return true;
  } catch (error) {
    console.log(
      `警告: markdown-table-prettify API格式化失败: ${error.message}`
    );
    return false;
  }
}

// 交互式获取题目信息
async function getProblemInfo(problemNum, problemTitle) {
  console.log(`\n为题目 ${problemNum}.${problemTitle} 设置分类信息:`);

  // 提供默认值作为参考
  const defaultDifficulty = getDifficulty(problemNum);
  const defaultModule = getModule(problemNum);

  // 自定义分类
  const difficulty = await select({
    message: "选择题目难度:",
    choices: DIFFICULTY_OPTIONS,
    default: defaultDifficulty,
  });

  const module = await select({
    message: "选择题目所属模块:",
    choices: MODULE_OPTIONS,
    default: defaultModule,
  });

  return { difficulty, module };
}

// 更新算法进度表
async function updateAlgorithmMd(newProblems) {
  if (newProblems.length === 0) {
    console.log("没有新的算法题目需要添加");
    return false;
  }

  let lines = [];

  if (!existsSync(ALGORITHM_MD_PATH)) {
    lines = [
      "# 🧠 算法刷题打卡进度表（ProgrammerCarl）",
      "",
      "| 日期  | 模块 | 题目         | 难度 | 是否做出 | 是否总结 | 是否复盘 | 备注 |",
      "| ----- | ---- | ------------ | ---- | -------- | -------- | -------- | ---- |",
    ];
  } else {
    lines = readFileSync(ALGORITHM_MD_PATH, "utf-8").split("\n");
  }

  // 获取当前日期
  const today = new Date();
  const dateStr = `${String(today.getMonth() + 1).padStart(2, "0")}/${String(
    today.getDate()
  ).padStart(2, "0")}`;

  // 找到表格的末尾
  let insertPosition = lines.length;
  for (let i = 3; i < lines.length; i++) {
    // 跳过表头
    if (lines[i].includes("|")) {
      insertPosition = i + 1;
    }
  }

  // 添加新题目
  const newEntries = [];
  for (const [problemNum, problemTitle, problemInfo] of newProblems) {
    const { difficulty, module } = problemInfo;

    const newEntry = `| ${dateStr} | ${module} | ${problemNum}.${problemTitle} | ${difficulty} | ✅ | ❌ | ❌ | —— |`;
    newEntries.push(newEntry);
  }

  // 插入新条目
  lines.splice(insertPosition, 0, ...newEntries);

  // 写回文件
  writeFileSync(ALGORITHM_MD_PATH, lines.join("\n"));

  console.log(`已添加 ${newProblems.length} 个新题目到进度表`);
  return true;
}

// 主函数
async function main() {
  // 读取现有题目
  const existingProblems = readAlgorithmMd();

  // 扫描算法文件夹
  const files = readdirSync(ALGORITHM_CPP_DIR);
  const newProblemFiles = [];

  for (const filename of files) {
    if (filename.endsWith(".cpp")) {
      const problemNum = getProblemNumber(filename);
      if (problemNum && !existingProblems.has(problemNum)) {
        const problemTitle = getProblemTitle(filename);
        newProblemFiles.push([problemNum, problemTitle]);
      }
    }
  }

  if (newProblemFiles.length === 0) {
    console.log("没有新的算法题目需要添加");
    return;
  }

  console.log(`发现 ${newProblemFiles.length} 个新题目待添加`);

  // 交互式获取每个题目的分类信息
  const newProblems = [];
  for (const [problemNum, problemTitle] of newProblemFiles) {
    const problemInfo = await getProblemInfo(problemNum, problemTitle);
    newProblems.push([problemNum, problemTitle, problemInfo]);
  }

  // 更新进度表
  const hasUpdated = await updateAlgorithmMd(newProblems);

  // 格式化文件
  if (
    hasUpdated ||
    (newProblems.length === 0 && existsSync(ALGORITHM_MD_PATH))
  ) {
    // 首先尝试使用markdown-table-prettify专门格式化表格
    formatWithMarkdownTablePrettify(ALGORITHM_MD_PATH);
  }
}

// 执行主函数
main().catch((error) => {
  console.error("发生错误:", error);
});
