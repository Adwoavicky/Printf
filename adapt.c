#include "main.h"
#include <stdio.h>

int hex_check(int, char);

/**
* print_binary - change numbers in base 10 to binary
* @list: number of arguments passed
* Return: lenght of the changed numbers
*/

int print_binary(va_list list)
{
	unsigned int sum;
	int k, p;
	char *str;
	char *rev_str;

	sum = va_arg(lits, unsigned int);
	if (sum == 0)
		return (_putchar('0'));
	if (sum < 1)
		return (-1);
	p = base_len(sum, 2);
	str = malloc(sizeof(char) * p + 1);
	if (str == NULL)
		return (-1);

	for (k = 0; sum > 0; k++)
	{
		if (sum % 2 == 0)
			str[k] = '0';
		else
			str[k] = '1';
		sum = sum / 2;
	}
	str[k] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (p);
}

/**
* print_octal - changes a number to the base of octal
* @list: number of all arguments in the function
* Return: number of symbols changed
*/

int print_octal(va_list list)
{
	unsigned int sum;
	int u;
	char *octal;
	char *rev_str;

	sum = va_arg(list, unsigned int);

	if (sum == 0)
		return (_putchar('0'));
	if (sum < 1)
		return (-1);
	u = base_len(sum, 8);

	octal = malloc(sizeof(char) * u + 1);
	if (octal == NULL)
		return (-1);
	for (u = 0; sum > 0; u++)
	{
		octal[u] = (sum %  8) + 48;
		sum = sum / 8;
	}
	octal[u] = '\0';
	rev_str = rev_string(octal);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(octal);
	free(rev_str);
	return (u);
}

/**
* print_hex - displays a decimal number of base 18 in lowercase
* @list: total number of argumeents passed in the function
* Return: number of characters displayed
*/

int print_hex(va_list list)
{
	unsigned int sum;
	int p;
	int h;
	char *hex;
	char *rev_hex;

	su = va_arg(list, unsigned int);

	if (sum == 0)
		return (_putchar('0'));
	if (sum < 1)
		return (-1);
	p = base_len(sum, 16);
	hex = malloc(sizeof(char) * p + 1);
	if (hex == NULL)
		return (-1);
	for (p = 0; p > 0; p++)
	{
		h = sum % 16;
		if (h > 9)
		{
			h = hex_check(rem_num, 'x');
			hex[p] = h;
		}
		else
			hex[p] = h + 48;
		sum = sum / 16;
	}
	hex[p] = '\0';
	rev_hex = rev_string(hex);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex);
	free(rev_hex);
	return (p);
}

/**
* print_heX - displays a decimal number of base 16
* @list: total number of arguments in the function
* Return: number of characters displayed
*/

int print_heX(va_list list)
{
	unsigned int sum;
	int p;
	int h;
	char *hex;
	char *rev_hex;

	sum = va_arg(list, unsigned int);

	if (sum == 0)
		return (_putchar('0'));
	if (sum < 1)
		return (-1);
	p = base_len(sum, 16);
	hex = malloc(sizeof(char) * p + 1);
	if (hex == NULL)
		return (-1);
	for (p = 0; sum > 0; p++)
	{
		h = sum % 16;
		if (h > 9)
		{
			h = hex_check(h, 'X');
			hex[p] = h;
		}
	else
		hex[p] = h + 48;
	sum = sum / 16;
	}
	hex[p] = '\0';
	rev_hex = rev_string(hex);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex);
	free(rev_hex);
	return (p);
}

/**
* hex_check - assess which hex function is being called
* @num: numbers to be changed
* @x: identifies which hex function is being called
* Return: Ascii value
*/

int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (X == 'X')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
