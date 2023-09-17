#include <stdio.h>

int main(void)
{
  char string1[100], string2[100], result[200];
  int i = 0, j = 0;

  printf("Enter first string: ");
  scanf("%s", string1);

  printf("Enter second string: ");
  scanf("%s", string2);

  // Copy the first string to the result string
  while (string1[i] != '\0')
  {
    result[i] = string1[i];
    i++;
  }

  // Concatenate the second string to the result string
  while (string2[j] != '\0') 
  {	  
    result[i] = string2[j];
    i++;
    j++;
  }

  // Add null character to the end of the result string
  result[i] = '\0';

  printf("The concatenated string is: %s\n", result);

  return 0;
}
