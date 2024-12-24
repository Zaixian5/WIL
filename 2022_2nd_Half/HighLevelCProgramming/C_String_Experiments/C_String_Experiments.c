#include <stdio.h>

int main(void)
{
	// 아래는 문자열과 문자열 배열을 실험해 보면서 알게된 사실들임. 정확한 개념은 아닐 수 있다.

	char str1[3][10] =
	{
		"HELLO",
		"WORLD",
		"BABY"
	}; // 글자수가 10(NULL문자 포함)인 문자열 3개를 저장하는 문자열 배열
	char* str2[3] =
	{
		"HELLO",
		"WORLD",
		"BABY"
	}; // 문자열 3개를 저장하는 문자열 배열

	// 전체출력
	for (int i = 0; i < 3; i++)
	{
		printf("%s ", str1[i]); // 문자열은 첫번째 글자를 가리키는 주소값으로 저장 된다. 
								// 2차원 배열 arr[][]에서 arr[]은 각 행의 첫번째 요소를 가리키는 포인터임을 이용한 원리(부분배열)
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s ", str2[i]);
	}
	printf("\n\n");

	// <c.f. 1>
	char str3[10] = "HELLO!"; // 글자 수 10(NULL문자 포함)의 문자열을 저장할 수 있는 문자열 변수
	printf("%s\n", str3);	  // 문자열 출력 방법이 이러한 이유:
							  // 배열의 이름은 배열의 첫번째 요소(문자열의 첫번째 글자)를 가리키는 포인터임을 이용한 원리
	printf("%s\n\n", &str3[3]);

	// 일부출력
	for (int i = 0; i < 3; i++)
	{
		printf("%s ", &str1[i][3]);
	}
	printf("\n\n"); // &str1[i][3]은 str1의 i번째 문자열 4번째 글자를 가리키는 포인터
					// 따라서 4번째 글자 부터 시작해서 출력된다.

	// <c.f. 2>
	for (int i = 0; i < 3; i++)
	{
		printf("%c ", str1[i][2]); // 문자하나만 출력하고 싶다면 %c를 쓰면 된다.
	}
	printf("\n\n");

	// 문자열 교체와 수정
	str1[2][3] = '?';
	for (int i = 0; i < 3; i++)
	{
		printf("%s ", str1[i]);
	}
	printf("\n"); // 변수형태의 문자열 배열

	str2[2] = "MI GENTE!";
	for (int i = 0; i < 3; i++)
	{
		printf("%s ", str2[i]);
	}
	printf("\n"); // 상수형태의 문자열 배열

	return 0;
}