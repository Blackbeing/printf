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

	if (i < 0)
	{
		bytes += _write('-');
		i *= -1;
	}
	if (i / 10)
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
	int i = n;
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
	int size = sizeof(n) * 8, b = 0, i = 0;
	int bytes = 0;
	int t = n;
	int one_flag = 0; /* flag, indicate if 1 has been encountered, */

	for (i = size - 1; i >= 0; i--)
	{
		/**
		 * 2's Complement representation
		 */

		if (n < 0)
		{
			b = (t >> i) & 1 ? 1 : 0;
			bytes += _write(b + '0');
		}
		else
		{
			b = (t >> i) & 1;
			if (t == 0)
			{
				bytes += _write('0');
				break;
			}

			if (b)
			{
				one_flag = 1;
				bytes += _write(b + '0');
			}
			else if (one_flag)
				bytes += _write(b + '0');
		}

	}
	return (bytes);
}

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
		bytes += print_num_recursively(i);
	}
	return (bytes);
}
