#include <stdio.h>

int main(void) 
{
  char string1[100], string2[100];
  int equal = 1, i = 0;

  printf("Enter first string: ");
  scanf("%s", string1);

  printf("Enter second string: ");
  scanf("%s", string2);
  
  // Compare the two strings
  while (string1[i] != '\0' || string2[i] != '\0') 
  {
    if (string1[i] != string2[i]) 
    {
      equal = 0;
      break;
    }
    i++;
  }

  if (equal) 
  {
    printf("The two strings are equal.\n");
  }
  else
  {
    printf("The two strings are not equal.\n");
  }

  return 0;
}
