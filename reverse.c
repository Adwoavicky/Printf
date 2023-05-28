#include "main.h"
#include <stdio.h>

/**
* rev_string - fuction that displays the reversed of a string
* @s: string to be reversed
* Return: pointer to a character
*/

char *rev_string(char *s)
{
	int head;
	int tail;
	char sow;
	char *reap;

	for (head = 0; s[head] != '\0'; head++)
	{}

	reap = malloc(sizeof(char) * head + 1);
	if (reap == NULL)
		return (NULL);

	_memcpy(reap, s, head);
	for (tail = 0; tail < head; tail++, head--)
	{
		sow = reap[head - 1];
		reap[head - 1] = reap[tail];
		reap[tail] = sow;
	}
	return (reap);
}

/**
* write_base - outputs a character to the stdout
* @str: string to parse
*/

void write_base(char *str)
{
	int l;

	for (l = 0; str[l] != '\0'; l++)
		_putchar(str[l]);
}

/**
* base_len - checks length of an octal number
*@num: number to be checked
* @base: number base to be checked
* Return: an integer which represents the length of a number
*/

unsigned int base_len(unsigned int num, int base)
{
	unsigned int s;

	for (s = 0; num > 0; s++)
	{
		num = num / base;
	}
	return (s);
}


/**
* _memcpy - copy memory area
* @dest: where memory area will be taken from
* @src: source to copy from
* @n: number of byte
* Return: a pointer to dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int p;

	for (p = 0; p < n; p++)
		dest[p] = src[p];
	dest[p] = '\0';
	return (dest);
}
