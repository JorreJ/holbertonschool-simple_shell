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
