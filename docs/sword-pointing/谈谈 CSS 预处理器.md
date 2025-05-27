### 谈谈 CSS 预处理器

css本身不属于可编程语言。当前端项目逐渐庞大之后css的维护也愈发困难。css与处理器所做的本质上是为css增加一些可编程的特性，通过**变量、嵌套、简单的程序逻辑、计算】函数**等特性，通过工程化的手段让css更易维护，提升开发效率

#### postcss

postcss是目前最为流行的css预处理器。postcss会把css解析成AST，之后由其他的插件进行不同的处理
功能

- autoprefixer为css中的属性添加浏览器特定的前缀
- postcss-preset-env根据browserslist制定的目标浏览器将一些css的新特性转换为目标浏览器所支持的语法
- cssnano css压缩
- postcss-nested 提供css嵌套功能
- postcss-px-to-viewport 提供px转vw功能
- postcss-custom-properties 支持css的自定义属性

 优点

- 插件系统完善，扩展性强
- 配合插件功能齐全
- 生态优秀

#### sass

Sass 在完全兼容 CSS 语法的前提下，给 CSS 提供了变量、嵌套、混合、操作符、自定义函数等可编程能力。

优点

- 使用广泛。
- 功能支持完善。
- 可编程能力强。

 缺点

- css的复杂度不可控
- node-sass国内安装不易

#### less

Less 和 Sass 类似，完全兼容 CSS 语法，并给 CSS 提供了变量、嵌套、混合、运算等可编程能力。Less 通过 JavaScript 实现，可在浏览器端直接使用。

优点

- 使用广泛
- 可以在浏览器中运行，容易实现主题定制

缺点

- 不支持自定义函数
- 编程能力相对较弱

#### 扩展

1. css mudules
是给css文件加入了作用域和模块依赖，主要是为了解决css全局污染的痛点以及为了剞劂全局污染而嵌套过深的问题

2. CSS-in-js
css-injs是一种在js里写css的方式。利用js的优势可实现非常灵活的可扩展样式

3. Tailwind 和 Utility-first CSS
Tailwind CSS 是一个功能类优先的 CSS 框架，通过组合不同的类名实现页面设计。Tailwind 主要优势如下：

1. 不用考虑 class 的命名。
2. CSS 文件大小增长可控，通过 purge 可生成非常小的 CSS 文件。
3. 统一设计系统下的样式与布局。
4.

IDE 集成优秀。
