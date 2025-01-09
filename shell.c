#include "simple_shell.h"

/**
 * read_prompt - read user's command
 *
 * Return: string of the user's command
 */

/*char *read_prompt(void)
{
	char *string = NULL;
	size_t len;

	printf("hsh$ ");
	if (getline(&string, &len, stdin) == -1)
	{
		if (isatty(STDIN_FILENO))
			printf("\n");
		return (NULL);
	}
	if (string[_strlen(string) - 1] == '\n')
	{
		string[_strlen(string) - 1] = '\0';
	}
	return (string);
}*/

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
			fprintf(stderr, "%s: %s: %s\n", inter_name, string, strerror(errno));
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
		exec_command(string, argv[0]);
	}
	free(string); /* free allocated memory */
	return (0);
}

/*


	char *string, *command[2];
	size_t len;
	pid_t child;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("hsh$ ");
		if (getline(&string, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		if (string[_strlen(string) - 1] == '\n') 
		{
			string[_strlen(string) - 1] = '\0';
		}
		command[0] = string;
		command[1] = NULL;
		child = fork(); 
		if (child == -1) 
		{
			printf("%s: 1: %s: not found", argv[0], command[0]);
			break;
		}
		if (child == 0) 
		{
			if (execve(string, command, NULL) == -1) 
			{
				printf("%s: 1: %s: not found\n", argv[0], command[0]);
				exit(1);
			}
		}
		else 
		{
			wait(NULL);
		}
	}
	free(string); 
	return (0);
}
*/
