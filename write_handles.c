#include "main.h"

/**
 * handles_write_char - prints a string
 * @c: char types
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars printed
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

		if (flags & F_ZERO)
			padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) + 
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - outputs a string
 * @is_negative: amount of arguments
 * @ind: char types
 * @buffer: an array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars printed
 */

int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', sub = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		sub = '-';
	else if (flags & F_PLUS)
		sub = '+';
	else if (flags & F_SPACE)
		sub = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, sub));
}

/**
 * write_num - prints a number using a buffer
 * @ind: the starting point of a number on the buffer
 * @buffer: buffer to be used
 * @flags: flags
 * @width: width
 * @prec: precision specifier
 * @length: number length
 * @padd: pading char
 * @more: extra char
 * Return: number of printed chars
 */
int write_num(int ind, char buffer[], int flags,
		int width, int prec, int length, char padd,
		char more)
{
	int s, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (more != 0)
		length++;
	if (width > length)
	{
		for (s = 1; s < width - length + 1; s++)
			buffer[s] = padd;
		buffer[s] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (more)
				buffer[--ind] = more;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], s - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (more)
				buffer[--ind] = more;
			return (write(1, &buffer[1], s - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (more)
				buffer[--padd_start] = more;
			return (write(1, &buffer[padd_start], s - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (more)
		buffer[--ind] = more;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - outputs an unsigned number
 * @is_negative: number which indicates if the num is negative
 * @ind: initial start off point of the number in the buffer
 * @buffer: array of chars
 * @flags: flags specifiers
 * @width: width specifiers
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of written chars.
 */

int write_unsgnd(int is_negative, int ind, 
		char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - prints a memory address
 * @buffer: arrays of chars
 * @ind: initial start off point of the number in the buffer
 * @length: length of number
 * @width: width specifier
 * @flags: flags specifier
 * @padd: char representing the padding
 * @more: char representing extra char
 * @padd_start: index at which padding should start
 * Return: number of written chars
 */

int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char more, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (more)
				buffer[--ind] = more;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (more)
				buffer[--ind] = more;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));

		else if (!(flags & F_MINUS) && padd == '0'
		}
			else if (!(flags & F_MINUS) && padd == '0')
			{
				if (more)
					buffer[--padd_start] = more;
				buffer[1] = '0';
				buffer[2] = 'x';
				return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
			}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (more)
		buffer[--ind] = more;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
