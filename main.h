#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _write(char);


typedef struct c_list 
{
	char *fmt;
	void (*func)(va_list args);
} c_l;
void print_char(va_list args);


#endif /* MAIN_H */
