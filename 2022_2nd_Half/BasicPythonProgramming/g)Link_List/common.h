#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdbool.h>

typedef struct node_t // node ����ü
{
	int key;
	struct node_t* next; // NODE* next;�� �� �� ����. NODE�� �ؿ� ���ǵǾ� �ֱ� ����.
} NODE;                  // ����ü�� ����ؼ� ���� ����ü�� ����Ű���� �ϴ� ����. ������ ����ü�� node�� ��.

NODE* node_alloc(int);
void insert_front(int);
void delete_front(void);
void print_list(void);
bool contains(int);
void find_n_delete(int);

#endif 