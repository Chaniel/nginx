#include <stdio.h>
#include <stdlib.h>


#define ngx_string(str)     { sizeof(str) - 1, (u_char *) str }
#define ngx_null_string     { 0, NULL }
#define ngx_str_set(str, text)                                               \
    (str)->len = sizeof(text) - 1; (str)->data = (u_char *) text
#define ngx_str_null(str)   (str)->len = 0; (str)->data = NULL





typedef struct {
    size_t      len;
    u_char     *data;
} ngx_str_t;

int main()
{
    ngx_str_t str = ngx_string("hello world");
    ngx_str_t str1 = ngx_null_string;    

    printf("%d\n", sizeof(size_t));
    printf("%d\n", sizeof(long unsigned int));
    printf("%d\n", sizeof(u_char));
    
}
