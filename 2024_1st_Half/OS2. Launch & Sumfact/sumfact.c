#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREAD 100 // 스레드는 최대 100개까지만 생성하도록 제한

// 스레드의 식변번호와 명령행 인수를 저장하는 구조체
// 이 구조체를 만든 이유:
// 스레드를 생성하는 pthread_create() 함수는 네번째 인수로 스레드 함수의 매개변수로 보낼 값을 받는다.
// 그런데 값을 하나만 보내도록 정의 되어있어 여러개의 인수를 보내고자 할 땐,
// 보내고 싶은 값을 구조체로 정의하여 구조체의 포인터를 전달하는 방법을 사용해야 한다.
typedef struct{
  int thread_idx; // 스레드의 식별번호를 저장할 변수
  int num; // 명령행 인수 값을 저장할 변수
}THREAD_CREATE_4TH_ARG; 

void* thread_function(void*); // 스레드 함수 원형

int main(int argc, char* argv[]){
  if(argc != 2){ // 명령행 인수가 2개가 아닐경우 오류 발생
    fprintf(stderr, "Wrong Input!\n");
    exit(-1);
  }
  else{ // 명령행 인수가 2개일 경우 정상 실행
    int return_value; // pthread_create() 함수의 반환값을 저장하는 변수
    int exit_value; // thread_function() 함수의 반환값을 저장하는 변수
    pthread_t thread[MAX_THREAD]; // 스레드 식별자를 저장할 배열
    
    // 구조체를 동적 할당하고 명령행 인수 크기 만큼 스레드를 생성하는 반복문
    // 구조체를 명령행 인수 크기 만큼 선언하는 이유:
    // 만약 구조체를 이 반복문 외부에 한 번 선언하고 스레드 함수에서 사용하게끔 한다면,
    // 여러 스레드가 하나의 구조체에 동시에 접근하는 상황이 발생한다.
    // 즉, 그 구조체가 Critical Section이 되므로 구조체를 각각 따로 선언해야 하는 것이다.
    for(int i = 0; i < atoi(argv[1]); i++){ 
      THREAD_CREATE_4TH_ARG* arg = (THREAD_CREATE_4TH_ARG*)malloc(sizeof(THREAD_CREATE_4TH_ARG));
      arg->num = atoi(argv[1]); // 구조체 num 변수에 명령행 인수 값을 저장
      arg->thread_idx = i; // 구조체 thread_idx 변수에 스레드 식별번호를 저장

      return_value = pthread_create(&thread[i], NULL, thread_function, (void*)arg); // 스레드를 생성하고 반환값을 저장 

      if(return_value != 0){ // 반환값이 0이 아니라면 스레드 생성 오류
        fprintf(stderr, "Thread Create Failed!\n");
        exit(-1);
      }
    }
    
    // 스레드의 실행이 완료될 때까지 기다려 주기 위한 pthread_join() 함수를 실행하고, 계산 결과 값을 출력하기 위한 반복문
    for(int i = 0; i < atoi(argv[1]); i++){
      pthread_join(thread[i], (void**)&exit_value); // 해당 스레드가 실행이 완료될 때까지 기다리고 반환값을 가져옴. 이 함수는 반환값을 가져올 변수를 void** 형으로 하도록 정의되어 있음

      if(i == 0){ // i 값이 0이라면 첫 번째 스레드이므로 팩토리얼 값을 출력하도록 함
        printf("sumfact : factorial = %d\n", exit_value);
      }
      else{ // i 값이 0이 아니라면 나머지 스레드이므로 sum 값을 출력하도록 함
        printf("sumfact : sum = %d\n", exit_value);
      }
    }
  }

  return 0;
}

// 스레드 함수의 정의
void* thread_function(void* p_arg){
  THREAD_CREATE_4TH_ARG* arg = (THREAD_CREATE_4TH_ARG*)p_arg; // void* 형을 구조체 포인터 형으로 변환하여 사용.
  long factorial = 1; // 팩토리얼 계산 결과를 저장할 변수
  long sum = 0; // 합 계산 결과를 저장할 변수

  if(arg->thread_idx == 0){ // 스레드 식별번호가 0이면 첫 번째 스레드이므로 팩토리얼을 계산하고 반환
    for(int i = 1; i <= arg->num; i++){
      factorial *= i; // 팩토리얼을 계산하는 반복문
    }
    
    free(arg); // 동적 메모리 해제
    pthread_exit((void*)factorial); // pthread_exit() 함수로 팩토리얼 값을 반환. 이 함수는 반환값을 void* 형으로 하도록 정의되어 있음.
  }
  else{ // 스레드 식별번호가 0이 아니라면 나머지 스레드이므로 합 계산을 하고 반환
    for(int i = 1; i <= arg->num; i++){
      sum += i; // 합 계산을 하는 반복문
    }
    
    free(arg); // 동적 메모리 해제
    pthread_exit((void*)sum); // pthread_exit() 함수로 sum 값을 반환
  }
}
