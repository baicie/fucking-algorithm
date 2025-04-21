import { existsSync, readFileSync, writeFileSync, readdirSync } from "fs";
import { execSync } from "child_process";

// 配置项
const ALGORITHM_MD_PATH = "algorithm.md";
const ALGORITHM_CPP_DIR = "src/algorithm-cpp";

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

// 使用Prettier格式化文件
function formatWithPrettier(filePath) {
  try {
    // 检查是否安装了prettier
    execSync("npx prettier --version", { stdio: "ignore" });

    // 使用prettier格式化文件
    execSync(`npx prettier --write "${filePath}"`, { stdio: "pipe" });
    console.log(`文件已使用Prettier格式化: ${filePath}`);
    return true;
  } catch (error) {
    console.log("警告: Prettier未安装或格式化失败，使用内置格式化功能");
    return false;
  }
}

// 更新算法进度表
function updateAlgorithmMd(newProblems) {
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
  for (const [problemNum, problemTitle] of newProblems) {
    const difficulty = getDifficulty(problemNum);
    const module = getModule(problemNum);

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
function main() {
  // 读取现有题目
  const existingProblems = readAlgorithmMd();

  // 扫描算法文件夹
  const newProblems = [];
  const files = readdirSync(ALGORITHM_CPP_DIR);

  for (const filename of files) {
    if (filename.endsWith(".cpp")) {
      const problemNum = getProblemNumber(filename);
      if (problemNum && !existingProblems.has(problemNum)) {
        const problemTitle = getProblemTitle(filename);
        newProblems.push([problemNum, problemTitle]);
      }
    }
  }

  // 更新进度表
  const hasUpdated = updateAlgorithmMd(newProblems);

  // 使用Prettier格式化文件
  if (
    hasUpdated ||
    (newProblems.length === 0 && existsSync(ALGORITHM_MD_PATH))
  ) {
    const prettierSuccess = formatWithPrettier(ALGORITHM_MD_PATH);
    if (!prettierSuccess) {
      console.log("使用内置格式化功能...");
      // 如果Prettier失败，使用原有的格式化功能
      const lines = readFileSync(ALGORITHM_MD_PATH, "utf-8").split("\n");
      const formattedLines = formatMarkdownTable(lines);
      writeFileSync(ALGORITHM_MD_PATH, formattedLines.join("\n"));
      console.log("文档格式已使用内置功能优化");
    }
  }
}

// 格式化表格（作为备选方案）
function formatMarkdownTable(lines) {
  // 找到表头和分隔行
  let headerIndex = -1;
  let separatorIndex = -1;

  for (let i = 0; i < lines.length; i++) {
    if (lines[i].includes("|") && lines[i].includes("--")) {
      separatorIndex = i;
      headerIndex = i - 1;
      break;
    }
  }

  if (headerIndex < 0 || separatorIndex < 0) {
    return lines; // 没找到表格结构，返回原始内容
  }

  // 解析表头，计算每列的最大宽度
  const headerParts = lines[headerIndex].split("|").map((part) => part.trim());
  const columnWidths = headerParts.map((part) => part.length);

  // 遍历表格数据，更新列宽
  for (let i = headerIndex + 2; i < lines.length; i++) {
    if (!lines[i] || !lines[i].includes("|")) continue;

    const rowParts = lines[i].split("|").map((part) => part.trim());
    for (let j = 0; j < rowParts.length; j++) {
      if (j < columnWidths.length) {
        columnWidths[j] = Math.max(columnWidths[j], rowParts[j].length);
      }
    }
  }

  // 重新构建表格
  const formattedLines = [...lines];

  // 重建分隔行
  const separatorParts = [];
  for (let i = 0; i < columnWidths.length; i++) {
    separatorParts[i] = "-".repeat(columnWidths[i]);
  }
  formattedLines[separatorIndex] = "| " + separatorParts.join(" | ") + " |";

  // 格式化表头和数据行
  formattedLines[headerIndex] = formatTableRow(headerParts, columnWidths);

  for (let i = headerIndex + 2; i < lines.length; i++) {
    if (!lines[i] || !lines[i].includes("|")) continue;

    const rowParts = lines[i].split("|").map((part) => part.trim());
    formattedLines[i] = formatTableRow(rowParts, columnWidths);
  }

  return formattedLines;
}

// 格式化表格行
function formatTableRow(parts, columnWidths) {
  const formattedParts = [];

  for (let i = 0; i < parts.length; i++) {
    if (i < columnWidths.length) {
      // 中文字符宽度计算
      const part = parts[i] || "";
      const visibleLength = getVisibleLength(part);
      const padding = columnWidths[i] - visibleLength;

      if (padding > 0) {
        formattedParts[i] = part + " ".repeat(padding);
      } else {
        formattedParts[i] = part;
      }
    }
  }

  return "| " + formattedParts.join(" | ") + " |";
}

// 计算字符串显示宽度（考虑中文字符占两个位置）
function getVisibleLength(str) {
  let length = 0;
  for (let i = 0; i < str.length; i++) {
    length += isFullWidthChar(str.charCodeAt(i)) ? 2 : 1;
  }
  return length;
}

// 判断是否为全角字符（中文、日文等）
function isFullWidthChar(charCode) {
  return (
    (charCode >= 0x3000 && charCode <= 0x9fff) || // CJK统一表意文字
    (charCode >= 0xff00 && charCode <= 0xffef) // 全角ASCII、全角标点
  );
}

// 执行主函数
main();
