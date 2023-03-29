#include "main.h"

/**
 * _strlen - string length
 * @s: array of chars
 *
 * Description: find the length of a string
 *
 * Return: int
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * is_digit - check for digit
 * @c: character
 *
 * Description: this checks whether or not a
 * character is a digit
 *
 * Return: returns 0 (Success)
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number -numbers converted to specified size
 * @num: Number params
 * @size: type being casted.
 *
 * Return: num
 */
long int convert_size_number(long int num, int size)
{
	if (size == LONG_LENGTH)
		return (num);
	else if (size == SHORT_LENGTH)
		return ((short)num);

	return ((int)num);
}
