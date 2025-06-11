# Generator 和 SourceMap 详解

## 一、Generator 原理

### 1. 基本概念

- 将 AST 转换回代码字符串
- 递归遍历 AST 节点
- 根据节点类型生成对应代码

### 2. 节点打印示例

```javascript
// While 语句节点打印
WhileStatement {
    print('while')
    print(' (')
    print(node.test)
    print(') ')
    print(node.block)
}

// 条件表达式节点打印
ConditionalExpression {
    print(node.test)
    print(' ? ')
    print(node.consequent)
    print(' : ')
    print(node.alternate)
}
```

## 二、SourceMap 详解

### 1. 作用

- 调试代码时定位到源码
- 线上报错定位到源码
- 支持开发时的源码调试

### 2. SourceMap 格式

```javascript
{
    version : 3,
    file: "out.js",
    sourceRoot : "",
    sources: ["foo.js", "bar.js"],
    names: ["src", "maps", "are", "fun"],
    mappings: "AAgBC,SAAQ,CAAEA"
}
```

### 3. 字段说明

- version：sourcemap 版本
- file：转换后的文件名
- sourceRoot：转换前的文件所在目录
- sources：转换前的文件列表
- names：转换前的所有变量名和属性名
- mappings：源码和目标代码的映射关系

### 4. Mapping 格式

- 分号(;)：表示一行
- 逗号(,)：分隔一行内的映射
- 五位映射：
  1. 目标代码列数
  2. 源文件索引
  3. 源代码行数
  4. 源代码列数
  5. names 索引（可选）

## 三、SourceMap 的生成

### 1. 基本流程

1. Parse 时记录源码位置
2. Transform 时保留位置信息
3. Generate 时生成映射关系

### 2. 位置信息

```javascript
// AST 节点的位置信息
node.loc = {
  start: { line, column },
  end: { line, column },
};
```

### 3. 使用 source-map 库

```javascript
// 生成 sourcemap
const map = new SourceMapGenerator({
  file: "source-mapped.js",
});

map.addMapping({
  generated: {
    line: 10,
    column: 35,
  },
  source: "foo.js",
  original: {
    line: 33,
    column: 2,
  },
  name: "christopher",
});
```

## 四、SourceMap 的使用

### 1. 开发环境

```javascript
// 在文件末尾添加注释
//# sourceMappingURL=http://example.com/path/to/your/sourcemap.map
```

### 2. 生产环境

- 单独上传 sourcemap 到错误收集平台
- 使用 @sentry/webpack-plugin
- 使用 @sentry/cli 手动上传

### 3. Sourcemap 消费

```javascript
// 使用 source-map 库解析
const consumer = await SourceMapConsumer.with(
  rawSourceMap,
  null,
  (consumer) => {
    // 目标代码位置查询源码位置
    consumer.originalPositionFor({
      line: 2,
      column: 28,
    });

    // 源码位置查询目标代码位置
    consumer.generatedPositionFor({
      source: "foo.js",
      line: 2,
      column: 10,
    });
  }
);
```

## 五、最佳实践

### 1. Generator 优化

- 合理处理空白字符
- 优化生成代码的体积
- 保持代码可读性

### 2. Sourcemap 处理

- 开发环境启用完整 sourcemap
- 生产环境单独上传 sourcemap
- 合理设置 sourceRoot

### 3. 调试技巧

- 使用浏览器开发工具
- 配置 sourcemap 加载
- 使用条件断点
