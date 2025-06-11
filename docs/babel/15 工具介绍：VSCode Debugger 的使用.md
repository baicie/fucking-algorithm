# VSCode Debugger 的使用

## 一、基础配置

### 1. launch.json 配置

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "type": "node",
      "request": "launch",
      "name": "Debug Babel Plugin",
      "program": "${workspaceFolder}/src/index.js",
      "skipFiles": ["<node_internals>/**"]
    }
  ]
}
```

### 2. 断点类型

- 行断点：点击行号左侧
- 条件断点：右键行号，设置条件
- 日志断点：右键行号，添加日志消息

### 3. 调试控制

- F5：启动/继续
- F10：单步跳过
- F11：单步进入
- Shift+F11：单步退出
- F9：切换断点

## 二、Babel 插件调试

### 1. 源码映射

```javascript
// .vscode/launch.json
{
  "configurations": [
    {
      "type": "node",
      "request": "launch",
      "name": "Debug Transform",
      "program": "${workspaceFolder}/src/transform.js",
      "sourceMaps": true,
      "outFiles": [
        "${workspaceFolder}/lib/**/*.js"
      ]
    }
  ]
}
```

### 2. 调试变量

```javascript
module.exports = function ({ types: t }) {
  return {
    visitor: {
      Identifier(path) {
        debugger; // 设置断点
        console.log("当前节点：", path.node);
        console.log("父节点：", path.parent);
      },
    },
  };
};
```

### 3. 监视表达式

```javascript
// 在调试视图中添加监视
path.node.name;
path.scope.bindings;
path.parentPath.type;
```

## 三、高级调试技巧

### 1. 条件断点

```javascript
// 在特定条件下中断
{
  Identifier(path) {
    // 当标识符名为 'debug' 时中断
    if (path.node.name === 'debug') {
      debugger;
    }
  }
}
```

### 2. 日志点

```javascript
// 使用日志点输出信息
{
  ClassDeclaration(path) {
    // 在 VSCode 中设置日志点：
    // 类名：{path.node.id.name}
    // 父类：{path.node.superClass?.name}
  }
}
```

### 3. 调用栈分析

```javascript
// 在调试控制台中
> path.getFunctionParent()
> path.getStatementParent()
> path.findParent(p => p.isProgram())
```

## 四、性能分析

### 1. CPU 分析

```javascript
// 使用 --inspect-brk 启动
{
  "configurations": [
    {
      "type": "node",
      "request": "launch",
      "name": "Profile Transform",
      "program": "${workspaceFolder}/src/transform.js",
      "runtimeArgs": ["--inspect-brk"]
    }
  ]
}
```

### 2. 内存分析

```javascript
// 在代码中添加内存快照
const inspector = require("inspector");
const session = new inspector.Session();
session.connect();

session.post("HeapProfiler.takeHeapSnapshot", null, (err, result) => {
  // 分析堆内存
});
```

### 3. 执行时间分析

```javascript
// 使用 console.time
console.time("transform");
// 转换代码
console.timeEnd("transform");

// 或使用 Performance API
const { performance } = require("perf_hooks");
const start = performance.now();
// 转换代码
const end = performance.now();
console.log(`耗时: ${end - start}ms`);
```

## 五、远程调试

### 1. 远程连接

```json
{
  "configurations": [
    {
      "type": "node",
      "request": "attach",
      "name": "Attach to Remote",
      "address": "localhost",
      "port": 9229,
      "localRoot": "${workspaceFolder}",
      "remoteRoot": "/app"
    }
  ]
}
```

### 2. Docker 调试

```dockerfile
# Dockerfile
FROM node:14
WORKDIR /app
COPY . .
CMD ["node", "--inspect=0.0.0.0:9229", "src/index.js"]
```

### 3. WSL 调试

```json
{
  "configurations": [
    {
      "type": "node",
      "request": "attach",
      "name": "Attach to WSL",
      "address": "localhost",
      "port": 9229,
      "localRoot": "${workspaceFolder}",
      "remoteRoot": "/mnt/c/workspace"
    }
  ]
}
```

## 六、最佳实践

### 1. 调试配置管理

```javascript
// .vscode/launch.json
{
  "compounds": [
    {
      "name": "Full Debug",
      "configurations": [
        "Debug Transform",
        "Debug Tests"
      ]
    }
  ]
}
```

### 2. 调试工作流

1. 设置关键断点
2. 使用监视表达式
3. 分析调用栈
4. 检查变量状态
5. 单步调试代码

### 3. 常见问题解决

- 断点不生效
  - 检查 sourcemap 配置
  - 验证文件路径映射
- 变量信息不完整
  - 使用 console.dir
  - 展开对象属性
- 性能问题
  - 减少断点数量
  - 使用条件断点
  - 关注热点代码
