#include <stdio.h>

int main(__attribute__((unused)) int ac, char **av)
{
  int i = 1;
  while (av[i])
    {
      printf("%s", av[i]);
      if (av[i + 1])
        printf(" ");
      i++;
    }
  printf("\n");
  return (0);
}
