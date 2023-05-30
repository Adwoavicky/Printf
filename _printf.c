#include "main.h"

void print_buffer(chr buffer[], int *buff_ind);

/**
* _printf - displays a function
* @format: format to be displayed
* Return: displayed chars
*/

int _printf(const char *format, ...)
{
	int k, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (b = 0; format && format[b] != '\0'; b++)
	{
		if (format[b] != '%')
		{
			buffer[buff_ind++] = format[b];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &b);
			width = get_width(format, &b, list);
			precision = get_precision(format, &b, list);
			size = get_size(format, &b);
			++b;
			printed = handle_print(format, &b, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
* print_buffer - displays the contents of an existing buffer
* @buffer: string to be displayed
* @buff_ind: index that represent length
*/

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
