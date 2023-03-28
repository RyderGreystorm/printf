#include "main.h"

/**
 * set_str_length - set length
 * @format: string formater
 * @i: format index
 *
 * Description: set the str_length based on the
 * the modifier
 *
 * Return: int
 */
int set_str_length(const char *format, int *i)
{
	int j = *i + 1, str_length = 0;

	if (format[j] == 'l')
	{
		str_length = LONG_LENGTH;
		*i = j;
	}
	else if (format[j] == 'h')
	{
		str_length = SHORT_LENGTH;
		*i = j;
	}

	return (str_length);
}
