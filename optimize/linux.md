# Nginx Performance Optimization Configuration
## Linux OS Optimization
Optimize the restriction of system resources  
`ulimit –n `  
The maximum number of open file descriptors.  
`ulimit –u`   
The maximum number of processes available to a single user.  
vim /etc/security/limits.conf , add:
```vim
* soft nofile 1000000
* hard nofile 1000000
* soft nproc 1000000
* hard nproc 1000000
```
then reboot the system.
Optimization the disk write operation
close atime write:
open the fstab file:
`vi /etc/fstab`
at defaults add noatime and nodiratiome， just like：  
```vim
/dev/sdb1	/dataext3	defaults,noatime,nodiratime	0	0
```
then reboot the system, or use remount command to make it work:  
```bash
mount -o defaults,noatime,nodiratime -o remount /dev/sdb1 /sdb
mount -o defaults,noatime,nodiratime  /dev/sdb1 /sdb
```

Optimization TCP kernel option
vi /etc/sysctl.conf
```bash
########## add by admin###########
net.ipv4.tcp_syncookies = 1
net.ipv4.tcp_timestamps = 0
net.ipv4.tcp_synack_retries = 1
net.ipv4.tcp_syn_retries = 1
net.ipv4.tcp_fin_timeout = 1
net.ipv4.tcp_keepalive_time = 30

net.core.somaxconn = 262144
net.core.rmem_default = 262144
net.core.wmem_default = 262144
net.core.rmem_max = 16777216
net.core.wmem_max = 16777216
net.ipv4.tcp_rmem = 4096 4096 16777216
net.ipv4.tcp_wmem = 4096 4096 16777216
net.ipv4.tcp_mem = 786432 2097152 3145728
net.ipv4.tcp_max_syn_backlog = 262144
net.core.netdev_max_backlog = 262144
net.ipv4.tcp_max_syn_backlog = 16384
net.ipv4.tcp_tw_reuse = 1
net.ipv4.tcp_tw_recycle = 1
net.ipv4.tcp_max_orphans = 262144
net.ipv4.ip_local_port_range = 1024 65535
kernel.sem = 250 256000 100 1024
net.ipv4.tcp_max_tw_buckets = 600000
# add end#
```
then save the configuration use command : `sysctl -p`  

## Nginx configuration optimization
```nginx
use epoll
```
after linux 2.6 kernel can support this feature.

connection optimization 
```nginx
worker_connections 65535
keepalive_timeout 60
# use “getconf PAGESIZE” command to get the page size
client_header_buffer-size 8k
worker_rlimit_nofile 2000000
```
