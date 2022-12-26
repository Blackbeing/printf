#include "main.h"

void _print_test(char *n, ...);

void _print_test(char *n, ...)
{
	va_list args;
	va_start(args, n);
	print_str(args);
}

int main(void)
{
	_print_test("m", "testing");
	printf("\n");

	return (0);
}
