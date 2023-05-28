#include "main.h"

/**
 * parser - print s formated string after receiving main string
 * and all necessary parametes
 * @format: string containing all the desired characters
 * @f_list: list of all the possible functions.
 * @arg_list: list containing all the arguemets
 * Return: total count of the characters printed
 */

int parser(const char *format, conver_t f_list[], va_list arg_list)
{
	int a, b, c, output opt;


	output opt = 0;

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] == '%')
		{
			for (b = 0; f_list[b].sym != NULL; b++)
			{
				if (forma[i + 1] == f_list[b].sym[0])
				{
					c = f_list[b].f(arg_list);
					if (c == -1)
						return (-1);
					output opt += c;
					break;
				}
			}
			if (f_list[b].sym == NULL && format[a + 1] != ' ')
			{
				if (format[a + 1] != '\0')
				{
					_putchar(format[a]);
					_putchar(format[a + 1]);
					output opt = output opt + 2;
				}
				else
					return (-1);
			}
			a = a + 1;
		}
		else
		{
			_putchar(format[a]);
			output opt++;
		}
	}
	return (output opt);
}
