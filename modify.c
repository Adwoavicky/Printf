#include "main.h"

/**
* print_char - displays a character
* @list: total number of arguments in the function
* Return: characters to be displayed
*/

int print_char(va_list list)
{
	char p = va_arg(list, int);

	_putchar(p);
	return (1);
}

/**
* print_string - displays a string
* @list: total number of arguments in the function
* Return: characters to be displayed
*/

int print_string(va_list list)
{
	char *str = va_arg(list, char *);
	int g = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '0')
	{
		_putchar(*str++);
		g++;
	}
	return (g);
}

/**
* print_percent - displays a percent sign
* @list: total number of arguments
* Return: characters to be diplayed
*/

int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
* print_integer - outputs an integer value
* @list: total numebr of arguments
* Return: integers to be displayed
*/

int print_integer(va_list list)
{
	int v = va_arg(list, int);
	int len = 0;

	if (v < 0)
	{
		_putchar('-');
		len++;
		v = -v;
	}
	len += print_unsigned_number(v);
	return (len);
}

/**
* unsigned_integer - displays an unsigned integer
* @list: the integer to be displayed
* Return: number of integers
*/

int unsigned_integer(va_list list)
{
	unsigned int add;

	add = va_arg(list, unsigned int);

	if (add == 0)
		return (print_unsigned_number(add));

	if (add < 1)
		return (-1);
	return (print_unsigned_number(add));
}
