# Code-Frame 和代码高亮原理

## 一、Code-Frame 概述

### 1. 什么是 Code-Frame

- 在控制台打印代码位置的工具
- 支持语法高亮
- 显示出错位置的上下文

### 2. @babel/code-frame 基本使用

```javascript
const { codeFrameColumns } = require("@babel/code-frame");

try {
  throw new Error("发生错误");
} catch (err) {
  console.error(
    codeFrameColumns(
      `const name = guang`,
      {
        start: { line: 1, column: 14 },
      },
      {
        highlightCode: true,
        message: err.message,
      }
    )
  );
}
```

## 二、代码高亮原理

### 1. 基本流程

1. 词法分析，将代码分割成 token
2. 识别 token 类型
3. 根据类型添加不同的颜色样式

### 2. Token 类型

- 关键字（Keyword）
- 标识符（Identifier）
- 字符串（String）
- 数字（Number）
- 操作符（Operator）
- 注释（Comment）

### 3. 高亮实现方式

```javascript
// ANSI 转义序列
const RED = "\u001b[31m";
const BLUE = "\u001b[34m";
const RESET = "\u001b[0m";

function highlight(code) {
  return code
    .replace(/const|let|var/g, `${BLUE}$&${RESET}`)
    .replace(/[0-9]+/g, `${RED}$&${RESET}`);
}
```

## 三、@babel/highlight 实现

### 1. 主要功能

- 支持多种语言
- 自动检测语言类型
- 支持自定义主题

### 2. 使用方式

```javascript
const highlight = require("@babel/highlight");

const code = `function hello() {
  console.log("Hello World");
}`;

console.log(highlight(code));
```

### 3. 配置选项

```javascript
highlight(code, {
  forceColor: true, // 强制启用颜色
  linesAbove: 2, // 显示上文行数
  linesBelow: 3, // 显示下文行数
});
```

## 四、实现自定义 Code-Frame

### 1. 基本结构

```javascript
function createFrame(source, location, options = {}) {
  const lines = source.split("\n");
  const start = Math.max(location.start.line - 3, 0);
  const end = Math.min(location.end.line + 3, lines.length);

  return lines
    .slice(start, end)
    .map((line, index) => {
      const lineNumber = start + index + 1;
      const marker = lineNumber === location.start.line ? ">" : " ";
      return `${marker} ${lineNumber} | ${line}`;
    })
    .join("\n");
}
```

### 2. 添加高亮

```javascript
function highlightLine(line, column) {
  return line + "\n" + " ".repeat(column) + "^";
}
```

### 3. 错误标记

```javascript
function markErrorLocation(frame, location) {
  const lines = frame.split("\n");
  const errorLine = location.line - 1;
  lines[errorLine] = highlightLine(lines[errorLine], location.column);
  return lines.join("\n");
}
```

## 五、最佳实践

### 1. 错误处理

- 提供清晰的错误位置
- 显示适当的上下文
- 使用醒目的颜色标记

### 2. 性能优化

- 缓存高亮结果
- 按需加载高亮模块
- 限制显示行数

### 3. 用户体验

- 保持一致的样式
- 提供足够的上下文
- 清晰标记错误位置

### 4. 调试技巧

- 使用 code-frame 定位错误
- 结合 sourcemap 使用
- 自定义错误显示样式
