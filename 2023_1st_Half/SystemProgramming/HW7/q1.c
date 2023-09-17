#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  FILE* fp_src, *fp_dest;
  int c;

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
		fprintf(stderr, "file open failed\n");
		exit(2);
	}
  }

  while((c = fgetc(fp_src)) != EOF)
  {
	if(c >= 65 && c <= 90)
	{
	  c += 32;
	}
	else if(c >= 97 && c <= 122)
	{
	  c -= 32;
	}

	fputc(c, fp_dest);
  }

  fclose(fp_src);
  fclose(fp_dest);

  return 0;
}
