#include "main.h"

/**
 * print_char - print char
 * @ap: va_list
 * @buffer: string buffer
 * @i: current index
 * @flags: flag specifiers
 * @width: width specifiers
 * @precision: precision specifiers
 * @str_length: length specifiers
 *
 * Description: print character passed as argument
 * and return number of characters printed
 *
 * Return: int
 */

int print_char(
	va_list ap, char buffer[], int *i, int flags,
	int width, int precision, int str_length
)
{
	char c, padding = ' ';
	int j, printed = 0;

	UNUSED(precision);
	UNUSED(i);
	UNUSED(str_length);

	c = va_arg(ap, int);
	buffer[0] = c;
	buffer[1] = '\0';

	if (width)
	{
		if (flags & F_ZERO)
			padding = '0';

		buffer[B_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buffer[B_SIZE - 2 - j] = padding;
		j--;
		if (flags & F_MINUS)
		{
			printed = write(1, &buffer[0] , 1);
			printed += write(1, &buffer[B_SIZE - 2 - j], width);
		}
		else
		{
			printed = write(1, &buffer[B_SIZE - 2 - j], width);
			printed += write(1, &buffer[0] , 1);
		}
	}
	else
	{
		printed = write(1, &buffer[0] , 1);
	}

	return (printed);
}
