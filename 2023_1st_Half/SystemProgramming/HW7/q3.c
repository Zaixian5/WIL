#include <stdio.h>
#define MAXSIZE 50

int main(void)
{
  int shift = 0;
  char str[MAXSIZE] = { 0 };

  printf("shift number: ");
  scanf("%d", &shift);

  while(fgets(str, MAXSIZE, stdin) != NULL)
  {
    for(int i = 0; str[i] != '\0'; i++)
	{
	  if(str[i] >= 65 && str[i] <= 90)
	  {
		str[i] += shift;

		if(str[i] > 90)
		{
		  str[i] -= 26;
		}
	  }
	  else if(str[i] >= 97 && str[i] <= 122)
	  {
		str[i] += shift;

		if(str[i] > 122)
		{
		  str[i] -= 26;
		}
	  }
	}

	printf("%s", str);
  }

  return 0;
}
