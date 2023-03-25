#include "main.h"

/**
* replace_with_string - replacement
* @s: pointer to string
* @i: index of the string
* @str: string to replace with
*
* Description: replace the charaters at the index with str string
*
* Return: char *
*/
char *replace_with_string(char *s, int i, char *str)
{
	char *new_s;
	int j, k, done = 0;

	new_s = malloc(sizeof(char) * (strlen(s) - 1));

	for (i = 0, j = 0; s[i] != '\0'; i++, j++)
	{
		if (s[i] == '%' && s[i + 1] == 's' && !done)
		{
			for (k = 0; str[k] != '\0'; k++, j++)
			{
				new_s[j] = str[k];
			}
			i = 1 + i;
			j--;
			done = 1;
			continue;
		}

		new_s[j] = s[i];
	}

	new_s[j] = '\0';

	return (new_s);
}
