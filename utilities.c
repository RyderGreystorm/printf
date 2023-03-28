#include <stdio.h>

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
