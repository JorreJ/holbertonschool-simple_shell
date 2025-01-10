#include "simple_shell.h"

/**
 * exec_command - execute the command passed
 * @string: command to execute
 * @env: environment variable passed from main
 */

void exec_command(char *string, char **env)
{
	pid_t child;
	char **command;
	int status;

	child = fork(); /* create child process */
	if (child == -1) /* handle fork error */
		perror("fork");
	else if (child == 0) /* child process */
	{
		command = parse_input(string); /* handle arguments */
		if (!command)
		{
			free(command);
			return;
		}
		if (execve(string, command, env) == -1) /* handle execve error */
		{
			perror("execve");
			free(command);
			exit(1);
		}
	}
	else /* parent process */
	{
		wait(&status);
	}
}

/**
 * main - Entry point
 * @argc: argument count (unused)
 * @argv: argument value
 * @env: environment variable
 *
 * Return: 0.
 */

int main(int argc, char **argv, char **env)
{
	char *string = NULL;
	size_t len = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("hsh$ "); /* display prompt */
		if (getline(&string, &len, stdin) == -1) /* handle getline error */
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		if (string[_strlen(string) - 1] == '\n') /* remove "\n" character */
		{
			string[_strlen(string) - 1] = '\0';
		}
		if (strcmp("exit", string) == 0)
			break;
		string = command_path(string, env); /* search the path of the command */
		if (!string)
			continue;
		exec_command(string, env); /* execute the command passed */
	}
	free(string); /* free allocated memory */
	return (0);
}
