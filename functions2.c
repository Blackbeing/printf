#include "main.h"

/**
 * print_num - Print number
 * @args: va_list object
 *
 * Return: Number of bytes written to buffer
 */
int print_num(va_list args)
{
	int bytes = 0;
	int n = va_arg(args, int);

	bytes += print_num_recursively(n);

	return (bytes);
}

/**
 * print_num_recursively - Print number recursively
 * @n: int argument
 *
 * Return: bytes written
 */

int print_num_recursively(int n)
{
	int bytes = 0;
	int i = n;

	if (n < 0)
	{
		bytes += _write('-');
		i = -i;
	}
	if (n / 10)
		bytes += print_num_recursively(i / 10);
	bytes += _write(i % 10 + '0');

	return (bytes);

}
