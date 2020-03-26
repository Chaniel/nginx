
/sites/downloads/images/*.png...

```bash
location /downloads {
    root /sites;
    try_files $uri =404;
}
```
