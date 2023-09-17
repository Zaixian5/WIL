#include <stdio.h>

void display(const char*);

int main(void) 
{
  display("Hello");
}
void display (const char * str)
{
  printf ("%s\n", str);
}
