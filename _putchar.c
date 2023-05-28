#include "main.h"

/**
 * putchar - prints out the character c
 * @c: the character to be printed
 * Return: 1 on sucess and -1 if otherwise
 */

int putchar(char)
{
	return (write(1, &c, 1));
}
