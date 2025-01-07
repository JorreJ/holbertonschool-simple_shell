#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
    int i;
    pid_t child;
    for (i = 0; i < 5; i++)
    {
        child = fork();
        if (child == -1)
        {
            perror("Error:");
            return (1);
        }
        if (child == 0)
        {
            if (execve(argv[0], argv, NULL) == -1)
                perror("Error:");
        }
        else
        {
            wait(NULL);
        }
    }
    return (0);
}
