#include "main.h"

/**
 * set_flag - set flags
 * @format: format string
 * @i: pointer to integer
 *
 * Description: Set the flags as integers
 *
 * Return: int
 */
int set_flag(const char *format, int *i)
{
	const char f_char[] = "-+0# ";
	const int f_int[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	int j, k, flags = 0;

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		for (k = 0; f_char[k] != '\0'; k++)
		{
			if (f_char[k] == format[j])
			{
				flags |= f_int[k];
				break;
			}
		}

		if (f_char[k] == '\0')
			break;
	}

	*i = j - 1;

	return (flags);
}
