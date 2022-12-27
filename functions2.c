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
	unsigned int i = n;

	if (n < 0)
	{
		bytes += _write('-');
		i *= -1;
	}
	if (n / 10)
		bytes += print_num_recursively(i / 10);
	bytes += _write(i % 10 + '0');

	return (bytes);
}

/**
 * print_bin - Print decimal in binary form
 * @args: va_list object
 *
 * Return: Bytes written to buffer
 */

int print_bin(va_list args)
{
	int n = va_arg(args, int);
	unsigned int i = n;
	int bytes = 0;

	bytes += to_binary(i);

	return (bytes);
}

/**
 * to_binary - Print binary recursively
 * @n: int argument
 *
 * Return: Bytes printed
 */

int to_binary(int n)
{
	int bytes = 0;
	unsigned int quot = 0, rem = 0;

	if (n == 0)
		return (0);

	quot = n / 2;
	rem = n % 2;
	bytes += to_binary(quot);
	bytes += _write(rem + '0');

	return (bytes);
}
