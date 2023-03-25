
/**
* replace_with_char - replacement
* @s: pointer to string
* @i: index of the string
* @c: character to replace with
*
* Description: replace the charaters at the index with c character
*
* Return: char *
*/
char *replace_with_char(char *s, int i, char c)
{
	char *new_s;
	int j, done = 0;

	new_s = malloc(sizeof(char) * (strlen(s) - 1));

	for (i = 0, j = 0; s[i] != '\0'; i++, j++)
	{
		if (s[i] == '%' && s[i + 1] == 'c' && !done)
		{
			new_s[j] = c;
			i = 1 + i;
			done = 1;
			continue;
		}

		new_s[j] = s[i];
	}

	new_s[j] = '\0';

	return (new_s);
}
