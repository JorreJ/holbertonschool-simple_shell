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

	command = parse_input(string); /* handle arguments */
	if (!command)
	{
		free(command);
		return;
	}
	command[0] = command_path(command[0], env); /* search path of the command */
	if (!command[0])
		return;
	child = fork(); /* create child process */
	if (child == -1) /* handle fork error */
		perror("fork");
	else if (child == 0) /* child process */
	{
		if (execve(command[0], command, env) == -1) /* handle execve error */
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
	/*int i = 0;*/
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
			free(string);
			exit(EXIT_SUCCESS);
		}
		if (string[_strlen(string) - 1] == '\n') /* remove "\n" character */
		{
			string[_strlen(string) - 1] = '\0';
		}
		if (strcmp("exit", string) == 0)
		{
			free(string);
			exit(EXIT_SUCCESS);
		}
		if (strcmp("env", string) == 0)
		{
			_env(env);
			continue;
		}
		exec_command(string, env); /* execute the command passed */
	}
	free(string); /* free allocated memory */
	return (0);
}
