# Babel 的 AST（抽象语法树）

## 一、常见的 AST 节点类型

### 1. Literal（字面量）

- StringLiteral：字符串字面量
- NumericLiteral：数字字面量
- BooleanLiteral：布尔字面量
- RegExpLiteral：正则表达式字面量
- 示例：`'guang'`、`123`、`true`、`/\w+/g`

### 2. Identifier（标识符）

- 变量名、属性名、参数名等
- 特点：只能包含字母、数字、下划线(\_)、美元符号($)
- 不能以数字开头
- 示例：变量名、函数名、属性名等

### 3. Statement（语句）

- 可独立执行的代码单位
- 包括：
  - break、continue、debugger、return
  - if 语句、while 语句、for 语句
  - 声明语句
  - 表达式语句等

### 4. Declaration（声明）

- 特殊的语句类型
- 用于声明：
  - 变量（VariableDeclaration）
  - 函数（FunctionDeclaration）
  - 类（ClassDeclaration）
  - import/export

### 5. Expression（表达式）

- 特点：执行后有返回值
- 常见类型：
  - 数组表达式：[1,2,3]
  - 赋值表达式：a = 1
  - 运算表达式：1 + 2
  - 函数表达式：function(){}
  - 箭头函数：() => {}
  - 类表达式：class{}

### 6. Class 相关

- ClassBody：整个 class 的内容
- ClassProperty：类的属性
- ClassMethod：类的方法
  - kind 属性区分 constructor 和普通方法

### 7. Modules 相关

#### Import

- ImportDeclaration：import 声明
- 三种类型：
  1. named import: import {c, d} from 'c'
  2. default import: import a from 'a'
  3. namespace import: import \* as b from 'b'

#### Export

- 三种类型：
  1. ExportNamedDeclaration
  2. ExportDefaultDeclaration
  3. ExportAllDeclaration

## 二、特殊节点

### 1. Program & Directive

- Program：代表整个程序的节点
  - body：程序体
  - directives：指令集合
- Directive：指令，如 "use strict"

### 2. File & Comment

- File：最外层节点
  - program
  - comments
  - tokens
- Comment：注释节点
  - CommentBlock：块注释
  - CommentLine：行内注释

## 三、AST 节点的公共属性

1. **type**：节点类型

2. **位置信息**：

   - start：开始位置
   - end：结束位置
   - loc：位置对象
     - line：行号
     - column：列号

3. **注释相关**：

   - leadingComments：开始的注释
   - innerComments：中间的注释
   - trailingComments：结尾的注释

4. **extra**：额外信息
   - 用于特殊情况处理
   - 如 StringLiteral 的 raw 属性

## 四、AST 可视化工具

1. **[astexplorer.net](https://astexplorer.net/)**

   - 可视化查看代码的 AST
   - 支持切换不同的 parser
   - 可以修改 parse options
   - 支持保存和分享

2. **查看完整 AST 定义**
   - babel parser 仓库的 AST 文档
   - @babel/types 的 typescript 类型定义
