// pr02_04.c

#include <stdio.h>
#include <unistd.h>

void print_option();

int main(int argc, char* argv[]){
  int n;
  extern char* optarg;
  
  if((n = getopt(argc, argv, "pn:h")) == -1){
    print_option();
  }
  else{
    switch(n){
      case 'p':
          printf("Welcome to Linux Server Programming!\n");
          break;

      case 'n':
          printf("Nice to meet you %s!\n", optarg);
          break;

      case 'h':
          print_option();
          break;
    }
  }
}

void print_option(){
  printf("Available Options:\n");
  printf("[p Welcome to Linux Server Programming!]\n");
  printf("[n Nice to meet you, ???]\n");
  printf("[h help!]\n");
}
