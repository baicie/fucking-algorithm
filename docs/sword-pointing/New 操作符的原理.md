### New 操作符的原理
 
#### new操作符做了什么
1. 在内存中创建一个新对象
2. 将对象内部的__proto__赋值为构造函数的prototype属性
3. 将构造函数内部的this指向新对象
4. 指向构造函数内部的代码 给新对象添加属性
5. 如果构造函数返回非空对象则返回该对象，否则返回this

#### new操作符的模拟实现
```js
function myNew(Constructor,...args){
    const obj = Object.create(Constructor.prototype);
    const result = Constructor.apply(obj,args);

    return (result && typeof result === 'object') ? result : obj;
}
```

