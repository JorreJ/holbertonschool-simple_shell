#include "simple_shell.h"

int main(__attribute__((unused))int argc, char **argv)
{
	char *string, *command[2];
	size_t len;
	pid_t child;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("hsh$ "); /* display prompt */
		if (getline(&string, &len, stdin) == -1) /* read user's command and handle getline error */
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		string[strcspn(string, "\n")] = '\0'; /* remove "\n" character */
		command[0] = string;
		command[1] = NULL;
		child = fork(); /* create child process */
		if (child == -1) /* handle fork error */
		{
			perror("Fork error");
			break;
		}
		if (child == 0) /* child process */
		{
			if (execve(string, command, NULL) == -1) /* execute command and handle execve error */
			{
				printf("%s: 1: %s: not found\n", argv[0], command[0]);
				exit(1);
			}
		}
		else /* parent process */
		{
			wait(NULL);
		}
	}
	free(string); /* free allocated memory */
	return (0);
}
