#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: format to be printed
 * Return:the nimber of printed characters
 */

int _printf(const char *format, ...)
{
	int n  = 0;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"u", unsigned_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}

	};

	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	n = parser(format, f_list, arg_list);

	va_end(arg_list);
	return (n);
}
