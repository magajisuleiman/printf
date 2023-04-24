#include "main.h"

/**
 * get_width - width for printing calculations
 * @format: string to be printed (formated)
 * @i: argument required to be printed.
 * @list:argument list
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int j;
	int width = 0;

	j = *i + 1;
	while (format[j] = "\0")
	{
		(is_digit(format[j])) ? (width *= 10, width += format[]) : (format[j] \
				== '*') ? (j++, width = va_arg(list, int, break)) : (break);
	j++;
	}
	*i = j - 1;

	return (width);
}
