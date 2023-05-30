#include "main.h"

/**
* print_char - outputs a char
* @types: total number of arguments in the function
* @buffer: a string that handles print
* @flags: calculates active flags
* @width: the width of the print
* @precision: precision specifier
* @size: size specifier
* Return: number of chars printed
*/

int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char p = va_arg(types, int);

	return (handle_write_char(p, buffer, flags, width, precision, size));
}

/**
* print_string - outputs a string
* @types: total number of arguments in the function
* @buffer: a string to handle print
* @flags: calculates active flags
* @width: get width
* @precision: precision specification
* @size: size specifier
* Return: number of strings to be printed
*/

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, sum;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "  ";
	}

	while (str[j] != '\0')
		j++;

	if (precision >= 0 && precision < j)
		j = precision;
	if (width > j)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], j);
			for (sum = width - length; sum > 0; sum--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (sum = width - length; sum > 0; sum--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
* print_percent - outputs a percent sign
* @types: total number of arguments
* @buffer: a string that handles print
* @flags: calculates active flags
* @width: get width of percent sign
* @precision: precision specifier
* @size: size specifier
* Return: number of chars printed
*/

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
* print_int - displays an integer
* @types: total number of arguments
* @buffer: a string the handles print
* @flags: calculates active flags
* @width: get width of an integer
* @precision: precision specifier
* @size: size specifier
* Return: number of chars printed
*/

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int g = BUFF_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(types, long int);
	unsigned long int sum;

	m = convert_size_number(m, size);
	if (m == 0)
		buffer[g--] = '\0';

	buffer[BUFF_SIZE - 1] = '\0';
	sum = (unsigned long int)m;
	if (m < 0)
	{
		sum = (unsigned long int)((-1) * m);
		is_negative = 1;
	}

	while (sum > 0)
	{
		buffer[g--] = (sum % 10) + '0';
		sum /= 10;
	}

	g++;

	return (write_number(is_negative, g, buffer, flags,
				width, precision, size));
}

/**
* print_binary - displays an unsigned number
* @types: total number of arguments
* @buffer: string that handles a print
* @flags: calculates an active flags
* @width: get width
* @precision: precision specifier
* @size: the size specifier
* Return: numbers of char printed
*/

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int h, f, c, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	h = va_arg(tpyes, unsigned int);
	f = 2147483648;
	a[0] = h / f;
	for (c = 1; c < 32; c++)
	{
		f / 2;
		a[c] = (h / f) % 2;
	}
	for (c = 0, sum = 0, count = 0; c < 32; c++)
	{
		sum += a[c];
		if (sum || c == 31)
		{
			char z = '0' + a[c];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
