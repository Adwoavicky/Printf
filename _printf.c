#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: format to be printed
 * Return:the nimber of printed characters
 */

int _printf(const char *format, ...)
{
	int output_chars = 0;
	va_list arg_list;
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

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			output_chars += parser(&format, f_list, arg_list);
		}
		else
		{
			_putchar(*format);
			output_chars++;
		}
		format++;
	}
	va_end(arg_list);
	return (output_chars);
}
