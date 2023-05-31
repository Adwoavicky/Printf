#include "main.h"

/**
* print_unsigned - outputs an unsigned number
* @types: total number of arguments
* @buffer: a string to handle print
* @flags: calculates active flags
* @width: attain width of unsigned number
* @precision: precision specifier
* @size: size specifier
* Return: number of chars outputed
*/

int print_unsigned (va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int g = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[g--] = (num % 10) + '0';
		num /= 10;
	}
	g++;

	return (write_unsgnd(0, g, buffer, flags, width, precision, size));
}

/**
* print_octal - displays an unsigned number in octal base
* @types: the toal number of arguments passed
* @buffer: a string buffer that handles print
* @flags: calculates active flags in the function
* @width: attains width of number
* @precision: precision specifier
* @size: size specifier
* Return: number of char to be displayed
*/

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int g = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[g--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[g--] = '0';
	g++;

	return (write_unsgnd(0, g, buffer, flags, width, precision, size));
}

/**
* print_hexadecimal - displays an unsigned number in hexadecimal form
* @types: total number of arguments
* @buffer: a string that handles print
* @flags: calculates all active flags
* @width: attains width of the number
* @precision: precision specifier
* @size: size specifier
* Return: number of chars to be displayed
*/

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
* print_hexa_upper - outputs an unsigned number in upper hexadecimal form
* @types: total number of arguments
* @buffer: a string to handle print
* @flags: calculates all active flags in the function
* @width: gets width of number
* @precision: precision specifier
* @size: size specifier
* Return: number of chars to be outputed
*/

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
* print_hexa - displays a hexadecimal number in either upper or lowercase
* @types: total number of arguments
* @map_to: an array of values that maps the hexadecimal number
* @buffer: an array to handle print
* @flags: calculates all active flags
* @flag_ch: calculates active flags
* @width: takes width of the hexadecimal number
* @precision: precision specifier
* @size: size specifier
* Return: number of chars to be displayed
*/

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
