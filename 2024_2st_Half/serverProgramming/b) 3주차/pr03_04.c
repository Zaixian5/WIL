// pr03_04.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void help(){
  printf("./pr03_04.out [option] int m int n\n");
}

int gcd(int m, int n){
  int gcd = 1;
  int min = n;

  if(m < n){
    min = m;
  }
  
  for(int i = 1; i <= min; i++){
    if((m % i == 0) && (n % i == 0)){
      gcd = i;
    }
  }

  return gcd;
}

int lcm(int m, int n){
  return (m * n) / gcd(m, n);  
}

int main(int argc, char* argv[]){
  int n;
  extern char* optarg;
  extern int optind;

  if(argc != 1){
    while((n = getopt(argc, argv, "g:n:t:p:")) != -1){
      switch(n){
        case 'g':
            printf("%d\n", gcd(atoi(optarg), atoi(argv[optind])));
            break;

        case 'n':
            printf("%d\n", lcm(atoi(optarg), atoi(argv[optind])));
            break;

        case 't':
            printf("%d\n", atoi(optarg) * atoi(argv[optind]));
            break;

        case 'p':
            printf("%d\n", atoi(optarg) + atoi(argv[optind]));
            break;

        case '?':
        case ':':
            help();
            break;
      }
    }
  }

  return 0;
}
