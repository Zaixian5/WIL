// pr02_02.c

#include <stdio.h>
#include <stdlib.h>

extern int subnum(int, int);

int main(int argc, char* argv[]){
  if(argc != 3){
    fprintf(stderr, "Useage: ./pr02_02 [Num1] [Num2]\n");
    return -1;
  }

  int sub = 0;
  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[2]);
  
  sub = subnum(num1, num2);

  (num1 > num2)? 
  printf("%d - %d = %d\n", num1, num2, sub):
  printf("%d - %d = %d\n", num2, num1, sub);

  return 0;
}
