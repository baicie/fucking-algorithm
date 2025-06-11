# Babel 插件的单元测试

## 一、测试环境搭建

### 1. 依赖安装

```bash
npm install --save-dev jest @babel/core @babel/preset-env
```

### 2. Jest 配置

```javascript
// jest.config.js
module.exports = {
  testEnvironment: "node",
  testMatch: ["**/__tests__/**/*.test.js"],
  collectCoverage: true,
  coverageDirectory: "coverage",
};
```

### 3. 测试辅助函数

```javascript
const babel = require("@babel/core");

function transform(code, plugins) {
  return babel.transform(code, {
    plugins,
    babelrc: false,
  }).code;
}

module.exports = {
  transform,
};
```

## 二、基本测试用例

### 1. 插件功能测试

```javascript
const myPlugin = require("../src/my-plugin");
const { transform } = require("./utils");

describe("my babel plugin", () => {
  it("should transform arrow function", () => {
    const source = `const add = (a, b) => a + b;`;
    const expected = `const add = function(a, b) { return a + b; };`;

    const result = transform(source, [myPlugin]);
    expect(result.trim()).toBe(expected.trim());
  });
});
```

### 2. 快照测试

```javascript
describe("snapshot testing", () => {
  it("should match snapshot", () => {
    const source = `const x = 1;`;
    const result = transform(source, [myPlugin]);
    expect(result).toMatchSnapshot();
  });
});
```

### 3. 错误处理测试

```javascript
describe("error handling", () => {
  it("should throw specific error", () => {
    const source = `invalid code`;
    expect(() => {
      transform(source, [myPlugin]);
    }).toThrow("Syntax Error");
  });
});
```

## 三、高级测试技巧

### 1. 参数测试

```javascript
describe("plugin options", () => {
  it("should respect options", () => {
    const source = `class Example {}`;
    const options = { loose: true };
    const result = transform(source, [[myPlugin, options]]);
    expect(result).toMatchSnapshot();
  });
});
```

### 2. 多种输入测试

```javascript
const testCases = [
  {
    name: "arrow function",
    input: `() => {}`,
    output: `function() {}`,
  },
  {
    name: "class method",
    input: `class A { method() {} }`,
    output: `class A { method() {} }`,
  },
];

describe("multiple cases", () => {
  testCases.forEach(({ name, input, output }) => {
    it(`should handle ${name}`, () => {
      const result = transform(input, [myPlugin]);
      expect(result.trim()).toBe(output.trim());
    });
  });
});
```

### 3. 异步测试

```javascript
describe("async transformation", () => {
  it("should handle async code", async () => {
    const source = `async function test() {}`;
    const result = await babel.transformAsync(source, {
      plugins: [myPlugin],
    });
    expect(result.code).toMatchSnapshot();
  });
});
```

## 四、测试覆盖率

### 1. 配置覆盖率报告

```javascript
// jest.config.js
module.exports = {
  collectCoverage: true,
  coverageReporters: ["text", "lcov"],
  coverageThreshold: {
    global: {
      branches: 80,
      functions: 80,
      lines: 80,
      statements: 80,
    },
  },
};
```

### 2. 边界条件测试

```javascript
describe("edge cases", () => {
  it("should handle empty input", () => {
    expect(transform("", [myPlugin])).toBe("");
  });

  it("should handle comments", () => {
    const source = `// comment\nconst x = 1;`;
    expect(transform(source, [myPlugin])).toMatchSnapshot();
  });
});
```

### 3. 分支覆盖

```javascript
describe("branch coverage", () => {
  it("should cover all branches", () => {
    const cases = [
      "if (x) { }",
      "if (x) { } else { }",
      "switch (x) { case 1: break; }",
    ];

    cases.forEach((source) => {
      expect(transform(source, [myPlugin])).toMatchSnapshot();
    });
  });
});
```

## 五、持续集成

### 1. GitHub Actions 配置

```yaml
name: Test
on: [push, pull_request]

jobs:
  test:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - uses: actions/setup-node@v2
      - run: npm install
      - run: npm test
```

### 2. 测试报告

```javascript
// jest.config.js
module.exports = {
  reporters: [
    "default",
    [
      "jest-junit",
      {
        outputDirectory: "reports",
        outputName: "junit.xml",
      },
    ],
  ],
};
```

### 3. 性能测试

```javascript
describe("performance", () => {
  it("should complete within timeout", () => {
    const start = Date.now();
    const result = transform(largeSource, [myPlugin]);
    const duration = Date.now() - start;

    expect(duration).toBeLessThan(1000);
    expect(result).toMatchSnapshot();
  });
});
```

## 六、最佳实践

### 1. 测试组织

- 按功能分组
- 从简单到复杂
- 独立的测试用例

### 2. 测试命名

- 清晰描述测试目的
- 包含输入和预期
- 使用一致的命名规范

### 3. 测试维护

- 定期更新快照
- 移除冗余测试
- 保持测试简洁
