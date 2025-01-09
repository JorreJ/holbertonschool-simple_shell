#include "shell.h"

#define PROMPT "#vador$ "

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *input = NULL;
	char **args = NULL;
	int status = 1;

	while (status)
	{
		prompt();
		input = read_input();
		if (!input)
		break;

		args = parse_input(input);
		if (!args || !args[0])
		{
			free(input);
			free_args(args);
			continue;
		}

		if (handle_builtin(args) == 0)
		{
			free(input);
			free_args(args);
			continue;
		}

		status = execute(args);

		free(input);
		free_args(args);
	}
	return (0);
}
