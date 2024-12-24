#include <stdio.h>
#include <stdlib.h>

#include "sim_struct.h"

/* 알고리즘에서 사용할 큐를 링크 리스트로 구현함. */

// 새로운 노드 생성 함수
Node* create_node(int number) {
    Node* new_node = (Node*)malloc(sizeof(Node)); // 노드에 메모리 할당

    new_node->number = number;  // 페이지 번호 설정
    new_node->next = NULL;  // 다음 노드는 NULL로 초기화

    return new_node;  // 생성된 노드 반환
}

// 링크 리스트에 노드 추가 함수
// 큐에서 push와 같은 기능
void append_node(Node** head, int number) {
    Node* new_node = create_node(number);  // 새로운 노드 생성

    if (*head == NULL) {  // 리스트가 비어있는 경우
        *head = new_node;  // 새로운 노드를 헤드로 설정
        return;
    }

    Node* temp = *head;  // 리스트 순회용 임시 포인터

    while (temp->next != NULL) {  // 리스트의 끝까지 순회
        temp = temp->next;
    }

    temp->next = new_node;  // 리스트의 끝에 새로운 노드 추가
}

// 링크 리스트에서 첫 번째 노드 제거 함수
// 큐에서 pop과 같은 기능
void remove_first_node(Node** head) {
    if (*head == NULL) {  // 리스트가 비어있는 경우
        return;
    }

    Node* temp = *head;  // 첫 번째 노드를 가리키는 임시 포인터

    *head = (*head)->next;  // 헤드를 다음 노드로 이동

    free(temp);  // 첫 번째 노드 메모리 해제
}

// 특정 number의 노드를 지우는 함수
// 이전 노드의 링크를, 제거한 노드의 다음 노드와 연결함.
void remove_node(Node** head, int number) {
    Node* temp = *head; // 리스트 순회용 임시 포인터
    Node* prev = NULL; // 리스트 순회시 이전 노드를 가리키는 용도로 사용할 임시 포인터
    
    // 빈 리스트일 경우
    if (*head == NULL){
        return;
    } 

    // 헤드가 제거할 노드일 경우
    if (temp != NULL && temp->number == number) {
        *head = temp->next;
        return;
    }

    // 제거할 노드를 찾는다
    while (temp != NULL && temp->number != number) {
        prev = temp; 
        temp = temp->next; 
    }

    // 노드가 없을 경우
    if (temp == NULL) {
        return;
    }

    // 노드를 리스트에서 제거
    prev->next = temp->next; 
}

// 링크 리스트에서 특정 노드를 리스트 끝으로 이동하는 함수
// 이동할 노드의 이전 노드와 다음 노드의 링크를 연결하고, 리스트 끝에 연결.
// NRU 알고리즘에서 LRU 알고리즘을 적용하기 위해 사용된다.
void move_to_end(Node** head, int number) {

    // 리스트가 비어있거나, 노드가 하나밖에 없는 경우
    if (*head == NULL || (*head)->next == NULL) {
        return;  // 아무 작업도 수행하지 않음
    }

    Node* temp = *head;  // 리스트 순회 시, 현재 노드를 가리키는 임시 포인터
    Node* prev = NULL;  // 리스트 순회 시, 현재 노드의 이전 노드를 가리키는 임시 포인터

    // 이동할 노드를 찾음
    while (temp != NULL && temp->number != number) {
        prev = temp;  // 이전 노드를 현재 노드로 업데이트
        temp = temp->next;  // 현재 노드를 다음 노드로 업데이트
    }

    // 노드를 찾지 못한 경우 또는 이미 끝에 있는 경우
    if (temp == NULL || temp->next == NULL) {
        return;  // 아무 작업도 수행하지 않음
    }

    // 이동할 노드가 헤드 노드인 경우
    if (prev == NULL) {
        *head = temp->next;  // 헤드를 다음 노드로 업데이트
    } 
    else {
        // 이동할 노드가 중간에 있는 경우
        prev->next = temp->next;  // 이전 노드의 다음 포인터를 현재 노드의 다음 노드로 업데이트
    }

    // 노드를 리스트의 끝으로 이동시킴
    Node* last = *head;  // 리스트의 끝을 찾기 위한 임시 포인터

    while (last->next != NULL) {
        last = last->next;  // 리스트의 끝으로 이동
    }

    last->next = temp;  // 리스트의 끝에 현재 노드를 추가
    temp->next = NULL;  // 현재 노드를 리스트의 끝으로 설정
}


// 링크 리스트 메모리 해제 함수
void free_list(Node* head) {
    Node* temp;

    while (head != NULL) {  // 리스트의 모든 노드를 순회
        temp = head;  // 현재 노드를 임시 저장
        head = head->next;  // 다음 노드로 이동
        
        free(temp);  // 현재 노드 메모리 해제
    }
}
