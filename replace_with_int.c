#include "main.h"

/**
*tostring - converst and int to string
*@str: string params
*@num: number to to converted
*Return: char pointer
*/

char *replace_with_int(char *s, int i, int num);
char *replace_with_num_string(char *s, int i, char *str);

char *tostring(char *str, int num)
{
	int i, rem, len = 0, n, isN = 0;

	if (num < 0)
	{
		isN = 1;
		num *= -1;
	}

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	str = (char *) malloc(sizeof(char) * (len + 1));
	for (i = 0; i < len; i++)
	{
		if (isN && (len - (i + 1)) == 0)
		{
			str[0] = '-';
			continue;
		}
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	return (str);
}


/**
* replace_with_int - replaces an int specifier with an int
*@s: string params
*@i: index of num
*@num: number being sent into string
*Return: char pointer
*/


char *replace_with_int(char *s, int i, int num)
{
	char *str = NULL;

	str = tostring(str, num);
	str = replace_with_num_string(s, i, str);
	return (str);
}

/**
*replace_with_num_string - replaces num in string
*@s: string params
*@i: index at with num goes
*@str: new string params
*Return: char pointer
*/

char *replace_with_num_string(char *s, int i, char *str)
{
	char *new_s;
	int j, k, done = 0;

	if (str == NULL)
	{
		str = "(null)";
	}
	else
	{
		k = (int) str[0];
		if (k < 0 || k > 127)
			str = "(null)";
	}

	new_s = malloc(sizeof(char) * (strlen(s) + strlen(str) - 1));

	for (i = 0, j = 0; s[i] != '\0'; i++, j++)
	{
		if (s[i] == '%' && (s[i + 1] == 'd' || s[i + 1] == 'i') && !done)
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
	strcpy(s, new_s);
	free(new_s);

	return (s);
}
