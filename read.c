#include "shell.h"
#include <stdio.h>

/* الدالة لقراءة السطر المخصصة */
char *custom_read_line(void) {
char *custom_line = NULL;     /* السلسلة المستلمة */
size_t custom_buffer_size = 0;  /* حجم الذاكرة المخصصة */
ssize_t custom_length;          /* طول السطر المقروء */
custom_length = getline(&custom_line, &custom_buffer_size, stdin);
if (custom_length == -1) {
        /* إذا فشلت القراءة، قم بتحرير الذاكرة وارجاع قيمة فارغة */
free(custom_line);
return NULL;
    }

return custom_line;
} 
