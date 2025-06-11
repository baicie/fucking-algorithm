# Babel Traverse 的核心概念

## 一、Visitor 模式

### 1. 基本概念

- 设计模式的一种
- 分离对象结构和操作
- 允许结构和操作独立扩展

### 2. 在 Babel 中的应用

```javascript
traverse(ast, {
  Identifier(path, state) {},
  StringLiteral: {
    enter(path, state) {},
    exit(path, state) {},
  },
});
```

### 3. 多节点处理

```javascript
traverse(ast, {
  "FunctionDeclaration|VariableDeclaration"(path, state) {},
});
```

## 二、Path

### 1. 基本属性

- node：当前 AST 节点
- parent：父 AST 节点
- parentPath：父 AST 节点的 path
- scope：作用域信息
- hub：编译过程的上下文

### 2. 节点关系

```javascript
path {
    // 节点关系
    node
    parent
    parentPath
    scope
    hub
    container
    key
    listKey
}
```

### 3. 常用方法

```javascript
// 获取和设置
path.get(key);
path.set(key, node);

// 节点操作
path.insertBefore(nodes);
path.insertAfter(nodes);
path.replaceWith(replacement);
path.remove();

// 遍历相关
path.skip();
path.stop();

// 判断节点类型
path.isXxx(opts);
path.assertXxx(opts);
```

## 三、Scope（作用域）

### 1. 基本概念

- 记录标识符的声明和引用
- 形成作用域链
- 支持变量提升和闭包

### 2. 主要属性

```javascript
scope {
    bindings        // 当前作用域的所有绑定
    block           // 生成作用域的节点
    parent          // 父作用域
    parentBlock     // 父作用域节点
    path           // 生成作用域的节点的 path
    references     // 所有引用
}
```

### 3. 核心方法

```javascript
// 作用域操作
scope.getAllBindings();
scope.getBinding(name);
scope.hasBinding(name);
scope.getOwnBinding(name);

// 生成唯一标识符
scope.generateUid(name);
```

## 四、State

### 1. 作用

- 在遍历过程中传递数据
- 存储插件配置信息
- 保存文件级别的状态

### 2. 基本结构

```javascript
state {
    file    // 文件信息
    opts    // 插件配置
}
```

### 3. 使用示例

```javascript
traverse(
  ast,
  {
    Identifier(path, state) {
      state.customData = "xxx";
    },
  },
  state
);
```

## 五、最佳实践

### 1. Path 操作

- 合理使用 path API
- 注意节点的替换和删除
- 处理好父子节点关系

### 2. Scope 使用

- 正确处理变量声明
- 避免作用域污染
- 合理生成唯一标识符

### 3. Visitor 编写

- 选择合适的遍历时机
- 处理好节点的进入和退出
- 合理使用别名

### 4. State 管理

- 合理组织状态数据
- 注意数据的生命周期
- 避免状态泄露

## 六、调试技巧

### 1. 打印调试

```javascript
path.debug(); // 打印路径信息
scope.dump(); // 打印作用域信息
```

### 2. 断点调试

- 使用 node debugger
- 使用 VSCode 调试
- 设置条件断点

### 3. 错误处理

- 添加错误边界
- 使用 path.assertXxx
- 打印详细错误信息
