### ES5、ES6 如何实现继承
继承是指子类型具备副类型的属性和行为，使代码得以复用，做到设计上的分离。js中的继承主要通过原型链和构造函数来实现。常见的继承方法有：ES6中的class继承、原型链继承、寄生组合式继承等。

```js
function Person() {}
        ↓
Person.prototype  ←——— 实例对象.__proto__
        ↓
Object.prototype
        ↓
       null
```
#### 原型链
原型链的本质是扩展型搜索机制。每一个实例对象都有一个私有属性__proto__。改属性执行它的构造函数的原型对象protptype。

#### 原型链继承
原型链继承的思想：一个引用类型继承另一个引用类型的属性和方法
```js
function SuperType() {
  this.b = [1, 2, 3];
}

function SubType() {}

SubType.prototype = new SuperType();
SubType.prototype.constructor = SubType;

var sub1 = new SubType();
var sub2 = new SubType();

// 这里对引用类型的数据进行操作
sub1.b.push(4);

console.log(sub1.b); // [1,2,3,4]
console.log(sub2.b); // [1,2,3,4]
console.log(sub1 instanceof SuperType); // true
```
优点：
1. 父类新增的原型方法/原型属性，子类都能访问到
2. 简单、易于实现
缺点：
1. 无法实现多继承
2. 由于原型中的引用值被共享，导致实力上的修改会直接影响到原型
3. 创建子类实例时，无法向父类构造函数穿参

#### 构造函数继承
构造函数继承的思想：*子类型构造函数中调用父类的构造函数，使所有需要继承的属性都定义在实例对象上*
```js
function SuperType(name){
    this.name = name
    this.b = [1,2,3]
}

SuperType.prototype.say = function(){
    console.log("LZW")
}

function SubType(name){
    SuperType.call(this,name);
}

var sub1 = new SubType();
var sub2 = new SubType();

// 传递参数
var sub3 = new SubType("lzw");

sub1.say(); // 使用构造函数继承并没有访问到原型链，say 方法不能调用

console.log(sub3.name); // lzw

sub1.b.push(4);

// 解决了原型链继承中子类实例共享父类引用属性的问题
console.log(sub1.b); // [1,2,3,4]
console.log(sub2.b); // [1,2,3]
console.log(sub1 instanceof SuperType); // false
```
优点：
1. 解决了原型链继承中子类实例共享父类引用属性的问题
2. 可以在子类型构造函数中向父类构造函数传递参数
3. 可以实现多继承 call多个父类对象

缺点：
1. 实例并不是父类的实例，只是子类的实例
2. 只能实现继承父类的实例属性和方法，无法继承原型属性和方法
3. 无法实现函数复用，每个子类都有父类实例函数的副本，影响性能


#### 组合继承
组合继承的思想：**使用原型链实现对原型属性和方法的继承，借用构造函数实现对实例属性的继承**
```js
function SuperType(name) {
  this.name = name;
  this.a = "HZFE";
  this.b = [1, 2, 3, 4];
}

SuperType.prototype.say = function () {
  console.log("HZFE");
};

function SubType(name) {
  SuperType.call(this, name); // 第二次调用 SuperType
}

SubType.prototype = new SuperType(); // 第一次调用 SuperType
SubType.prototype.constructor = SubType;
```
优点
1. 可以继承实例属性/方法，也可以继承原型属性/方法
2. 不存在引用属性共享问题
3. 可传参
4. 函数可以复用

缺点：调用了两次父类构造函数

#### 寄生组合式继承
**借用构造函数来继承属性，使用混合式原型链继承方法**
```js
// 在函数内部，第一步创建父类原型的一个副本，第二部是为创建的副本添加 constructor 属性，
// 从而弥补因重写而失去的默认的 constructor 属性。最后一步，将新创建的对象（即副本）赋值给予类型的原型。
function inheritPrototype(subType, superType) {
  var prototype = Object.create(superType.prototype); // 创建对象
  prototype.constructor = subType; // 增强对象
  subType.prototype = prototype; // 指定对象
}

function SuperType(name) {
  this.name = name;
}

SuperType.prototype.sayName = function () {
  console.log(this.name);
};

function SubType(name, num) {
  SuperType.call(this, name);
  this.num = num;
}

inheritPrototype(SubType, SuperType);

SubType.prototype.sayNum = function () {
  console.log(this.num);
};
```
优点：
1. 只调用了一次SuperType构造函数，避免了在SubType.prototype上创建不必要的属性
2. 能够正常使用instanceof和isPrototypeOf()

缺点：
1. 实现较为复杂

#### ES6中的class继承
 需要注意的是：class 关键字只是原型的语法糖， JavaScript 继承仍然是基于原型实现的。