#include "main.h"

int _write(char c)
{
	return write(1, &c, sizeof(c));
}

void print_char(va_list args)
{
	_write(va_arg(args, int));
}
