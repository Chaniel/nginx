```conf
# match only  /project
        location = /project {
            return 200 '/project';
        }
# match /project, /projectxxx
        location ~ /project {
            return 200 '/project';
        }
# match  /project[0-9] ,  /project[0-9]xxx
        location  /project[0-9] {
            return 200 '/project';
        }
# match /project123, /project/363...
        location ~ /project[0-9] {
            return 200 '/project';
        }
# match /apple, /applexxx,
        location ~ /apple {
            return 200 '/project';
        }
```