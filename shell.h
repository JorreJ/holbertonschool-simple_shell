#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes des fonctions */
char *read_prompt(void);
void execute_command(char *line);
int _strcmp(const char *s1, const char *s2);

#endif
