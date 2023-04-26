#include "main.h"

/**
 * handle_print - function that prints argument based on type
 * @fmt: string to be printed in formated manner
 * @list: argument list required to be printed
 * @ind: index
 * @buffer:array to handle in buffer
 * @flags: compute active flage
 * @width: with to be printed
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, unk_len = 0, printed_chars = -1;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	while (fmt_types[j].fmt != '\0')
	{
		if (fmt[*ind] == fmt_types[j].fmt)
			return (fmt_types[j].fn(list, buffer, flags, width, precision, size));
		j++;
	}

	if (fmt_types[j].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unk_len = unk_len +  write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unk_len = unk_len +  write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unk_len = unk_len +  write(1, &fmt[*ind], 1);
		return (unk_len);
	}
	return (printed_chars);
}
