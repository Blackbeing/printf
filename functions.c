#include "main.h"

int _write(char c)
{
	return write(1, &c, sizeof(c));
}

void print_char(va_list args)
{
	_write(va_arg(args, int));
}

void print_str(va_list args)
{
	int i;
	char *str = va_arg(args, char *);

	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			_write(str[i]);
			i++;
		}
	}
}
void print_perc(va_list args)
{
	_write('%');
}
