#include "shell.h"

/**
 * **strtow - splits a given string into words, ignoring repeat delimiters.
 * @str: the input string
 * @d: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **result;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	result = malloc((1 + numwords) * sizeof(char *));
	if (!result)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		result[j] = malloc((k + 1) * sizeof(char));
		if (!result[j])
		{
			for (k = 0; k < j; k++)
				free(result[k]);
			free(result);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			result[j][m] = str[i++];
		result[j][m] = 0;
	}
	result[j] = NULL;
	return (result);
}

/**
 * **strtow2 - splits a given string into words using a specified delimiter.
 * @str: the input string
 * @d: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int a, b, c, e, numwords = 0;
	char **result;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
				(str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	result = malloc((1 + numwords) * sizeof(char *));
	if (!result)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		c = 0;
		while (str[a + c] != d && str[a + c] && str[a + c] != d)
			c++;
		result[b] = malloc((c + 1) * sizeof(char));
		if (!result[b])
		{
			for (c = 0; c < b; c++)
				free(result[c]);
			free(result);
			return (NULL);
		}
		for (e = 0; e < c; e++)
			result[b][e] = str[a++];
		result[b][e] = 0;
	}
	result[b] = NULL;
	return (result);
}
