#include "shell.h"

/**
 * interactive - true if shell in int mode
 * @info: address of struxt
 *
 * Return: 1 if true else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if char is delim
 * @c: checks the charaster
 * @delim: the delim to bew checked
 * Return: 1 if true else return 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alpha char
 * @c: cahr to input
 * Return: 1 if true else return 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - conv a str to int
 * @s: the str to be changed
 * Return: 1 if true else return 0
 */

int _atoi(char *s)
{
	int cat, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (cat = 0; s[cat] != '\0' && flag != 2; cat++)
	{
		if (s[cat] == '-')
			sign *= -1;

		if (s[cat] >= '0' && s[cat] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[cat] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
