#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // sleep() 함수가 있는 헤더파일
#include <signal.h> // kill() 함수가 있는 헤더파일

#define MAX_PROCESS 200

int main(void)
{
  FILE* fp_confession;
  FILE* fp_process;
  int pid[MAX_PROCESS];
  int mafia_idx = 0;
  int total_mafia = 0;
	
  // linuxtown_class1 파일을 실행합니다.
  // 프로그램이 백그라운드에서 실행되고 출력값을 표시하지 않도록 명령합니다.
  system("./linuxtown_class1 > /dev/null &");

  // 200개의 프로세스가 모두 실행 되게끔 충분한 시간을 대기합니다.
  printf("Searching For Mafia(3sec)...\n\n");
  sleep(3);

  // linuxtown_class1 실행시 생성되는 프로세스 정보를 process.txt 파일에 저장합니다. 
  system("ps | grep linuxtown_class > process.txt");
  
  fp_process = fopen("./process.txt", "r");
  
  if(fp_process == NULL)
  {
    fprintf(stderr, "%s\n", "File(process.txt) Open Failed");

    return -1;
  }
  else
  {
    for(int i = 0; i < MAX_PROCESS; i++)
    {
      // process.txt의 내용 중 PID에 해당하는 숫자만 pid 배열에 저장합니다.
      fscanf(fp_process, "%d %*s %*s %*s", &pid[i]);
    }
  }

  fclose(fp_process);
  
  for(int i = 0; i < MAX_PROCESS; i++)
  {
    // linuxtown_class1이 생성한 모든 프로세스에게 SIGUSR1 시그널을 보냅니다.
    kill(pid[i], SIGUSR1);
  }
  
  // 실행중인 linuxtown_class 프로세스들을 모두 종료시킵니다.
  system("pkill -9 linuxtown_class");

  fp_confession = fopen("./confession.txt", "r");

  if(fp_confession == NULL)
  {
    fprintf(stderr, "%s\n", "File(confession.txt) Open Failed\n");

    return -1;
  }
  else
  {
    char is_mafia[100];

    while(fscanf(fp_confession, "%s", is_mafia) != EOF)
    {
      // 마피아는 SIGUSR1에 반응하면 confession.txt파일에 !!!를 남깁니다.
      // confession.txt 파일에서 !!!가 출력된 줄 번호를 이용해 마피아의 PID를 알아낼 수 있습니다.
      if (strncmp(is_mafia, "!!!", strlen(is_mafia)) == 0)
      {
        printf("Mafia Found!!! PID: %d\n", pid[mafia_idx]);
	total_mafia++;
      }

      mafia_idx++;
    }  
  }
  printf("\n");
  printf("There was %d Mafia in Linux Town\n", total_mafia);

  fclose(fp_confession);

  return 0;
}
