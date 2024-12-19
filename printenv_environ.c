#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
    unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    printf("--------------------------------------------------------\n");
    for (i = 0; environ[i]; i++)
        printf("%s\n", environ[i]);
    return (0);
}
