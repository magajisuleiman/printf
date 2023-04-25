#include "main.h"

/**
 * is_printable - checks if a char is printable
 * @c: Character needed tobe evaluated
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	return ((c >= 32 && c < 127) ? (1) : (0));
	return (0);
}

/**
 * append_hexa_code - hexadecimal sode to buffer for ascii
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char maps_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code = ascii_code *  -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = maps_to[ascii_code / 16];
	buffer[i] = maps_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if the char is a digit
 * @c: Character needed to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	return ((c >= '0' && c <= '9') ? (1) : (0));

	return (0);
}

/**
 * convert_size_number - numbers cast to specific size
 * @num: casted number
 * @size: type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)(size == S_LONG)
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
