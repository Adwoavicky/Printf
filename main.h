#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct convert - defines a structure for symbols and functions
 * @sym: the operator
 * @f: the function associated
 */

struct convert
{
	char *sym;
	int (*f)(va_list);
};

typedef struct convert conver_t;

int parser(const char *format, conver_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _putchar(char);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int rot13(va_list);
int print_reversed(va_list arg);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list);
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *str);
int print_unsigned_number(unsigned int);

#endif
