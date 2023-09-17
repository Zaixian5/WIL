#include <stdio.h>

int multiply(int, int);
int add(int, int);
float divide(int, int);
void subtract(int, int);

int main(void)
{
  int x;
  x = 10;
  printf("The value of x is %d\n", x);
  return 0;
}

int multiply(int a, int b) 
{
  return a * b;
}

int add(int a, int b) 
{
  return a + b;
}

float divide(int a, int b) 
{
  if (b == 0) 
  {
    printf("Cannot divide by zero.\n");
    return 0;
  } 
  else 
  {
    return (float)a / b;
  }
}

void subtract(int a, int b) 
{
  int result = a - b;
  printf("The result is %d\n", result);
}
