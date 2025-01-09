#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

/* Function Prototypes */
void prompt(void);
char *read_input(void);
char **parse_input(char *input);
int execute(char **args);
int handle_builtin(char **args);
char *find_command(char *command);
void free_args(char **args);

#endif
