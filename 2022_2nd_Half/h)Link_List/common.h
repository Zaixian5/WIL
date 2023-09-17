#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdbool.h>

typedef struct node_t // node 구조체
{
	int key;
	struct node_t* next; // NODE* next;로 쓸 수 없다. NODE가 밑에 정의되어 있기 때문.
} NODE;                  // 구조체가 계속해서 같은 구조체를 가리키도록 하는 구조. 각각의 구조체가 node가 됨.

NODE* node_alloc(int);
void insert_front(int);
void delete_front(void);
void print_list(void);
bool contains(int);
void find_n_delete(int);

#endif 