#include <stdio.h>

#include "common.h"

/*
	<연결리스트>

	-정의: 포인터와 동적할당을 이용해 자료를 유연하게 저장하고 관리하는 알고리즘
	-개념:
			1. 자료를 저장하는 공간을 노드(Node)라 칭하고 이를 구조체로 구현한다.
			2. 각각의 노드는 자료가 저장되어 있는 변수 key와 다음 노드를 가리키는 포인터 변수 next로 구성된다.
			3. 마지막 노드의 next는 NULL이 된다. 즉, 노드 구조체가 NULL을 만날 때까지 계속해서 같은 구조체를 가리키는 방식으로 구현.
			4. 구조체의 주소 값을 이용해야 하므로 동적할당을 사용한다.
			5. 여러 알고리즘 중 여기선 첫번째 노드를 가리키는 포인터 head를 이용하여 앞에서 부터 삽입하고 삭제되는 알고리즘을 구현하였다.
	-예시:
			head -> 30(첫 노드) -> 20(두번째 노드) -> 10(마지막 노드) -> NULL

	-파일분할:
				1. main.c -> 알고리즘 동작 확인
				2. function.c -> 알고리즘 구현(함수 정의)
				3. common.h -> 구조체 정의, 함수 선언
*/

extern NODE* head;

int main(void)
{
	// 노드 삽입 알고리즘
	printf("-삽입-\n");

	insert_front(10); // 마지막 노드
	insert_front(20); // 마지막에서 두번째 노드
	insert_front(30); // 마지막에서 세번째 노드

	NODE* first = head;
	printf("%d ", first->key);

	NODE* second = first->next;
	printf("%d ", second->key);

	NODE* third = second->next;
	printf("%d\n", third->key);

	printf("\n");

	// 노드 삭제 알고리즘
	printf("-삭제-\n");

	delete_front(); // 가장 앞의 노드를 삭제
	printf("%d\n", head->key); // 첫번째 노드가 삭제되어 두번째 노드가 출력됨.

	printf("\n");

	// 순서대로 출력 알고리즘
	printf("-순서대로 출력-\n");

	delete_front();
	delete_front(); // 기존 리스트 내용을 지움

	for (int i = 10; i <= 100; i += 10)
	{
		insert_front(i); // 리스트에 100 ~ 10 까지 저장
	}

	print_list();

	printf("\n");

	// 리스트에 특정 key 값이 있는지 탐색하는 알고리즘
	int find_key = 0;

	printf("-탐색-\n");

	printf("key 입력: ");
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

	// 리스트의 특정 key값만 삭제하는 알고리즘
	int delete_key = 0;

	printf("-선택 삭제\n-");

	printf("key 입력: ");
	scanf_s("%d", &delete_key);

	find_n_delete(delete_key);

	print_list();

	return 0;
}