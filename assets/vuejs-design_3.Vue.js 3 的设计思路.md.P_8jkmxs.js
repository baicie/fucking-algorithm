import{_ as a,c as i,o as l,a7 as r}from"./chunks/framework.Ed-g3oaB.js";const p=JSON.parse('{"title":"Vue.js 3 的设计思路","description":"","frontmatter":{},"headers":[],"relativePath":"vuejs-design/3.Vue.js 3 的设计思路.md","filePath":"vuejs-design/3.Vue.js 3 的设计思路.md","lastUpdated":1740366238000}'),t={name:"vuejs-design/3.Vue.js 3 的设计思路.md"};function s(o,e,n,d,u,c){return l(),i("div",null,e[0]||(e[0]=[r('<h1 id="vue-js-3-的设计思路" tabindex="-1">Vue.js 3 的设计思路 <a class="header-anchor" href="#vue-js-3-的设计思路" aria-label="Permalink to &quot;Vue.js 3 的设计思路&quot;">​</a></h1><h2 id="声明式地描述-ui" tabindex="-1">声明式地描述 UI <a class="header-anchor" href="#声明式地描述-ui" aria-label="Permalink to &quot;声明式地描述 UI&quot;">​</a></h2><ul><li>DOM 元素：例如是 div 标签还是 a 标签。</li><li>属性：如 a 标签的 href 属性，再如 id、class 等通用属性。</li><li>事件：如 click、keydown 等。</li><li>元素的层级结构：DOM 树的层级结构，既有子节点，又有父节点。</li></ul><p>使用 JavaScript 对象来描述 UI 的方式，其实就是所谓的虚拟 DOM</p><h2 id="初识渲染器" tabindex="-1">初识渲染器 <a class="header-anchor" href="#初识渲染器" aria-label="Permalink to &quot;初识渲染器&quot;">​</a></h2><p>渲染器的实现思路</p><ul><li>创建元素：把 vnode.tag 作为标签名称来创建 DOM 元素。</li><li>为元素添加属性和事件：遍历 vnode.props 对象，如果 key 以 on 字符开头，说明它是一个事件，把字符 on 截取掉后再调用 toLowerCase 函数将事件名称小写化，最终得到合法的事件名称，例如 onClick 会变成 click，最后调用 addEventListener 绑定事件处理函数。</li><li>处理 children：如果 children 是一个数组，就递归地调用 renderer 继续渲染，注意，此时我们要把刚刚创建的元素作为挂载点（父节点）；如果 children 是字符串，则使用 createTextNode 函数创建一个文本节点，并将其添加到新创建的元素内。</li></ul><h2 id="组件的本质" tabindex="-1">组件的本质 <a class="header-anchor" href="#组件的本质" aria-label="Permalink to &quot;组件的本质&quot;">​</a></h2><p>组件就是一组 DOM 元素的封装</p><ul><li>函数式</li><li>对象式</li></ul><h2 id="模板的工作原理" tabindex="-1">模板的工作原理 <a class="header-anchor" href="#模板的工作原理" aria-label="Permalink to &quot;模板的工作原理&quot;">​</a></h2><p>编译器的作用其实就是将模板编译为渲染函数</p><h2 id="vue-js-是各个模块组成的有机整体" tabindex="-1">Vue.js 是各个模块组成的有机整体 <a class="header-anchor" href="#vue-js-是各个模块组成的有机整体" aria-label="Permalink to &quot;Vue.js 是各个模块组成的有机整体&quot;">​</a></h2><p>组件的实现依赖于渲染器，模板的编译依赖于编译器 编译节点能够标注那些是会变化的</p>',14)]))}const _=a(t,[["render",s]]);export{p as __pageData,_ as default};
