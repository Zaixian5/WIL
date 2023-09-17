#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE]; // 입력 줄
char longest[MAXLINE]; // 가장 긴 줄

/*입력 줄 가운데 가장 긴 줄 프린트 */
int main(void)
{
   int len;
   int max;
   max = 0;
   //double d;

  //d = 10/max;
/* int i=0;
   for (;;) {
     printf("%d\n", i); fflush(stdout);
     line[i++] = 'a';
   }
*/
 
   while (fgets(line, MAXLINE, stdin) != NULL) 
   {
      len = strlen(line);

      if (len > max)
	  {
         max = len;
         copy(line, longest);
      }
   }

   if (max > 0) // 입력 줄이 있었다면
   printf("%s\n", longest);

   printf("extern test: %d\n", k);

   return 0;
}

