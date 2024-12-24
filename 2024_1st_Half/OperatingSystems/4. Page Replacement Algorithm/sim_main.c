#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fifo_algorithm(int);
void nru_algorithm(int);

// 메인 함수
int main(int argc, char* argv[]) {
    if (argc != 3) {  // 명령줄 인수 개수가 맞지 않을 때
        fprintf(stderr, "Wrong Input. Try Again\n");  // 에러 메시지 출력
        exit(-1);  // 프로그램 종료
    }

    char* algorithm = argv[1];  // 알고리즘 종류. fifo 혹은 nru
    int total_frame = atoi(argv[2]);  // 최대 프레임 수

    if (strcmp(algorithm, "fifo") == 0) {  // fifo 알고리즘 선택 시
        fifo_algorithm(total_frame);  // FIFO 시뮬레이션 실행
    }
    else if(strcmp(algorithm, "nru") == 0) { // nru 알고리즘 선택 시
        nru_algorithm(total_frame);  // NRU 시뮬레이션 실행
    }
    
    return 0;  // 프로그램 종료
}
