# JavaScript Parser 的历史演进

## 一、早期阶段：SpiderMonkey 与 estree 标准

### 1. SpiderMonkey

- Mozilla 的 JS 引擎
- 在 MDN 上公布了 parser API 和 AST 标准
- 成为后续 JS Parser 的基础

### 2. Esprima

- 最早的 JS Parser 之一
- 基于 SpiderMonkey 的 AST 标准
- 形成了 estree 标准
- 问题：ES 新特性支持较慢

### 3. Espree

- ESLint 的默认 parser
- 最初是 Esprima 的 fork 版本
- 后来基于 Acorn 重新实现
- 保持 estree 标准

## 二、Acorn 的崛起

### 1. Acorn 的优势

- 速度更快
- 支持插件机制
- 保持 estree 标准
- 被广泛采用

### 2. 基于 Acorn 的工具

- Espree（ESLint 的 parser）
- Babel Parser（原 Babylon）
  - 扩展了 estree AST
  - 支持更多语法特性

## 三、Babel Parser 的扩展

### 1. 对 estree AST 的扩展

- Literal 的细分
  - StringLiteral
  - NumericLiteral
  - BooleanLiteral
  - RegExpLiteral 等
- Property 的细分
  - ObjectProperty
  - ObjectMethod
- 其他扩展
  - Program 和 BlockStatement 支持 directives
  - ChainExpression 的替换
  - ImportExpression 的处理

## 四、Acorn 插件机制

### 1. 插件实现方式

```javascript
module.exports = function (Parser) {
  return class extends Parser {
    // 重写相关方法
  };
};
```

### 2. 插件开发示例

```javascript
// 添加新关键字
parse(program) {
    var newKeywords = "break ... new guang";
    this.keywords = new RegExp("^(?:" + newKeywords.replace(/ /g, "|") + ")$")
    return(super.parse(program));
}

// 处理新语法
parseStatement(context, topLevel, exports) {
    if (this.type == Parser.acorn.keywordTypes["guang"]) {
        // 处理新语法
    }
    return super.parseStatement(context, topLevel, exports);
}
```

## 五、其他 Parser

### 1. 非 estree 标准的 Parser

- Terser
- TypeScript
- 各自实现自己的 AST 标准

### 2. 选择考虑因素

- 性能要求
- 语法支持范围
- 社区活跃度
- 维护状况

## 六、最佳实践

### 1. Parser 选择

- 标准场景使用 Acorn
- 需要 TypeScript 支持使用 @babel/parser
- 需要高度定制使用专门的 Parser

### 2. 插件开发

- 合理使用 Acorn 插件机制
- 注意词法分析和语法分析的配合
- 保持良好的错误处理

### 3. AST 标准

- 优先使用 estree 标准
- 必要时再考虑自定义 AST
- 注意与工具链的兼容性
