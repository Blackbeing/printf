#include "main.h"

void _print_test(unsigned int n, ...);

void _print_test(unsigned int n, ...)
{
	va_list args;
	int bytes = 0;
	va_start(args, n);
	bytes = print_char(args);
	printf(" -> %d bytes\n", bytes);
}

int main(void)
{
	_print_test(1, 't');

	return (0);
}
