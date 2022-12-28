#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
int _write(char);


/**
 * struct c_list - c list struct
 * @fmt: str arg
 * @func: pointer to func
 */
typedef struct c_list
{
	char *fmt;
	int (*func)(va_list args);
} c_l;

int print_char(va_list args);
int print_str(va_list args);
int print_perc(va_list args);
int print_num(va_list args);
int print_num_recursively(int n);
int print_bin(va_list args);
int to_binary(int n);
int print_uns(va_list args);
int print_uint(unsigned int n);

#endif /* MAIN_H */
