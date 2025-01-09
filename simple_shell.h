#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int _strlen(char *s);
void exec_command(char *string, char *inter_name);

#endif /* SIMPLESHELL_H */