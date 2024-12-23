#include "shell.h"

/**
 * execute_command - Exécute une commande saisie par l'utilisateur
 * @line: La commande à exécuter
 */
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[2];

	pid = fork(); /* Crée un processus enfant */
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0) /* Dans le processus enfant */
	{
		argv[0] = line;
		argv[1] = NULL;

		if (execve(line, argv, NULL) == -1)
		{
			perror(line);
			exit(EXIT_FAILURE);
		}
	}
	else /* Dans le processus parent */
	{
		wait(&status);
		}
}
