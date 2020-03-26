
```bash
http {

  fastcgi_cache_path /tmp/nginx_cache levels=1:2 keys_zone=microcache:10m max_size=500m;
  fastcgi_cache_key "$scheme$request_method$host$request_uri";
  
  # testing curl -I url
  # microcache-status: HIT | MISS | BYPASS
  add_header microcache-status $upstream_cache_status;


  # default cache for everythin
  set $no_cache 0;
  
  # Bypass cache for POST requests
  if ($request_method = POST) {set $no_cache 1;}
  
  # Bypass cache for URL with query string
  if ($query_string != "") {set $no_cache 1;}
  
  # Dont't cache the following URLs
  if ($request_uri ~* "/wp-admin") {set $no_cache 1;}

  server {
  
  
    location ~ \.php$ {
      include fastcgi_params;
      include fastcgi.conf;
    
    
      fastcgi_cache microcache;
      fastcgi_cache_valid 200 60m;
      
      fastcgi_cache_bypass $no_cache;
      fastcgi_no_cache $no_cache; 
    }
  }
}
```

# testing:  
1. whole testing , use ab
2. bypass testing

```bash
curl -I http://127.0.0.1/wp-admin
curl -I http://127.0.0.1?somevar=1
```
      

