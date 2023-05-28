#include "main.h"

/**
 * _printf - function to replicate printf
 * @format: format to be printed
 * Return: Printed characters
 */

int _printf(const char *format, ...)
{
	int output_chars;
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
		{"x" print_hex},
		{"X", print_heX},
		{NULL, NULL}

	};

	va_list opt;

	if (format == NULL)
		return (-1);
	va_start(opt, format);
	output_chars = parser(format, f_list, opt);
	va_end(opt);

	return (output_chars);
}
