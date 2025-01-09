#include "simple_shell.h"

/**
 * exec_command - execute the command passed
 * @string: command to execute
 * @inter_name: name of the interpreter (used in error message)
 */

void exec_command(char *string, char *inter_name)
{
	pid_t child;
	char *command[2];
	int status;

	child = fork(); /* create child process */
	if (child == -1) /* handle fork error */
	{
		perror("fork fail");
	}
	else if (child == 0) /* child process */
	{
		command[0] = string;
		command[1] = NULL;
		if (execve(string, command, NULL) == -1) /* handle execve error */
		{
			fprintf(stderr, "%s: %s\n", inter_name, strerror(errno));
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
 *
 * Return: 0.
 */

int main(__attribute__((unused))int argc, char **argv)
{
	char *string = NULL;
	size_t len = 0;

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
		exec_command(string, argv[0]); /* execute the command passed */
	}
	free(string); /* free allocated memory */
	return (0);
}
