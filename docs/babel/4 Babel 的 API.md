# Babel 的 API

## 一、核心 API 概览

### 1. @babel/parser

- 功能：源码转 AST
- 主要 API：
  ```javascript
  parse(code, options);
  parseExpression(code, options);
  ```
- 重要选项：
  - plugins：指定 jsx、typescript、flow 等插件
  - sourceType：指定解析模式（module/script/unambiguous）
  - allowXxx：指定允许的语法特性

### 2. @babel/traverse

- 功能：遍历和修改 AST
- 主要 API：
  ```javascript
  traverse(ast, visitor);
  ```
- visitor 模式：
  ```javascript
  traverse(ast, {
    FunctionDeclaration: {
      enter(path, state) {},
      exit(path, state) {},
    },
  });
  ```

### 3. @babel/types

- 功能：AST 节点的工具库
- 主要 API：
  - 创建节点：`t.identifier(name)`
  - 判断节点：`t.isIdentifier(node)`
  - 断言节点：`t.assertIdentifier(node)`

### 4. @babel/template

- 功能：批量创建 AST 节点
- 主要 API：
  ```javascript
  template.ast(code);
  template.program(code);
  template.expression(code);
  template.statements(code);
  ```

### 5. @babel/generator

- 功能：AST 转目标代码
- 主要 API：
  ```javascript
  generate(ast, options, code);
  ```
- 重要选项：
  - sourceMaps：是否生成 sourcemap
  - comments：是否包含注释
  - minified：是否压缩代码

### 6. @babel/core

- 功能：babel 转译核心功能
- 主要 API：
  ```javascript
  transformSync(code, options);
  transformFileSync(filename, options);
  transformFromAstSync(ast, code, options);
  ```
  异步版本：
  ```javascript
  transformAsync();
  transformFileAsync();
  transformFromAstAsync();
  ```

## 二、API 使用示例

### 1. Parser 示例

```javascript
const parser = require("@babel/parser");
const ast = parser.parse(code, {
  sourceType: "unambiguous",
  plugins: ["jsx"],
});
```

### 2. Traverse 示例

```javascript
const traverse = require("@babel/traverse").default;
traverse(ast, {
  CallExpression(path) {
    // 处理函数调用
  },
});
```

### 3. Types 示例

```javascript
const types = require("@babel/types");
types.isIdentifier(node, { name: "n" });
types.identifier("n");
```

### 4. Template 示例

```javascript
const template = require("@babel/template").default;
const ast = template.ast(`console.log("hello")`);
```

### 5. Generator 示例

```javascript
const generate = require("@babel/generator").default;
const { code, map } = generate(ast, {
  sourceMaps: true,
});
```

## 三、最佳实践

### 1. 错误处理

- 使用 @babel/code-frame 定位错误
- 添加错误处理和恢复机制

### 2. 性能优化

- 避免重复遍历
- 合理使用 path.skip()
- 适当缓存中间结果

### 3. 代码组织

- 模块化组织 visitor
- 合理使用 state 传递数据
- 保持代码清晰可维护

### 4. 调试技巧

- 使用 console.log 打印关键信息
- 使用 AST Explorer 验证转换
- 编写单元测试确保正确性
