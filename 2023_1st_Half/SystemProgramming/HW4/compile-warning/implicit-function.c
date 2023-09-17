#include <stdio.h>

void display(char*);

int main (void)
{
  printf("Hello World!\n");
  display("Good Morning");
  return 0;
}

void display(char *str)
{
  printf("%s\n", str);
}
