
```bash
yum install libgeoip-dev
--with-http_geoip_module
```

mkdir /etc/nginx/geoip

go to http://dev.maxmind.com, download geolite_country and geolite_city

```
ls
GeoIP.dat
GeoLiteCity.dat
```

```bash
http {
#Geo

geoip_country /etc/nginx/geoip/GeoIP.dat;
geoip_city /etc/nginx/geoip/GeoLiteCity.dat;

  server {
    location /geo_country {
      return 200 "Visiting from: $geoip_country_name";
    
    }
  
  }

}
```