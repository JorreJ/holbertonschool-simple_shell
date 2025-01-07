#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *string, *argv[2];
	size_t len = 0;
	pid_t child;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&string, &len, stdin) == -1)
		{
			perror("Getline error");
			break;
		}
		if (string[strlen(string) - 1] == '\n')
		{
			string[strlen(string) - 1] = '\0';
		}
		argv[0] = string;
		argv[1] = NULL;
		child = fork();
		if (child == 0)
		{
			if (execve(string, argv, NULL) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
		else if (child > 0)
			wait(NULL);
		else
		{
			perror("Fork error");
			break;
		}
	}
	free(string);
	return (0);
}
