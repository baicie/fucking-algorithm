const fs = require("fs");
const path = require("path");

const structure = {
  基础知识: [
    "HTML.md",
    "CSS.md",
    "JavaScript.md",
    "TypeScript.md",
    "浏览器原理.md",
  ],
  "框架相关/Vue": ["响应式原理.md", "生命周期.md"],
  "框架相关/React": [
    "Hooks详解.md",
    "组件设计.md",
    "性能优化.md",
    "状态管理.md",
  ],
  项目实战: ["项目架构.md", "组件抽象.md", "低代码平台实践.md"],
  面试准备: ["高频八股文.md", "手写题合集.md", "面试复盘记录.md"],
  算法与手写: ["数组相关.md", "深拷贝.md", "手写Promise.md"],
  工程化: ["Vite配置.md", "打包原理.md", "模块系统.md"],
  随记区: ["一句话知识点.md", "今天学到了什么.md", "灵感记录.md"],
};

const baseDir = path.resolve(__dirname, "前端成长笔记");

function createFile(
  filePath,
  content = "# 笔记标题\n\n## ✅ 一句话总结\n\n## 💡 详细理解\n\n## 🧪 典型面试问法\n\n## 🔍 示例代码\n\n## 🚨 易错点\n\n## 🧩 我的总结 & 适用场景\n"
) {
  if (!fs.existsSync(filePath)) {
    fs.writeFileSync(filePath, content, "utf-8");
    console.log("📄 创建文件:", filePath);
  }
}

function createStructure() {
  for (const folder in structure) {
    const fullFolderPath = path.join(baseDir, folder);
    fs.mkdirSync(fullFolderPath, { recursive: true });

    const files = structure[folder];
    files.forEach((file) => {
      const fullFilePath = path.join(fullFolderPath, file);
      createFile(fullFilePath);
    });
  }
}

createStructure();
