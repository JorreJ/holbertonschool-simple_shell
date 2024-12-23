#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROMPT "#vador$ "

/**
 * main - Entrée du programme du simple shell
 *
 * Description : Affiche un prompt, lit l'entrée de l'utilisateur
 * et quitte lorsque "exit" ou Ctrl+D est saisi.
 *
 * Return: 0 en cas de succès
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf(PROMPT); /* Affiche le prompt */
		nread = getline(&line, &len, stdin); /* Lit l'entrée utilisateur */

		if (nread == -1) /* Gestion de EOF (Ctrl+D) */
		{
			printf("\n");
			break;
		}

		/* Supprime le caractère de nouvelle ligne */
		line[strcspn(line, "\n")] = '\0';

		if (strcmp(line, "exit") == 0) /* Commande pour quitter */
			break;

		printf("Command entered: %s\n", line); /* Affiche la commande */
	}

	free(line); /* Libère la mémoire allouée */
	return (0);
}
