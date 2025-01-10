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
	char *path;
	int status;

	command = parse_input(string); /* handle arguments */
	if (!command || !command[0])
	{
		free(command);
		return;
	}
	if (strcmp(command[0], "exit") == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	path = command_path(command[0], env); /* search path of the command */
	if (!path)
	{
		fprintf(stderr, "Commande not found: %s\n", command[0]);
		free(command);
		return;
	}
	child = fork(); /* create child process */
	if (child == -1) /* handle fork error */
	{
		perror("fork");
		free(command);
		free(path);
		return;
	}
	else if (child == 0) /* child process */
	{
		if (execve(path, command, env) == -1) /* handle execve error */
		{
			perror("execve");
			free(command);
			free(path);
			exit(EXIT_FAILURE);
		}
	}
	else /* parent process */
		wait(&status);
	free(command);
	free(path);
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
	ssize_t string_size;
	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("hsh$ "); /* display prompt */
		string_size = getline(&string, &len, stdin);
		if (string_size == -1) /* handle end of file */
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(string);
			exit(EXIT_SUCCESS);
		}
		if (string[string_size - 1] == '\n') /* remove "\n" character */
			string[string_size - 1] = '\0';
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
		if (strncmp("which", string, 5) == 0)
		{
			char *command = string + 6; /* Skip "which " (5 char + space) */
			char *path = command_path(command, env);
			if (path)
			{
				printf("%s\n", path);
				free(path);
			}
			else
			{
				fprintf(stderr, "Command not found: %s\n", command);
			}
			continue;
		}
		exec_command(string, env); /* execute the command passed */
	}
	free(string); /* free allocated memory */
	exit (0);
}
