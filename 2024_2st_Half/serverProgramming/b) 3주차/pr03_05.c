// pr03_05.c

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int count_vowel(char* str){
  int count = 0;
    
  for(int i = 0; str[i] != '\0'; ++i){
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
      count++;
    }
  }
  
  return count; 
}

int main(){
  int n;
  int total_vowel = 0;

  printf(">> ");
  scanf("%d", &n);

  char** strings = calloc(n, sizeof(char*));

  for(int i = 0; i < n; ++i){
    strings[i] = calloc(MAX_SIZE, sizeof(char));
    scanf("%s", strings[i]);
  }

  for(int i = 0; i < n; ++i){
    total_vowel += count_vowel(strings[i]);
    free(strings[i]);  
  }

  printf(">> %d\n", total_vowel);

  free(strings);
  return 0;
}
