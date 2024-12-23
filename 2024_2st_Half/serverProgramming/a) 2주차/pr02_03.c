// pr02_03.c

#include <stdio.h>
#include <stdlib.h>

extern int addnums(int*, int);

int main(int argc, char* argv[]){
  if(argc != 3){
    fprintf(stderr, "Useage: ./pr02_03 [Num1] [Num2]\n");
    return -1;
  }

  int n = atoi(argv[1]);
  int m = atoi(argv[2]);

  int* nums = (int*)malloc(sizeof(int) * n);
  
  for(int i = 0; i < n; ++i){
    nums[i] = i + 1;
  }

  int result1 = addnums(nums, n);
  
  nums = (int*)realloc(nums, sizeof(int) * m);

  for(int i = 0; i < m; ++i){
    nums[i] = i + n + 1;
  }
  
  int result2 = addnums(nums, m);

  printf("%d %d\n", result1, result2);

  free(nums);  
  return 0;
}
