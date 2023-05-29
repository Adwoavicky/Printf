#include "main.h"

/**
 * _putchar - prints out the character "c"
 * @c: the character to be printed
 * Return: 1 on sucess and -1 if otherwise
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
