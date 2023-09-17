#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "common.h"

NODE* head = NULL; // head: 첫 번째 노드를 가리키는 포인터

NODE* node_alloc(int key) // 노드를 생성하는 함수
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));

	if (new_node != NULL)
	{
		new_node->key = key;
		new_node->next = NULL;
	}

	return new_node;
}
void insert_front(int key)
{
	if (head == NULL) // 빈 노드에 삽입(마지막 노드가 될 것)
	{
		NODE* new_node = node_alloc(key);
		if (new_node)
		{
			head = new_node;
		}
	}
	else // 새 노드에 삽입(처음 노드가 될 것) - 앞에서 부터 삽입하는 방식
	{
		NODE* new_node = node_alloc(key);
		if (new_node)
		{
			new_node->next = head;
			head = new_node;
		}
	}
}
void delete_front(void) // 앞에서 부터 삭제
{
	if (head != NULL)
	{
		NODE* tmp = head;
		head = head->next;

		free(tmp);
	}
}
void print_list(void) // 노드의 자료를 순서대로 출력하는 함수
{
	NODE* current = head;

	while (current != NULL)
	{
		printf("%d ", current->key);
		current = current->next;
	}
	printf("\n");
}
bool contains(int target) // 노드에 특정 키 값이 있는지 탐색하는 함수
{
	NODE* current = head;

	while (current != NULL)
	{
		if (current->key == target)
		{
			return true;
		}
		current = current->next;
	}

	return false;
}
void find_n_delete(int target) // 노드에 특정 키 값을 찾아 삭제해주는 함수
{
	if (head == NULL)
	{
		return;
	}

	if (head->key == target) // 만약 특정 키 값이 첫번째 노드일 경우 delete_front() 함수로 삭제
	{
		delete_front();
		return;
	}

	NODE* previous = NULL;
	NODE* current = head;

	while (current != NULL)
	{
		if (current->key == target)
		{
			previous->next = current->next;
			free(current);

			return;
		}
		previous = current;
		current = current->next;
	}
	/*
		-이전 노드가 다음다음 노드를 가리키도록 하는 알고리즘

		예)
		- head -> 30 -> 20 -> 10 -> NULL
		- 여기서 20만 삭제 하려면, 30이 10을 가리키게 하고 20의 메모리는 반환해야함.
		- head -> 30 -> 10 -> NULL
	*/
}