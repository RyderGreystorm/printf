#include "main.h"

/**
 * print_bin - print char
 * @ap: va_list
 * @buffer: string buffer
 * @i: current index
 * @flags: flag specifiers
 * @width: width specifiers
 * @precision: precision specifiers
 * @str_length: length specifiers
 *
 * Description: print a number in its binary form
 *
 * Return: int
 */
int print_bin(
	va_list ap, char buffer[], int *i, int flags,
	int width, int precision, int str_length
)
{
	int num, j = B_SIZE - 2;

	UNUSED(width);
	UNUSED(i);
	UNUSED(str_length);
	UNUSED(flags);
	UNUSED(precision);

	num = va_arg(ap, int);

	buffer[B_SIZE - 1] = '\0';
	while (num != 0)
	{
		buffer[j--] = (num % 2) + '0';
		num /= 2;
	}
	j++;

	return (write(1, &buffer[j], B_SIZE - 1 - j));
}
