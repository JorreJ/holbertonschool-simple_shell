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

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	int c = 0;

	while (s1[c] == s2[c])
	{
		if (s1[c] == '\0' || s2[c] == '\0')
		{
			break;
		}
		c++;
	}
	if (s1[c] == '\0' || s2[c] == '\0')
	{
		return (0);
	}
	else
	{
		return (s1[c] - s2[c]);
	}
}

void _env(char **env)
{
	int i;
	if (!env)
	{
		fprintf(stderr, "Error: Environment is empty or invalid.\n");
		return;
	}
	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s", env[i]);
		printf("\n");
	}
}