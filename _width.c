#include "main.h"

/**
 * get_width - function calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int cur;
	int width = 0;

	cur = *i + 1;

	while (format[cur] != '\0')
	{
		if (is_digit(format[cur]))
		{
			width *= 10;
			width += format[cur] - '0';
		}
		else if (format[cur] == '*')
		{
			cur++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
		cur++;
	}

	*i = cur - 1;

	return (width);
}
