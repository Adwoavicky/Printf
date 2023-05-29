#include "main.h"

/**
 * print_number - print a number
 * @args: arguements variable
 * Return: number of arguments printed
 */

int print_number(va_list args)
{
	int i;
	int j;
	int s;
	unsigned int n;

	i = va_arg(args, int);
	j = 1;
	s = 0;

	if (i < 0)
	{
		s += _putchar('-');
		n = i * -1;
	}
	else
		n = i;

	for (; n / j > 9;)
		j *= 10;
	for (; j != 0;)
	{
		s += _putchar('0' + n / j);
		n %= j;
		j /= 10;
	}

	return (s);
}

/**
 * print_unsigned_number - prints unsigned number
 * @n: the integer variable
 * Return: amount of numbers printed
 */

int print_unsigned_number(unsigned int n)
{
	int j;
	int s;
	unsigned int a;


	j = 1;
	s = 0;

	a = n;

	for (; a / j > 9; )
		j *= 10;

	for (; j != 0; )
	{
		j += _putchar('0' + a / j);
		a %= j;
		j /= 10;
	}

	return (s);
}
