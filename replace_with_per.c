#include "main.h"

/**
* replace_with_per - replacement
* @s: pointer to string
* @i: index of the string
*
* Description: replace the charaters at the index with %
*
* Return: char *
*/
char *replace_with_per(char *s, int i)
{
	char *new_s;
	int j, done = 0;

	new_s = malloc(sizeof(char) * (strlen(s) - 1));

	for (i = 0, j = 0; s[i] != '\0'; i++, j++)
	{
		if (s[i] == '%' && s[i + 1] == '%' && !done)
		{
			new_s[j] = '%';
			i = 1 + i;
			done = 1;
			continue;
		}

		new_s[j] = s[i];
	}

	new_s[j] = '\0';

	return (new_s);
}
