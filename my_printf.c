#include "main.h"
#include "functions.c"

int _printf(const char *format, ...)
{
	unsigned int fmt_counter = 0;
	va_list args;
	unsigned int ops_counter;

	c_l ops[] = {
		{"c", print_char},
		{"s", print_char},
		{"%", print_char},
		{NULL, NULL},
	};

	va_start(args, format);

	for (fmt_counter = 0; format[fmt_counter] != '\0'; fmt_counter++)
	{
		ops_counter = 0;
		/* for (ops_counter = 0; ops_counter < 2; ops_counter++) */
		while (ops_counter < 3)
		{
			if (format[fmt_counter] == *ops[ops_counter].fmt)
				ops[ops_counter].func(args);
			ops_counter++;
		}
	}
	return (0);

}
int main(void)
{
	_printf("c", 'j');
	return (0);
}

