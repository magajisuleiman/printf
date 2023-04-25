#include "main.h"

/**
 * get_flags - function calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */


int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, cur;
	int flaged = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur = *i + 1; format[cur] != '\0'; cur++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[cur] == FLAGS_CH[j])
			{
				flaged |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = cur - 1;

	return (flaged);
}
