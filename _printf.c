#include "main.h"

/**
* write_chars - write characters
* @str: string
* @b_int: pointer to int
*
* Description: print characters stored up in the
* buffer
*
* Return: int
*/
void write_chars(char *str, int *b_int)
{
	if (*b_int > 0)
		write(1, &str[0], *b_int);
	*b_int = 0;
}

/**
* _printf - printing
* @format: string that may contain formatting identifiers
*
* Description: print format by replacing identifiers with the
* optional parameters
*
* Return: int
*/
int _printf(const char *format, ...)
{
	char str[B_SIZE];
	int i, len = 0, b_int = 0, char_printed = 0;
	int flags, width, precision, str_length;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			write_chars(str, &b_int);
			flags = set_flag(format, &i);
			width = set_width(ap, format, &i);
			precision = set_precision(ap, format, &i);
			str_length = set_str_length(format, &i);
			i++;
			char_printed = _print(
				format, str, ap, &i, flags,
				width, precision, str_length
			);
			if (char_printed == -1)
				return (-1);
			len += char_printed;
		}
		else
		{
			str[b_int] = format[i];
			b_int++;
			if (b_int ==  B_SIZE)
				write_chars(str, &b_int);
			len++;
		}
	}
	va_end(ap);
	write_chars(str, &b_int);
	return (len);
}
