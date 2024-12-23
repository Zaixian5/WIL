// pr03_07.c

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main(){
  int zero_count = 0;
  int* array = calloc(MAX_SIZE, sizeof(int));

  for(int i = 0; i < MAX_SIZE; ++i){
    array[i] = rand() % 10;
  }

  while(*array){
    printf("%d\n", *array++);
    zero_count++;
  }

  printf("The first value: %d\n", *(array - zero_count));

  free(array - zero_count);
}
