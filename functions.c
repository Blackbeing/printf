#include "main.h"

/**
 * _write - Print char to stdout
 * @c: char to print
 * Return: Number of bytes written to buffer
 */

int _write(char c)
{
	return (write(1, &c, sizeof(c)));
}

/**
 * print_char - Print character
 * @args: va_list object
 *
 * Return: Number of bytes written to buffer
 */

int print_char(va_list args)
{
	return (_write(va_arg(args, int)));
}

/**
 * print_str - Print string
 * @args: va_list object
 *
 * Return: Number of bytes written to buffer
 */

int print_str(va_list args)
{
	int i;
	int bytes;
	char *str = va_arg(args, char *);

	bytes = 0;
	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			bytes += _write(str[i]);
			i++;
		}
	}
	return (bytes);
}

/**
 * print_perc - Print percent
 * @args: va_list object
 *
 * Return: Number of bytes written to buffer
 */

int print_perc(va_list args)
{
	(void)(args);
	return (_write('%'));
}
