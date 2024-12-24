#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sim_struct.h"

void append_node(Node**, int);
void remove_first_node(Node**);
void free_list(Node*);

// FIFO 알고리즘 시뮬레이션 함수
void fifo_algorithm(int total_frame) {
    FILE* fp = fopen("./access.list", "r");  // 파일 열기

    if (fp == 0) {  // 파일 열기 실패 시
        fprintf(stderr, "File Open Failed\n");  // 에러 메시지 출력
        exit(-1);  // 프로그램 종료
    }

    int total_access = 0; // 총 access 수
    int access_num; // access.list에서 읽어들인 페이지 번호
    char access_operation[10]; // access.list에서 읽어들인 operation(read, write)을 저장하는 문자열

    int read_count = 0; // read의 개수
    int write_count = 0; // write의 개수

    Node* page_table = NULL;  // 페이지 테이블 링크 리스트 초기화

    int page_set[1001] = { 0 }; // 페이지가 메모리에 있는지 기록하는 배열. 인덱스는 페이지 번호, 요소 값은 메모리에 있으면 1, 없으면 0

    int page_hit = 0;  // 페이지 히트 수
    int page_fault = 0;  // 페이지 폴트 수

    int occupied_frame = 0;  // 현재 점유된 프레임 수

    while (fscanf(fp, "%d %s", &access_num, access_operation) != EOF) {
        total_access++; // 총 access 수 증가

        if(strcmp(access_operation, "read") == 0){
            read_count++; // access_operation이 read라면 read_count를 증가
        }
        else if(strcmp(access_operation, "write") == 0){
            write_count++; // access_operation이 write라면 write_count를 증가
        }
        
        if (page_set[access_num] == 1) {  // 페이지가 메모리에 있는 경우
            page_hit++;  // 페이지 히트 증가
        } 
        else {  // 페이지가 메모리에 없는 경우
            page_fault++;  // 페이지 폴트 증가

            if (occupied_frame < total_frame) {  // 아직 사용할 수 있는 프레임이 남아있는 경우
                append_node(&page_table, access_num);  // 페이지를 페이지 테이블에 추가(push)

                page_set[access_num] = 1;  // 페이지가 메모리에 있음을 표시
                occupied_frame++;  // 점유된 프레임 수 증가
            } 
            else {  // 사용할 수 있는 프레임이 없는 경우
                page_set[page_table->number] = 0;  // 교체될 페이지가 메모리에서 제거됨을 표시

                remove_first_node(&page_table);  // 페이지 테이블에서 첫 번째 노드 제거(pop)
                append_node(&page_table, access_num);  // 새로운 페이지를 페이지 테이블에 추가(push)

                page_set[access_num] = 1;  // 새로운 페이지가 메모리에 있음을 표시
            }
        }
    }

    // 결과 출력
    printf("Total number of access: %d\n", total_access); // 모든 access 수 출력
    printf("Total number of read: %d\n", read_count); // 모든 read 수 출력
    printf("Total number of write: %d\n", write_count); // 모든 write 수 출력
    printf("Number of page hits: %d\n", page_hit); // 모든 페이지 히트 수 출력
    printf("Number of page faults: %d\n", page_fault); // 모든 페이지 폴트 수 출력
    printf("Page fault rate: %d/%d = %.2f%%\n", page_fault, total_access, (double)page_fault / total_access * 100); // 페이지 폴트율 출력

    free_list(page_table);  // 페이지 테이블 메모리 해제
}
