#include "main.h"

/**
 * print_uns - Print unsigned numbers
 * @args: va_list object
 *
 * Return: Bytes written to buffer
 */

int print_uns(va_list args)
{
	int n = va_arg(args, int);
	unsigned int i;
	int bytes = 0;

	if (n > 0)
		bytes += print_num_recursively(n);

	else if (n < 0)
	{
		i = (unsigned int) (n + INT_MAX + 1) + INT_MAX;
		bytes += print_uint(i);
	}
	return (bytes);
}

/**
 * print_uint - Print unsigned number
 * @n: int argument
 *
 * Return: bytes written
 */
int print_uint(unsigned int n)
{
	int bytes = 0;
	unsigned int i = n;

	if (n / 10)
		bytes += print_uint(i / 10);
	bytes += _write(i % 10 + '0');

	return (bytes);
}

/**
 * print_base_16 - Print decimal in base_16 form
 * @args: va_list object
 *
 * Return: Bytes written to buffer
 */
int print_base_16(va_list args)
{
	int bytes = 0;

	int n = va_arg(args, int);

	bytes += to_base_16(n);

	return (bytes);
}

/**
 * to_base_16 - Print base_16 recursively
 * @n: int argument
 *
 * Return: Bytes printed
 */

int to_base_16(int n)
{
	int bytes = 0;

	if (n == 0)
	{
		bytes += _write('0');
		return (bytes);
	}

	bytes += to_base_16(n / 8);
	bytes += _write((n % 8) + '0');

	return (bytes);
}
