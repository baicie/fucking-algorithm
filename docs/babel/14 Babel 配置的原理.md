# Babel 配置的原理

## 一、配置文件类型

### 1. 项目范围配置

```javascript
// babel.config.js
module.exports = {
  presets: [
    [
      "@babel/preset-env",
      {
        targets: "> 0.25%, not dead",
      },
    ],
  ],
  plugins: ["@babel/plugin-transform-runtime"],
};
```

### 2. 文件相对配置

```javascript
// .babelrc
{
  "presets": ["@babel/preset-react"],
  "plugins": [
    ["@babel/plugin-proposal-decorators", { "legacy": true }]
  ]
}
```

### 3. 包配置

```javascript
// package.json
{
  "babel": {
    "presets": ["@babel/preset-env"],
    "plugins": ["@babel/plugin-proposal-class-properties"]
  }
}
```

## 二、配置加载过程

### 1. 配置文件查找

```javascript
// 查找顺序
1. babel.config.js
2. .babelrc
3. package.json 中的 babel 字段
```

### 2. 配置合并策略

```javascript
// 合并示例
const result = {
  // 项目配置（babel.config.js）
  ...projectConfig,

  // 文件配置（.babelrc）
  ...fileConfig,

  // 编程式配置
  ...programmaticConfig,

  // 选项合并
  presets: [
    ...projectConfig.presets,
    ...fileConfig.presets,
    ...programmaticConfig.presets,
  ],
  plugins: [
    ...projectConfig.plugins,
    ...fileConfig.plugins,
    ...programmaticConfig.plugins,
  ],
};
```

### 3. 配置缓存

```javascript
// 缓存配置
{
  "babel": {
    "cacheDirectory": true,
    "cacheCompression": false
  }
}
```

## 三、配置项详解

### 1. 基本配置项

```javascript
module.exports = {
  // 源码类型
  sourceType: "module",

  // 代码生成选项
  generatorOpts: {
    retainLines: true,
    compact: true,
  },

  // 解析选项
  parserOpts: {
    strictMode: true,
    allowReturnOutsideFunction: false,
  },
};
```

### 2. 环境配置

```javascript
module.exports = {
  env: {
    development: {
      sourceMaps: "inline",
    },
    production: {
      minified: true,
    },
    test: {
      plugins: ["istanbul"],
    },
  },
};
```

### 3. 覆盖配置

```javascript
module.exports = {
  overrides: [
    {
      test: "./src/legacy/**/*.js",
      presets: [["@babel/preset-env", { targets: "ie 11" }]],
    },
  ],
};
```

## 四、扩展机制

### 1. 预设扩展

```javascript
// 自定义预设
module.exports = () => ({
  presets: [require("@babel/preset-env")],
  plugins: [
    [require("@babel/plugin-proposal-class-properties"), { loose: true }],
  ],
});
```

### 2. 插件扩展

```javascript
// 自定义插件
module.exports = function ({ types: t }) {
  return {
    name: "custom-plugin",
    visitor: {
      Identifier(path) {
        // 转换逻辑
      },
    },
  };
};
```

### 3. 配置函数

```javascript
module.exports = function (api) {
  api.cache(true);

  const presets = [
    /* ... */
  ];
  const plugins = [
    /* ... */
  ];

  return {
    presets,
    plugins,
    env: {
      test: {
        sourceMaps: "inline",
      },
    },
  };
};
```

## 五、配置最佳实践

### 1. 模块化配置

```javascript
// babel.config.js
const presets = require("./babel/presets");
const plugins = require("./babel/plugins");
const env = require("./babel/env");

module.exports = {
  presets,
  plugins,
  env,
};
```

### 2. 条件配置

```javascript
module.exports = function (api) {
  const isTest = api.env("test");
  const isDevelopment = api.env("development");

  return {
    presets: [
      [
        "@babel/preset-env",
        {
          targets: isTest ? { node: "current" } : { browsers: "> 0.25%" },
        },
      ],
    ],
    plugins: [isDevelopment && "react-refresh/babel"].filter(Boolean),
  };
};
```

### 3. 性能优化

```javascript
module.exports = {
  // 缓存配置
  cacheDirectory: true,

  // 排除不需要转换的文件
  ignore: ["src/**/*.spec.js", "node_modules"],

  // 只包含需要转换的文件
  only: ["src/**/*.js", "packages/*/src/**/*.js"],
};
```

## 六、调试技巧

### 1. 配置调试

```javascript
module.exports = function (api) {
  // 打印环境信息
  console.log("Babel ENV:", api.env());
  console.log(
    "Cache:",
    api.cache.using(() => process.env.NODE_ENV)
  );

  return {
    // 配置项
  };
};
```

### 2. 插件调试

```javascript
{
  "plugins": [
    ["@babel/plugin-transform-runtime", {
      "debug": true
    }]
  ]
}
```

### 3. 输出调试

```javascript
module.exports = {
  // 生成 sourcemap
  sourceMaps: true,

  // 保留行号
  retainLines: true,

  // 输出注释
  comments: true,
};
```
