// pr07_04.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  char* val;

  setenv(argv[1], argv[2], 0);

  val = getenv(argv[1]);
  printf("%s=%s\n", argv[1], val);

  unsetenv(argv[1]);

  return 0;
}
