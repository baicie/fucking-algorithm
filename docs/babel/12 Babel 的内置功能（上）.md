# Babel 的内置功能（上）

## 一、语法转换

### 1. 箭头函数转换

```javascript
// 输入
const add = (a, b) => a + b;

// 输出
var add = function (a, b) {
  return a + b;
};
```

### 2. 解构赋值

```javascript
// 输入
const { name, age } = person;
const [first, ...rest] = array;

// 输出
var name = person.name,
  age = person.age;
var first = array[0],
  rest = array.slice(1);
```

### 3. 类转换

```javascript
// 输入
class Person {
  constructor(name) {
    this.name = name;
  }

  sayHello() {
    console.log(`Hello, ${this.name}!`);
  }
}

// 输出
function _classCallCheck(instance, Constructor) {
  /* ... */
}
function _defineProperties(target, props) {
  /* ... */
}

var Person = (function () {
  function Person(name) {
    _classCallCheck(this, Person);
    this.name = name;
  }

  _defineProperties(Person.prototype, [
    {
      key: "sayHello",
      value: function sayHello() {
        console.log("Hello, " + this.name + "!");
      },
    },
  ]);

  return Person;
})();
```

## 二、模块系统转换

### 1. ES Module 转 CommonJS

```javascript
// 输入
import { name } from "./module";
export const age = 18;

// 输出
("use strict");

Object.defineProperty(exports, "__esModule", {
  value: true,
});
exports.age = void 0;

var _module = require("./module");

var age = 18;
exports.age = age;
```

### 2. 动态导入

```javascript
// 输入
const module = import("./module");

// 输出
var module = Promise.resolve().then(function () {
  return require("./module");
});
```

### 3. 导出处理

```javascript
// 输入
export default function () {}
export const name = "babel";

// 输出
Object.defineProperty(exports, "__esModule", {
  value: true,
});
exports.default = function () {};
exports.name = "babel";
```

## 三、异步函数处理

### 1. async/await 转换

```javascript
// 输入
async function getData() {
  const result = await fetch("/api");
  return result.json();
}

// 输出
function asyncGeneratorStep(gen, resolve, reject, _next, _throw, key, arg) {
  // 辅助函数实现
}

function _asyncToGenerator(fn) {
  // 转换实现
}

function getData() {
  return _asyncToGenerator(function* () {
    var result = yield fetch("/api");
    return result.json();
  })();
}
```

### 2. Generator 函数

```javascript
// 输入
function* generator() {
  yield 1;
  yield 2;
}

// 输出
var _marked = regeneratorRuntime.mark(generator);

function generator() {
  return regeneratorRuntime.wrap(function generator$(_context) {
    while (1) {
      switch ((_context.prev = _context.next)) {
        case 0:
          _context.next = 2;
          return 1;
        case 2:
          _context.next = 4;
          return 2;
        case 4:
        case "end":
          return _context.stop();
      }
    }
  }, _marked);
}
```

## 四、新特性支持

### 1. 可选链操作符

```javascript
// 输入
const name = user?.profile?.name;

// 输出
var _user, _user$profile;
const name =
  (_user = user) === null || _user === void 0
    ? void 0
    : (_user$profile = _user.profile) === null || _user$profile === void 0
    ? void 0
    : _user$profile.name;
```

### 2. 空值合并运算符

```javascript
// 输入
const value = data ?? defaultValue;

// 输出
const value = data !== null && data !== void 0 ? data : defaultValue;
```

### 3. 私有类字段

```javascript
// 输入
class Counter {
  #count = 0;

  increment() {
    this.#count++;
  }
}

// 输出
function _classPrivateFieldGet(receiver, privateMap) {
  // 实现细节
}

function _classPrivateFieldSet(receiver, privateMap, value) {
  // 实现细节
}

var _count = new WeakMap();

class Counter {
  constructor() {
    _count.set(this, 0);
  }

  increment() {
    _classPrivateFieldSet(
      this,
      _count,
      _classPrivateFieldGet(this, _count) + 1
    );
  }
}
```

## 五、工具函数

### 1. 继承辅助

```javascript
function _inherits(subClass, superClass) {
  if (typeof superClass !== "function" && superClass !== null) {
    throw new TypeError("Super expression must either be null or a function");
  }
  subClass.prototype = Object.create(superClass && superClass.prototype, {
    constructor: {
      value: subClass,
      writable: true,
      configurable: true,
    },
  });
  if (superClass) _setPrototypeOf(subClass, superClass);
}
```

### 2. 装饰器支持

```javascript
function _decorate(decorators, target, key, desc) {
  var c = arguments.length;
  var r =
    c < 3
      ? target
      : desc === null
      ? (desc = Object.getOwnPropertyDescriptor(target, key))
      : desc;
  var d;

  if (typeof Reflect === "object" && typeof Reflect.decorate === "function") {
    r = Reflect.decorate(decorators, target, key, desc);
  } else {
    for (var i = decorators.length - 1; i >= 0; i--) {
      if ((d = decorators[i])) {
        r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
      }
    }
  }

  return c > 3 && r && Object.defineProperty(target, key, r), r;
}
```

### 3. 类型检查

```javascript
function _instanceof(left, right) {
  if (
    right != null &&
    typeof Symbol !== "undefined" &&
    right[Symbol.hasInstance]
  ) {
    return !!right[Symbol.hasInstance](left);
  } else {
    return left instanceof right;
  }
}
```
