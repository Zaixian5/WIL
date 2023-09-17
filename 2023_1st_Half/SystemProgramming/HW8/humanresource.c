#include <stdio.h>
#include <stdlib.h>

#include "humanresource.h"

int main(int argc, char* argv[])
{
  FILE* fp_save;
  HUMAN rec;

  if(argc != 2)
  {
    fprintf(stderr, "wrong input\n");
    exit(1);    
  }

  fp_save = fopen(argv[1], "wb");
  
  printf("Enter employee profile\n");
  printf("%-9s %-9s %-9s %-9s %-10s\n", "ID", "name", "tel.", "dpt.", "hired date");

  while(scanf("%d %s %s %s %s", &rec.id, rec.name, rec.call, rec.dpt, rec.date) == 5)
  {
    fwrite(&rec, sizeof(rec), 1, fp_save);
  }

  printf("-----Texts are saved to binary file-----\n");

  fclose(fp_save);

  return 0;
}
