#include "main.h"

/**
 * print_reversed - reverse a function and print a string
 * @arg: argument passed
 * Return: characters printed
 */

int print_reversed(va_list arg)
{
	int i;
	char *s;
	char *p;


	s = va_arg(arg, char *);
	if (s == NULL)
		return (-1);
	p = rev_string(s);
	if (p == NULL)
		return (-1);
	for (i = 0; p[i] != '\0'; i++)
		_putchar(p[i]);
	free(p);
	return (i);
}

/**
 * rot13 - converts string to rot13
 * @list: string to be converted
 * Return: conerted string
 */

int rot13(va_list list)
{
	int n;
	int num;
	char *s;

	char x[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NMPOQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(list, char *);

	if (s == NULL)
		return (-1);
	for (n = 0; s[n] != '\0'; n++)
	{
		for (num = 0; num <= 52; num++)
		{
			if (s[n] == x[num])
			{
				_putchar(u[num]);
				break;
			}
		}
		if (num == 53)
			_putchar(s[n]);
	}
	return (n);
}
