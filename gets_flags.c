#include "main.h"

/**
* gets_flags - calculates all flags that are active
* @format: a string where arguments will be stored
* @i: parameter in the function
* Return: active flags
*/

int get_flags(const char *format, int *i)
{
	int j, rise;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH,
	F_SPACE, 0};

	for (rise = *i + 1; format[rise] != '\0'; rise++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[rise] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = rise - 1;

	return (flags);
}
