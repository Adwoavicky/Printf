#include "main.h"

/**
 * get_size - calculates the size to cast the arguement
 * @format: formatted string in which to print the arguements
 * @i: list of arguments to be printed
 * Return: precision
 */

int get_size(const char *format, int *i)
{
	int ran = *i + 1;
	int size = 0;

	if (format[ran] == 'l')
		size = S_LONG;
	else if (format[ran] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = ran - 1;
	else
		*i = ran;

	return (size);
}
