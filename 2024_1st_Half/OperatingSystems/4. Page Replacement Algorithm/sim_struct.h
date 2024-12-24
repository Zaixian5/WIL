#ifndef SIM_STRUCT_H // 헤더가드 정의
#define SIM_STRUCT_H

// NRU 알고리즘에서 페이지 번호와 operation을 기록할 구조체
typedef struct {
    int nru_number; // 페이지 번호
    int r_bit; // r비트
    int m_bit; // m비트
} NRU_PAGE;

// 링크 리스트 노드 구조체
typedef struct Node {
    int number;        // 페이지 번호
    struct Node* next; // 다음 노드 포인터
} Node;

#endif
