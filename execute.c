#include "shell.h"

/**
 * execute - Executes a command
 * @args: The array of arguments
 *
 * Return: 1 if successful, 0 otherwise
 */

int execute(char **args)
{
	pid_t pid;
	int status;
	char *cmd = find_command(args[0]);

	if (!cmd)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0) /* Processus enfant */
	{
		execve(cmd, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0) /* Processus parent */
	wait(&status);
	else
	perror("fork");

	free(cmd);
	return (1);
}
