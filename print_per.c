#include "main.h"

/**
 * print_per - print char
 * @ap: va_list
 * @buffer: string buffer
 * @i: current index
 * @flags: flag specifiers
 * @width: width specifiers
 * @precision: precision specifiers
 * @str_length: length specifiers
 *
 * Description: print a percentage sign
 *
 * Return: int
 */

int print_per(
	va_list ap, char buffer[], int *i, int flags,
	int width, int precision, int str_length
)
{
	UNUSED(precision);
	UNUSED(str_length);
	UNUSED(buffer);
	UNUSED(ap);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(i);

	return (write(1, "%", 1));
}
