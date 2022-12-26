#include "main.h"

void _print_test(unsigned int n, ...);

void _print_test(unsigned int n, ...)
{
	va_list args;
	va_start(args, n);
	print_char(args);
}

int main(void)
{
	_print_test(1, 't');
	printf("\n");

	return (0);
}
