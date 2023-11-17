#include "shell.h"

/**
 * _strncpy - Copies a string.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The number of characters to be copied.
 * Return: A pointer to the concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 * _strncat - Concatenates two strings.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used.
 * Return: A pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 * Return: A pointer to the first occurrence of the character in the string.
 *         If the character is not found, returns NULL.
 */
char *_strchr(char *s, char c)
{
	do	{
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
