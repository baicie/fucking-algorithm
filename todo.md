## 参考项目pure-admin
项目地址：https://pure-admin.github.io/vue-pure-admin/#/login  
文档：    https://pure-admin.github.io/pure-admin-doc/  
github： https://github.com/pure-admin/vue-pure-admin  

## 环境准备
1.nodejs lts长时间支持版本 20.16.0 记得nvm切换到对应版本，对应命令`nvm install 20.16.0` `nvm use 20.16.0`
2.pnpm `npm i pnpm -g`
3.vite创建新项目 `pnpm create vite` 选择vue项目与typescript

- [ ] 基建任务  
  - [ ] 接入ui库 element-plus
    - [ ] 整体引入即可
  - [ ] 接入axios 
    - [ ] 设置超时时间
    - [ ] 返回拦截器处理统一报错
    - [ ] 请求拦截器设置token