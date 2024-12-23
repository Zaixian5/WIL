// pr07_01.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
  int fd;
  char str[] = "a\n";
  
  time_t t;
  struct tms buf;
  clock_t ct = sysconf(_SC_CLK_TCK);

  int i = 1;
  while(i <= 100000){
    fd = open("input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, str, sizeof(str));
    close(fd);

    i++;
  }

  sleep(1);
  
  times(&buf);

  printf("Clock tick: %ld\n", ct);
  printf("User Time: %.3f sec\n", (double)buf.tms_utime / ct);
  printf("System time: %.3f sec\n", (double)buf.tms_stime / ct);

  return 0;
}
