```bash
http {
  
  charset utf-8;
  sendfile on;
  tcp_nopush on;
  tcp_nodelay off;
  
  open_file_cache max=1000 inactive=20s;
  open_file_cache_valid 30s;
  open_file_cache_min_users 2;
  open_file_cache_errors on;
  
  
  include mime.types;
  
  server {
    listen 80;
    server_name ip;
    root /sites/wordpress;
    
    index index.php index.html;
    
    location / {
      try_files $uri $uri/ /index.php?$args;
    }
    
    # Pass all .php files onto a php-fpm/php-fcgi server.
    location ~ \.php$ {
      
      include fastcgi_params;
      include fastcgi.conf;
      
      fastcgi_pass 127.0.0.1:9000;
    }
  
  }
  
}
```