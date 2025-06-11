# Babel 插件和 preset

## 一、插件基础

### 1. 插件类型

- 语法插件（Syntax Plugin）
  - 用于解析特定语法
  - 在 parser 阶段工作
- 转换插件（Transform Plugin）
  - 用于转换 AST
  - 在 traverse 阶段工作

### 2. 插件结构

```javascript
module.exports = function (api, options) {
  return {
    name: "my-plugin",
    visitor: {
      Identifier(path, state) {
        // 转换逻辑
      },
    },
    pre(state) {
      // 前置处理
    },
    post(state) {
      // 后置处理
    },
  };
};
```

## 二、常用插件开发技巧

### 1. 状态管理

```javascript
module.exports = function () {
  return {
    visitor: {
      Program: {
        enter(path, state) {
          state.count = 0;
        },
        exit(path, state) {
          console.log(`处理了 ${state.count} 个节点`);
        },
      },
    },
  };
};
```

### 2. 配置项处理

```javascript
module.exports = function (api, options) {
  const { target = "es5" } = options;

  return {
    visitor: {
      BinaryExpression(path) {
        if (target === "es5") {
          // ES5 转换逻辑
        }
      },
    },
  };
};
```

### 3. 复用工具函数

```javascript
const { addDefault } = require("@babel/helper-module-imports");

module.exports = function () {
  return {
    visitor: {
      Program(path) {
        addDefault(path, "lodash", { nameHint: "_" });
      },
    },
  };
};
```

## 三、preset 详解

### 1. preset 结构

```javascript
module.exports = function (api, options) {
  return {
    presets: [require("@babel/preset-env")],
    plugins: [
      [require("@babel/plugin-transform-arrow-functions"), { spec: true }],
      require("@babel/plugin-transform-block-scoping"),
    ],
  };
};
```

### 2. 常用 preset

- @babel/preset-env
- @babel/preset-react
- @babel/preset-typescript
- @babel/preset-flow

### 3. 配置选项

```javascript
{
  "presets": [
    ["@babel/preset-env", {
      "targets": {
        "browsers": ["last 2 versions"],
        "node": "current"
      },
      "modules": false,
      "useBuiltIns": "usage",
      "corejs": 3
    }]
  ]
}
```

## 四、插件开发最佳实践

### 1. 命名规范

- babel-plugin-xxx：独立插件
- babel-preset-xxx：preset 包
- @org/babel-plugin-xxx：组织作用域插件
- @org/babel-preset-xxx：组织作用域 preset

### 2. 错误处理

```javascript
module.exports = function () {
  return {
    visitor: {
      CallExpression(path) {
        try {
          // 转换逻辑
        } catch (err) {
          throw path.buildCodeFrameError("转换失败：" + err.message);
        }
      },
    },
  };
};
```

### 3. 测试用例

```javascript
describe("my babel plugin", () => {
  it("should transform correctly", () => {
    const { code } = babel.transform("code", {
      plugins: [myPlugin],
    });
    expect(code).toMatchSnapshot();
  });
});
```

## 五、高级特性

### 1. 插件排序

- Plugin 会运行在 Preset 之前
- Plugin 会从前到后顺序执行
- Preset 会从后到前逆序执行

### 2. 副作用处理

```javascript
module.exports = function () {
  return {
    visitor: {
      ImportDeclaration(path) {
        path.get("specifiers").forEach((specifier) => {
          if (specifier.isImportSpecifier()) {
            // 处理具名导入
          }
        });
      },
    },
  };
};
```

### 3. 缓存机制

```javascript
module.exports = function () {
  const cache = new Map();

  return {
    visitor: {
      Identifier(path) {
        if (cache.has(path.node.name)) {
          return cache.get(path.node.name);
        }
        const result = someExpensiveOperation();
        cache.set(path.node.name, result);
        return result;
      },
    },
  };
};
```

## 六、调试技巧

### 1. 打印调试

```javascript
module.exports = function () {
  return {
    visitor: {
      Identifier(path) {
        console.log("当前节点：", path.node);
        console.log("父节点：", path.parent);
        console.log("作用域：", path.scope);
      },
    },
  };
};
```

### 2. AST 可视化

- [AST Explorer](https://astexplorer.net/)
- [Babel AST Explorer](https://lihautan.com/babel-ast-explorer/)

### 3. 断点调试

```javascript
module.exports = function () {
  return {
    visitor: {
      Identifier(path) {
        debugger;
        // 转换逻辑
      },
    },
  };
};
```
