#include "main.h"

/**
 * set_precision - set flags
 * @ap: argument pointer
 * @format: format string
 * @i: pointer to integer
 *
 * Description: Set the flags as integers
 *
 * Return: int
 */
int set_precision(va_list ap, const char *format, int *i)
{
	int j = *i + 1, precision = -1;

	if (format[*i] != '.')
		return (precision);

	precision = 0;
	for (j = *i + 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			precision *= 10;
			precision = precision + (format[j] - '0');
		}
		else if (format[j] == '*')
		{
			precision = va_arg(ap, int);
			j++;
			break;
		}
		else
		{
			break;
		}
	}

	*i = j - 1;

	return (precision);
}
