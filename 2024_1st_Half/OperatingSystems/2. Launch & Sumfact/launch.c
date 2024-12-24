#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  if (argc != 2){ // 명령행 인수가 2개가 아니면 오류발생
    fprintf(stderr, "Wrong Input!\n");
    exit(-1);
  } 
  else{ // 명령행 인수가 2개라면 정상 실행
    pid_t pid = fork(); // 자식 프로세스를 생성하고 pid에 반환값 저장

    switch(pid){
      case -1: // 반환값이 -1이면 자식 프로세스 생성 실패
        fprintf(stderr, "Fork Failed!\n");
	exit(-1);
	break;

      case 0: // 반환값이 0이면 자식 프로세스이므로 자식프로세스의 동작 구현
	printf("launch : start sumfact %s\n", argv[1]); // 자식 프로세스가 sumfact를 실행함을 알림
	
	if(execlp("./sumfact", "./sumfact", argv[1], NULL) == -1){ // 자식 프로세스가 sumfact를 실행하는 코드
	  fprintf(stderr, "Exec Failed!\n"); // 함수 반환 값이 -1이면 sumfact 실행 실패
          exit(-1);
	}
	break;

      default: // 이외의 반환값은 부모 프로세스이므로 부모 프로세스의 동작 구현
	int num = atoi(argv[1]); // 변수 num에 프로그램 실행시 입력한 인수를 저장(atoi(): 문자열을 정수로 바꿔주는 함수)
	int sum = 0; // 합 계산 결과를 저장하는 변수

	for(int i = 1; i <= num; i++){
	  sum += i; // 1부터 num까지의 수를 더함
	}

        printf("launch : sum = %d\n", sum); // 부모 프로세스에서 sum 계산 결과를 출력
    }

    if(wait(NULL) == -1){ // 부모 프로세스에서 자식 프로세스가 종료될 때까지 기다림
      fprintf(stderr, "Wait Error Occured!\n"); // wait() 반환값이 -1이면 함수 실행 오류 발생
      exit(-1);
    }
    else{
      return 0;  
    }
  }
}
