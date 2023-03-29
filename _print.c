#include "main.h"

/**
 * _print - print
 * @format: format string
 * @buffer: string buffer
 * @ap: va_list
 * @i: formatter index
 * @flags: flag specifiers
 * @width: width specifier
 * @precision: precision specifier
 * @str_length: length specifier
 *
 * Description: printing based on the specifiers
 * and return the number of characters printed
 *
 * Return: int
 */
int _print(
	const char *format, char buffer[], va_list ap,
	int *i, int flags, int width, int precision,
	int str_length
)
{
	f_spec_t specs[] = {
		{'c', print_char}, {'b', print_bin},
		{'s', print_string},
		{'%', print_per},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL},
	};
	int k, u_len = 0;

	for (k = 0; specs[k].fn != NULL; k++)
	{
		if (specs[k].specifier == format[*i])
			return (specs[k].fn(ap, buffer, i, flags, width, precision, str_length));
	}

	if (format[*i] == '\0')
		return (-1);

	u_len = write(1, "%%", 1);
	if (format[*i - 1] == ' ')
	{
		u_len += write(1, " ", 1);
	}
	else if (width)
	{
		--(*i);
		while (format[*i] != ' ' && format[*i] != '%')
			--(*i);
		if (format[*i] == ' ')
			--(*i);
		return (1);
	}

	u_len += write(1, &format[*i], 1);
	return (u_len);
}
