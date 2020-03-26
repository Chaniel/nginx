# Remove Unused Modules
```
./configure --help | grep without
```
such as: autoindex

# Turn off Server Tokens
```bash
http {
server_tokens off;
}
```

# Set Buffer Sizes


# Block User Agents
```bash
if ($http_user_agent ~* badbot) {
  return 403;
}

if ($http_referer ~* badbot) {
  return 403;
}
```

# Configure  X-Frame-Options
```bash
add_hader X-Frame-Options SAMEORIGIN;
```
# modsecurity
modsecurity.org
