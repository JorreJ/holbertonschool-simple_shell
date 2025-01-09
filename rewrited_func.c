#include "simple_shell.h"

/**
 * _strlen - return the lenght of a string
 * @s: string to measure
 *
 * Return: lenght of the string
 */

int _strlen(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	int lend, lens, l, a;

	lend = _strlen(dest);
	lens = _strlen(src);
	l = lend;
	for (a = 0; a <= lens; a++)
	{
		dest[l] = src[a];
		l++;
	}
	dest[l] = '\0';
	return (dest);
}

/**
 * _strchr - locates a character in a string
 * @s: string to search
 * @c: char to find
 *
 * Return: pointer to the first occurence of the character c,
 * or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	while (*s++)
	{
		if (*s == c)
		{
			return (s);
		}
		if (!*s)
		{
			return (0);
		}
	}
	return (s);
}