#include <stdio.h>

void concat_func(char[], char[]);

int main(void)
{
	char str1[100],str2[100];

	printf("Enter First String: ");
	scanf("%s", str1);

	printf("Enter Second String: ");
	scanf("%s", str2);

	concat_func(str1, str2);
	printf("Concatenated String: %s\n",str1);

	return 0;
}
