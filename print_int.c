#include "main.h"

/**
 * print_int - print int
 *write_number - prints chars
 * @buffer: string buffer
 * @i: current index
 * @flags: flag specifiers
 * @width: width specifiers
 * @precision: precision specifiers
 * @is_negative: checks negative
 * Description: print integer and return the
 * number of digits printed
 *@size: size
 * Return: int
 */

int write_num(int i, char buffer[], int flags, int width, int precision, int length, char padding, char last_c);

int write_number(int is_negative, int i, char buffer[],
	int flags, int width, int precision, int size);

int print_int(
	va_list ap, char buffer[], int *i, int flags,
	int width, int precision, int str_length
)
{
	int check_negative = 0;
	long int a = va_arg(ap, long int);
	unsigned long int count;

	a = convert_size_number(a, str_length);

	if (a == 0)
		buffer[*i--] = '0';

	buffer[B_SIZE - 1] = '\0';
	count = (unsigned long int)a;

	if (a < 0)
	{
		count = (unsigned long int)((-1) * a);
		check_negative = 1;
	}
	while (count > 0)
	{
		buffer[*i--] = (count % 10) + '0';
		count /= 10;
	}

	i++;
	return (write_number(check_negative, *i, buffer, flags, width, precision, str_length));
	return (0);
}

/**
*write_number - prints string
*@j: index of number on buffer
*@buffer: buffer
*@flags: flags
*@width: width
*@size: size
*@precision: Precision specifier
*@is_negative: checkes negative
*Return: number of printed chars
*/
int write_number(int is_negative, int j, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = B_SIZE - j - 1;
	char padding = ' ', last_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (is_negative)
		last_ch = '-';
	else if (flags & F_PLUS)
		last_ch = '+';
	else if (flags & F_SPACE)
		last_ch = ' ';

	return (write_num(j, buffer, flags, width, precision,
		length, padding, last_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @i: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @length: Number length
 * @padding: Pading char
 * @last_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int i, char buffer[],
	int flags, int width, int precision,
	int length, char padding, char last_c)
{
	int j, start = 1;

	if (precision == 0 && i == B_SIZE - 2 && buffer[i] == '0' && width == 0)
		return (0);
	if (precision == 0 && i == B_SIZE - 2 && buffer[i] == '0')
		buffer[i] = padding = ' ';
	if (precision > 0 && precision < length)
		padding = ' ';
	while (precision > length)
		buffer[--i] = '0', length++;
	if (last_c != 0)
		length++;
	if (width > length)
	{
		for (j = 1; j < width - length + 1; j++)
			buffer[j] = padding;
		buffer[j] = '\0';
		if (flags & F_MINUS && padding == ' ')
		{
			if (last_c)
				buffer[--i] = last_c;
			return (write(1, &buffer[i], length) + write(1, &buffer[1], j - 1));
		}
		else if (!(flags & F_MINUS) && padding == ' ')
		{
			if (last_c)
				buffer[--start] = last_c;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[i], length));
		}
		else if (!(flags & F_MINUS) && padding == '0')
		{
			if (last_c)
				buffer[--start] = last_c;
			return (write(1, &buffer[start], j - start) +
				write(1, &buffer[i], length - (1 - start)));
		}
	}
	if (last_c)
		buffer[--i] = last_c;
	return (write(1, &buffer[i], length));
}
