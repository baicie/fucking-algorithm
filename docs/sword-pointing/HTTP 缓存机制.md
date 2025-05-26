### HTTP 缓存机制
HTTP缓存主要分为强缓存和协商缓存

强缓存可以通过Expires/Cache-Control控制，命中强缓存时不会发起网络请求，资源直接本地获取，浏览器显示状态码200 form cache

协商缓存通过 Last-Modified / If-Modified-Since 和 Etag / If-None-Match控制开启协商缓存时向服务器发送请会带上缓存标识，若命中协商缓存服务器返回304Not Modified表示浏览器可以使用本地缓存文件，否则返回200OK正常返回数据

#### 强缓存
1. Expires
 - http1.0产物
 - 优先级低于Cache-Control：max-age
 - 缺点：使用本地时间判断是否过期，而本地时间是可修改茄饼粉一定准确

2. Cache-Control
 - http1.1产物
 - 优先级高于 Expires
 - 正确区分no-cache/no-store

max-age 缓存时间s做单位
no-store 不缓存
no-cache 需要协商缓存
public/private是否共享缓存

#### 协商缓存：发送请求带条件的，由服务器判断是否使用缓存（vite用到了）
原理：浏览器向服务器发送请求时，附带标识资源是否发生变化的信息，由服务器决定返回304或者200
关键的请求头和响应头
Last-Modified 响应头
If-Modufied-Since 请求头

ETag
If-not-match
如果返回304继续使用本地缓存

#### 缓存的优缺点
优点
 - 节省了不必要的数据传输，节省带宽
 - 减少服务端的负担，提高网站性能
 - 降低网络延迟，加快页面响应速度，增强用户体验

缺点
 - 不恰当的缓存设置可能会导致资源更新不及时，导致用户获取信息滞后
 