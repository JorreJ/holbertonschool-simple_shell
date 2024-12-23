#include "shell.h"

/**
 * read_prompt - Affiche le prompt et lit l'entrée de l'utilisateur
 *
 * Return: Une chaîne de caractères contenant la commande saisie
 */
char *read_prompt(void)
{
	char *line = NULL;
	size_t len = 0;

	printf("#vador$ ");
	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	line[strcspn(line, "\n")] = '\0'; /* Supprime le caractère \n */
	return (line);
}
