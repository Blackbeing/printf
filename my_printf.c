#include "main.h"

/**
 * _printf - Print according to format specified
 * @format: string format
 *
 * Return: Number of bytes written
 */

int _printf(const char *format, ...)
{
	unsigned int fmt_counter = 0;
	va_list args;
	unsigned int ops_counter;
	unsigned int bytes = 0;

	c_l ops[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_perc},
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
				bytes += ops[ops_counter].func(args);
			ops_counter++;
		}
	}
	return (bytes);

}
