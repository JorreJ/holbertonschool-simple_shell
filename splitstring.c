#include <string.h>
#include <stdio.h>

char split_string(char *str, int n)
{
    int i;
    char string[n];
    for (i = 0; i < n; i++)
    {
        string[i] = strtok(str, " ");
        printf("%s ", string[i]);
    }
    return (string);
}

int main(void)
{
    char *str = "test";
    split_string(str, 1);
    str = "test2";
    split_string(str, 1);
    str = "test test";
    split_string(str, 2);
}
