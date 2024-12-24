#include <stdio.h>

#include "common.h"

/*
	<���Ḯ��Ʈ>

	-����: �����Ϳ� �����Ҵ��� �̿��� �ڷḦ �����ϰ� �����ϰ� �����ϴ� �˰���
	-����:
			1. �ڷḦ �����ϴ� ������ ���(Node)�� Ī�ϰ� �̸� ����ü�� �����Ѵ�.
			2. ������ ���� �ڷᰡ ����Ǿ� �ִ� ���� key�� ���� ��带 ����Ű�� ������ ���� next�� �����ȴ�.
			3. ������ ����� next�� NULL�� �ȴ�. ��, ��� ����ü�� NULL�� ���� ������ ����ؼ� ���� ����ü�� ����Ű�� ������� ����.
			4. ����ü�� �ּ� ���� �̿��ؾ� �ϹǷ� �����Ҵ��� ����Ѵ�.
			5. ���� �˰��� �� ���⼱ ù��° ��带 ����Ű�� ������ head�� �̿��Ͽ� �տ��� ���� �����ϰ� �����Ǵ� �˰����� �����Ͽ���.
	-����:
			head -> 30(ù ���) -> 20(�ι�° ���) -> 10(������ ���) -> NULL

	-���Ϻ���:
				1. main.c -> �˰��� ���� Ȯ��
				2. function.c -> �˰��� ����(�Լ� ����)
				3. common.h -> ����ü ����, �Լ� ����
*/

extern NODE* head;

int main(void)
{
	// ��� ���� �˰���
	printf("-����-\n");

	insert_front(10); // ������ ���
	insert_front(20); // ���������� �ι�° ���
	insert_front(30); // ���������� ����° ���

	NODE* first = head;
	printf("%d ", first->key);

	NODE* second = first->next;
	printf("%d ", second->key);

	NODE* third = second->next;
	printf("%d\n", third->key);

	printf("\n");

	// ��� ���� �˰���
	printf("-����-\n");

	delete_front(); // ���� ���� ��带 ����
	printf("%d\n", head->key); // ù��° ��尡 �����Ǿ� �ι�° ��尡 ��µ�.

	printf("\n");

	// ������� ��� �˰���
	printf("-������� ���-\n");

	delete_front();
	delete_front(); // ���� ����Ʈ ������ ����

	for (int i = 10; i <= 100; i += 10)
	{
		insert_front(i); // ����Ʈ�� 100 ~ 10 ���� ����
	}

	print_list();

	printf("\n");

	// ����Ʈ�� Ư�� key ���� �ִ��� Ž���ϴ� �˰���
	int find_key = 0;

	printf("-Ž��-\n");

	printf("key �Է�: ");
	scanf_s("%d", &find_key);

	if (contains(find_key))
	{
		printf("TRUE\n");
	}
	else
	{
		printf("FALSE\n");
	}

	printf("\n");

	// ����Ʈ�� Ư�� key���� �����ϴ� �˰���
	int delete_key = 0;

	printf("-���� ����\n-");

	printf("key �Է�: ");
	scanf_s("%d", &delete_key);

	find_n_delete(delete_key);

	print_list();

	return 0;
}