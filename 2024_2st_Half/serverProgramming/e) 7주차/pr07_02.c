// pr07_02.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
  long sum = 0;

  clock_t ct;
  struct tms buf;

  for(int i = 1; i <= 1000000; i++){
    sum += i;
    printf("%ld\n", sum);
  }
  
  sleep(1);

  times(&buf);
  ct = sysconf(_SC_CLK_TCK);

  printf("Clock tick: %ld\n", ct);
  printf("User Time: %.3f sec\n", (double)buf.tms_utime / ct);
  printf("System time: %.3f sec\n", (double)buf.tms_stime / ct);
  
  return 0; 
}
