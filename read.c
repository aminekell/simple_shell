#include "shell.h"
#include <stdio.h>
/**
 * custom_read_line - function for write a prompt
 *
 * Return: return custom_line or NULL
*/
char *custom_read_line(void)
{
	char *custom_line = NULL;
	size_t custom_buffer_size = 0;
	ssize_t custom_length;

<<<<<<< HEAD
	custom_length = getline(&custom_line, &custom_buffer_size, stdin);

	if (custom_length == -1)
	{
	free(custom_line);
	return (NULL);
	}
	return (custom_line);
}
=======
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
>>>>>>> 7422104b3c2678222a184b3d398576b4e9c3d3c9
