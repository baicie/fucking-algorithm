### BFC 的形成和作用

#### BFC 是什么

    bfc全称为block formatting context,中文为`块级格式化上下文`。是一个只有块级盒子参与的独立渲染区域，它规定了内部的会计盒子如何布局，且与区域外部无关

#### BFC 有什么用

- 需要费用浮动元素造成的高度塌陷的问题
- 避免非期望的外边距折叠
- 实现灵活健壮的自适应布局

#### 触发 BFC 的常见条件

html
浮动元素 float 取值为 left right
绝对定位 positon 为 absolute（相对于最近的已定位祖先元素）fixed
行内块于是怒 display inline-block
表格布局 display table table-cell table-caption
overflow 不为 visiable
弹性盒子容器 display flex inline-flex
网格布局容器 grid inline-grid
多列容器布局 column-count column-width

#### 常见的格式化上下文

块级格式化上下文 BFC
内联格式化上文 IFC
弹性格式化上下文 FFC
栅格格式化上下文 GFC
