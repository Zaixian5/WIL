// pr07_03.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  if(argc < 2){
    fprintf(stderr, "Usage: ./pr07_03.out <env>\n");
    exit(1);
  }
	
  char* val = getenv(argv[1]);

  if(val == NULL){
    fprintf(stderr, "%s not defined\n", argv[1]);
    exit(1);
  }

  printf("%s = %s\n", argv[1], val);

  return 0;
}
