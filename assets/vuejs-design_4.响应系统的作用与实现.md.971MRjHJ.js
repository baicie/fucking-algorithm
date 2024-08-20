import{_ as e,c as a,o as t,a7 as _}from"./chunks/framework.Bgb21v0T.js";const u=JSON.parse('{"title":"响应系统的作用与实现","description":"","frontmatter":{},"headers":[],"relativePath":"vuejs-design/4.响应系统的作用与实现.md","filePath":"vuejs-design/4.响应系统的作用与实现.md","lastUpdated":1724153046000}'),o={name:"vuejs-design/4.响应系统的作用与实现.md"},r=_('<h1 id="响应系统的作用与实现" tabindex="-1">响应系统的作用与实现 <a class="header-anchor" href="#响应系统的作用与实现" aria-label="Permalink to &quot;响应系统的作用与实现&quot;">​</a></h1><h2 id="响应式数据与副作用函数" tabindex="-1">响应式数据与副作用函数 <a class="header-anchor" href="#响应式数据与副作用函数" aria-label="Permalink to &quot;响应式数据与副作用函数&quot;">​</a></h2><p>副作用函数指的是会产生副作用的函数<br> 我们希望当值变化后，副作用函数自动重新执行，如果能实现这个目标，那么对象 obj 就是响应式数据</p><h2 id="响应式数据的基本实现" tabindex="-1">响应式数据的基本实现 <a class="header-anchor" href="#响应式数据的基本实现" aria-label="Permalink to &quot;响应式数据的基本实现&quot;">​</a></h2><p>当读取字段时，可以把副作用函数 effect 存储到一个“桶”里 当设置 obj.text 时，再把副作用函数 effect 从“桶”里取出并执行即可</p>',5),s=[r];function n(i,c,d,l,h,p){return t(),a("div",null,s)}const m=e(o,[["render",n]]);export{u as __pageData,m as default};
