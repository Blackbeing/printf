#include "main.h"

void _print_test(char *n, ...);

void _print_test(char *n, ...)
{
	va_list args;
	int bytes = 0;
	va_start(args, n);
	bytes = print_perc(args);
	printf(" -> %d bytes\n", bytes);
}

int main(void)
{
	_print_test("%", "should not print this");
	return (0);
}
