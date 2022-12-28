#include "main.h"

/**
 * _printf - Print according to format specified
 * @format: string format
 *
 * Return: Number of bytes written
 */

int _printf(const char *format, ...)
{
	unsigned int fmt_counter = 0, ops_counter = 0, bytes = 0;
	va_list args;

	c_l ops[] = { {"c", print_char}, {"s", print_str}, {"%", print_perc},
		{"d", print_num}, {"i", print_num}, {"b", print_bin}, {"u", print_uns},
		{"o", print_base_16}, {NULL, NULL},
	};
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format && format[fmt_counter])
	{
		if (format[fmt_counter] == '%')
		{
			fmt_counter++;
			if (format[fmt_counter] == '\0')
				return (-1);
			ops_counter = 0;
			while (ops_counter < 9)
			{
				if (format[fmt_counter] == *(ops[ops_counter]).fmt)
				{
					bytes += ops[ops_counter].func(args);
					break;
				}
				ops_counter++;
			}
			if (ops_counter >= 9)
			{
				bytes += _write('%');
				bytes += _write(format[fmt_counter]);
			}
			fmt_counter++;
		}
		else
		{
			bytes += _write(format[fmt_counter]);
			fmt_counter++;
		}
	}
	va_end(args);
	return (bytes);
}
