#include "main.h"

int main(void)
{
	_printf("c", 't');
	_write('\n');
	_printf("s", "This is a string");
	_write('\n');
	_printf("%", "Don't print this string");
	_write('\n');
	_printf("This is a str");
	_write('\n');
	return (0);
}
