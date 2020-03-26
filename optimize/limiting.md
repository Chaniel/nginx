1. Concurrency
2. Frequency

```conf
http {
# limit concurrency
#limit_conn_zone $server_name zone=per_vhost:5m;
# limit_conn_zone $binary_remote_addr zone=per_ip:5m;
limit_req_zone $binary_remote_addr zone=one_per_sec:5m rate=1r/s;

   server {
        location ~* \.(css|js|jpg|png|gif)$ {
          access_log off;
          expires 1M;
          add_header Pragma public;
          add_header Cache-Control public;
          add_header Vary Accept-Encoding;
          
         # limit_conn per_ip 1;
          limit_req zone=one_per_sec burst=5;
        }
    }
}
```