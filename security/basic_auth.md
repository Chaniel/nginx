# for use htpasswd
```
yum install apache2-utils
```

htpasswd -c conf/.htpasswd user_name 

```bash
location ~ \.mp4$ {
  
  auth_basic "Restricted Content";
  auth_basic_user_file .htpasswd;
}
```
