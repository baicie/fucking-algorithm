# Babel 的内置功能（下）

## 一、Polyfill 机制

### 1. @babel/polyfill

```javascript
// 入口文件引入
import "@babel/polyfill";

// webpack 配置
module.exports = {
  entry: ["@babel/polyfill", "./src/index.js"],
};
```

### 2. core-js

```javascript
// 按需引入
import "core-js/stable";
import "regenerator-runtime/runtime";

// babel.config.js 配置
module.exports = {
  presets: [
    [
      "@babel/preset-env",
      {
        useBuiltIns: "usage",
        corejs: 3,
      },
    ],
  ],
};
```

### 3. 自动注入策略

- entry: 入口处注入所有 polyfill
- usage: 按需注入使用到的 polyfill
- false: 不注入 polyfill

## 二、Runtime 转换

### 1. @babel/plugin-transform-runtime

```javascript
// 安装依赖
npm install --save-dev @babel/plugin-transform-runtime
npm install --save @babel/runtime

// 配置
{
  "plugins": [
    ["@babel/plugin-transform-runtime", {
      "corejs": 3,
      "helpers": true,
      "regenerator": true
    }]
  ]
}
```

### 2. 辅助函数处理

```javascript
// 转换前
class Person {}

// 转换后（不使用 runtime）
function _classCallCheck(instance, Constructor) {
  // ...
}

// 转换后（使用 runtime）
var _classCallCheck = require("@babel/runtime/helpers/classCallCheck");
```

### 3. 内置函数转换

```javascript
// 转换前
Promise.resolve(1);

// 转换后（使用 runtime + corejs）
var _Promise = require("@babel/runtime-corejs3/core-js-stable/promise");
_Promise.resolve(1);
```

## 三、JSX 转换

### 1. @babel/preset-react

```javascript
// 转换前
const element = <h1>Hello, world!</h1>;

// 转换后
const element = React.createElement("h1", null, "Hello, world!");
```

### 2. 自定义 JSX 转换

```javascript
// babel 配置
{
  "plugins": [
    ["@babel/plugin-transform-react-jsx", {
      "pragma": "h",
      "pragmaFrag": "Fragment"
    }]
  ]
}

// 转换结果
const element = h("h1", null, "Hello, world!");
```

### 3. 新 JSX 转换

```javascript
// 转换前
function App() {
  return <h1>Hello</h1>;
}

// 转换后
import { jsx as _jsx } from "react/jsx-runtime";

function App() {
  return _jsx("h1", { children: "Hello" });
}
```

## 四、TypeScript 支持

### 1. @babel/preset-typescript

```javascript
// tsconfig.json
{
  "compilerOptions": {
    "target": "es5",
    "module": "commonjs",
    "strict": true
  }
}

// babel.config.js
module.exports = {
  presets: ["@babel/preset-typescript"]
};
```

### 2. 类型擦除

```typescript
// 转换前
function greet(name: string): string {
  return `Hello, ${name}!`;
}

// 转换后
function greet(name) {
  return `Hello, ${name}!`;
}
```

### 3. 装饰器支持

```typescript
// 转换前
@decorator
class Example {
  @readonly
  name: string;
}

// 转换后
let Example = _decorate([decorator], function (_initialize) {
  class Example {
    constructor() {
      _initialize(this);
    }
  }
  return Example;
});
```

## 五、Flow 支持

### 1. @babel/preset-flow

```javascript
// .flowconfig
[ignore]
.*/node_modules/.*

[include]
./src/

// babel.config.js
module.exports = {
  presets: ["@babel/preset-flow"]
};
```

### 2. 类型注解转换

```javascript
// 转换前
function sum(a: number, b: number): number {
  return a + b;
}

// 转换后
function sum(a, b) {
  return a + b;
}
```

### 3. 泛型支持

```javascript
// 转换前
class Container<T> {
  value: T;

  constructor(value: T) {
    this.value = value;
  }
}

// 转换后
class Container {
  constructor(value) {
    this.value = value;
  }
}
```

## 六、优化技巧

### 1. 构建优化

```javascript
// babel.config.js
module.exports = {
  presets: [
    [
      "@babel/preset-env",
      {
        modules: false, // 保留 ES 模块语法
        loose: true, // 使用更简单的转换
        targets: {
          // 指定目标环境
          browsers: ["> 1%", "last 2 versions"],
        },
      },
    ],
  ],
};
```

### 2. 缓存配置

```javascript
// webpack 配置
module.exports = {
  module: {
    rules: [
      {
        test: /\.js$/,
        use: [
          {
            loader: "babel-loader",
            options: {
              cacheDirectory: true,
            },
          },
        ],
      },
    ],
  },
};
```

### 3. 按需加载

```javascript
// .babelrc
{
  "plugins": [
    ["import", {
      "libraryName": "lodash",
      "libraryDirectory": "",
      "camel2DashComponentName": false
    }]
  ]
}

// 使用
import { map } from 'lodash';
// 转换为
import map from 'lodash/map';
```
