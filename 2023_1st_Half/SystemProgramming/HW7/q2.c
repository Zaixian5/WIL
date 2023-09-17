#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

int main(int argc, char* argv[])
{
  FILE* fp_src, *fp_dest;
  char str[MAXSIZE];

  if(argc != 3)
  {
    fprintf(stderr, "wrong input\n");
	exit(1);
  }
  else
  {
    fp_src = fopen(argv[1], "r");
	fp_dest = fopen(argv[2], "w");

	if(fp_src == NULL)
	{
      fprintf(stderr, "file open failed");
	  exit(2);
	}
  }

  while(fgets(str, MAXSIZE, fp_src) != NULL)
  {
    for(int i = 0; str[i] != '\0'; i++)
	{
      if(str[i] >= 65 && str[i] <= 90)
	  {
		str[i] += 32;
	  }
	  else if(str[i] >= 97 && str[i] <= 122)
	  {
		str[i] -= 32;
	  }
	}

	fputs(str, fp_dest);
  }

  fclose(fp_src);
  fclose(fp_dest);

  return 0;
}
