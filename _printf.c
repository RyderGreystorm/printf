#include "main.h"

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
	char *str;
	int i, len = 0;
	va_list ap;

	if (format == NULL)
		return (-1);

	str = malloc(sizeof(char) * (strlen(format) + 1));
	strcpy(str, format);
	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			switch (format[i + 1])
			{
				case 'c':
					str = replace_with_char(str, i, va_arg(ap, int));
					break;
				case 's':
					str = replace_with_string(str, i, va_arg(ap, char *));
					break;
				case '%':
					str = replace_with_per(str, i);
					break;
				case 'd':
					str = replace_with_int(str, i, (int) va_arg(ap, int));
					break;
				case 'i':
					str = replace_with_int(str, i, (int) va_arg(ap, int));
					break;
				default:
					break;
			}
		}
	}

	va_end(ap);
	len = strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
