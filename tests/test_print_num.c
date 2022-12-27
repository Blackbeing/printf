#include "main.h"

void _print_test(int n, ...);

void _print_test(int n, ...)
{
	va_list args;
	/* int bytes = 0; */
	va_start(args, n);
	print_num(args);
}

int main(void)
{
	_print_test(1, 1024);

	return (0);
}
