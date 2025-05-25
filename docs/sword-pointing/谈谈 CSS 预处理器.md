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

#### csss 