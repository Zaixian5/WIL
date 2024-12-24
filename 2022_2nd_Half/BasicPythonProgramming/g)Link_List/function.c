#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "common.h"

NODE* head = NULL; // head: ù ��° ��带 ����Ű�� ������

NODE* node_alloc(int key) // ��带 �����ϴ� �Լ�
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
	if (head == NULL) // �� ��忡 ����(������ ��尡 �� ��)
	{
		NODE* new_node = node_alloc(key);
		if (new_node)
		{
			head = new_node;
		}
	}
	else // �� ��忡 ����(ó�� ��尡 �� ��) - �տ��� ���� �����ϴ� ���
	{
		NODE* new_node = node_alloc(key);
		if (new_node)
		{
			new_node->next = head;
			head = new_node;
		}
	}
}
void delete_front(void) // �տ��� ���� ����
{
	if (head != NULL)
	{
		NODE* tmp = head;
		head = head->next;

		free(tmp);
	}
}
void print_list(void) // ����� �ڷḦ ������� ����ϴ� �Լ�
{
	NODE* current = head;

	while (current != NULL)
	{
		printf("%d ", current->key);
		current = current->next;
	}
	printf("\n");
}
bool contains(int target) // ��忡 Ư�� Ű ���� �ִ��� Ž���ϴ� �Լ�
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
void find_n_delete(int target) // ��忡 Ư�� Ű ���� ã�� �������ִ� �Լ�
{
	if (head == NULL)
	{
		return;
	}

	if (head->key == target) // ���� Ư�� Ű ���� ù��° ����� ��� delete_front() �Լ��� ����
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
		-���� ��尡 �������� ��带 ����Ű���� �ϴ� �˰���

		��)
		- head -> 30 -> 20 -> 10 -> NULL
		- ���⼭ 20�� ���� �Ϸ���, 30�� 10�� ����Ű�� �ϰ� 20�� �޸𸮴� ��ȯ�ؾ���.
		- head -> 30 -> 10 -> NULL
	*/
}