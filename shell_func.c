#include "simple_shell.h"

/**
 * parse_input - Splits the user input into arguments
 * @string: The input string
 *
 * Return: An array of arguments
 */

char **parse_input(char *string)
{
	char **args = NULL;
	char *token = NULL;
	size_t i = 0;

	args = malloc(sizeof(char *) * 64); /* allocate memory */
	if (!args) /* handle malloc error */
		return (NULL);

	token = strtok(string, " \t\n"); /* tokenize the string */
	while (token && i < 64)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	return (args);
}
