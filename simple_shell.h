#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
void _env(char **env);
void exec_command(char *string, char **env);
char **parse_input(char *string);
char *command_path(char *string, char **env);
void _env(char **env);
char *_getenv(const char *name, char **env);

#endif /* SIMPLESHELL_H */
