# 如何让后端服务，例如apache获取真实客户端IP，而不是nginx的ip
见： 《构建高可用Linux服务器》  于洪春 p173

# 向后端转发时的设置
```
proxy_set_header x-real-ip ```$remote_addr;
```
# 向客户端响应时的设置
```
proxy_add_header
```
