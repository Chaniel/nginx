```bash
location ~* \.(css|js|jpg|png|gif)$ {
  access_log off;
  expires 1M;
  add_header Pragma public;
  add_header Cache-Control public;
  add_header Vary Accept-Encoding;
}
```