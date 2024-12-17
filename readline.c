#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *string;
  size_t len;
  string = malloc(1024);
  len = 1024;
  while (1)
    {
      printf("$ ");
      getline(&string, &len, stdin);
      printf("%s", string);
    }
  return (0);
}
