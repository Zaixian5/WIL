#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sim_struct.h"

void append_node(Node**, int);
void remove_node(Node** head, int number);
void move_to_end(Node**, int);
void free_list(Node*);

// 어떤 페이지를 교체해야 하는지 찾아주는 함수
int which_to_replace(NRU_PAGE* nru_pages, Node* page_table, int* page_set) {
    // 리스트를 순회하기 위한 임시 포인터 변수
    Node* current = page_table;

    // 클래스 분류
    // 클래스는 0 ~ 4번까지 있다.
    // 0 ~ 4까지의 클래스는 (r비트, m비트)가 각각 (0, 0), (0, 1), (1, 0), (1, 1)이다.
    // 페이지 교체의 우선순위는 '클래스 0 > 클래스 1 > 클래스 2 > 클래스 3'이다.
    int class_0 = -1, class_1 = -1, class_2 = -1, class_3 = -1;

    // 리스트의 끝에 도달할 때까지(즉, 현재 메모리에 있는 모든 페이지를) 순회.
    while (current != NULL) {
        int page_num = current->number; // 페이지 번호 저장

        // 이 계산식은 비트가 (0, 0), (0, 1), (1, 0), (1, 1)일때, 계산결과가 각각 0, 1, 2, 3이 되게끔 한다.
        int nru_class = nru_pages[page_num].r_bit * 2 + nru_pages[page_num].m_bit;

        if (nru_class == 0) { // 해당 페이지가 클래스 0일때
            class_0 = page_num; // 클래스 0 변수에 페이지 번호 저장
            break; // 클래스 0은 우선순위가 가장 높으므로 바로 반환
        }
        else if (nru_class == 1 && class_1 == -1) { // 해당 페이지가 클래스 1일때
            class_1 = page_num; // 클래스 1 변수에 페이지 번호 저장
        }
        else if (nru_class == 2 && class_2 == -1) { // 해당 페이지가 클래스 2일때
            class_2 = page_num; // 클래스 2 변수에 페이지 번호 저장
        }
        else if (nru_class == 3 && class_3 == -1) { // 해당 페이지가 클래스 3일때
            class_3 = page_num; // 클래스 3 변수에 페이지 번호 저장
        }

        // 다음 노드로 이동
        current = current->next;
    }

    /* 부연설명: */
    // 아래 nru_algorithm 함수에서 페이지 히트가 났을 때 move_to_end 함수를 통해 해당 페이지를 연결 리스트의 가장 마지막에 보내도록 만들었다.
    // 즉, 연결 리스트에서 head에 가까이에 있는 페이지일 수록 메모리 상에 오래 있었던 페이지라는 뜻이다.
    // 따라서, 노드 순회시 같은 클래스의 페이지가 여러개 발견되었을 때는, 먼저 발견된 페이지일 수록 메모리에 오래 있었던 페이지가 된다.
    // 위의 조건문과 아래의 반환문은 이것을 고려하여 클래스 0이 발견되면 바로 반환하고, 
    // 그렇지 않으면 다음 우선순위 클래스의 페이지 중 가장 먼저 발견된 것을 반환하도록 한 것이다. 
    // 이는 우선순위가 같은 클래스가 있을시, LRU 알고리즘을 구현한 것이 된다.

    if (class_0 != -1) return class_0; // 클래스 0 페이지 반환
    if (class_1 != -1) return class_1; // 클래스 1 페이지 반환
    if (class_2 != -1) return class_2; // 클래스 2 페이지 반환
    if (class_3 != -1) return class_3; // 클래스 3 페이지 반환

    return -1; // 함수가 제대로 반환되었다면 이것을 반환하지는 않음
}

void nru_algorithm(int total_frame){
    FILE* fp = fopen("./access.list", "r");  // 파일 열기

    if (fp == 0) {  // 파일 열기 실패 시
        fprintf(stderr, "File Open Failed\n");  // 에러 메시지 출력
        exit(-1);  // 프로그램 종료
    }

    NRU_PAGE* nru_pages  = (NRU_PAGE*)malloc(sizeof(NRU_PAGE) * 1001); // nru_page 정보를 저장하는 구조체 배열 할당

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

        if (page_set[access_num] == 1) {  // 페이지가 메모리에 있는 경우
            page_hit++;  // 페이지 히트 증가
            nru_pages[access_num].r_bit = 1;  // 읽기 접근 시 r_bit 설정

            if (strcmp(access_operation, "write") == 0) {
                nru_pages[access_num].m_bit = 1;  // 쓰기 접근 시 m_bit 설정
                write_count++; // write_count를 증가
            } 
            else {
                read_count++; // read_count를 증가
            }

            move_to_end(&page_table, access_num); // LRU 구현을 위해 페이지를 리스트의 끝으로 이동
        } 
        else {  // 페이지가 메모리에 없는 경우
            page_fault++;  // 페이지 폴트 증가

            if (occupied_frame < total_frame) {  // 아직 사용할 수 있는 프레임이 남아있는 경우
                append_node(&page_table, access_num);  // 페이지를 페이지 테이블에 추가
                page_set[access_num] = 1;  // 페이지가 메모리에 있음을 표시

                // 페이지가 처음 메모리에 올라왔을 때 r비트는 0으로 설정.
                nru_pages[access_num].r_bit = 0;

                if (strcmp(access_operation, "write") == 0) {
                    nru_pages[access_num].m_bit = 1; // access_operation이 write라면 m비트를 1로 설정
                    write_count++; // write_count를 증가
                } 
                else {
                    nru_pages[access_num].m_bit = 0; // access_operation이 read라면 m비트를 0으로 설정 
                    read_count++; // read_count를 증가
                }

                occupied_frame++;  // 점유된 프레임 수 증가
            } 
            else {  // 사용할 수 있는 프레임이 없는 경우
                int replace_page = which_to_replace(nru_pages, page_table, page_set); // 교체할 페이지 선택

                if(replace_page != -1){
                    page_set[replace_page] = 0;  // 교체될 페이지가 메모리에서 제거됨을 표시

                    remove_node(&page_table, replace_page);  // 선택된 페이지를 페이지 테이블에서 제거
                    append_node(&page_table, access_num);  // 새로운 페이지를 페이지 테이블에 추가

                    page_set[access_num] = 1;  // 새로운 페이지가 메모리에 있음을 표시

                    // 페이지가 처음 메모리에 올라왔을 때 비트 설정
                    nru_pages[access_num].r_bit = 0;

                    if (strcmp(access_operation, "write") == 0) {
                        nru_pages[access_num].m_bit = 1; // access_operation이 write라면 m비트를 1로 설정
                        write_count++; // write_count를 증가
                    } 
                    else { 
                        nru_pages[access_num].m_bit = 0; // access_operation이 read라면 m비트를 0으로 설정 
                        read_count++; // read_count를 증가
                    }
                }
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

    free(nru_pages); // 페이지 테이블 메모리 해제
    free_list(page_table); // 링크드 리스트 메모리 해제
}
