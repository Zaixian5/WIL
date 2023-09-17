#include <stdio.h>
#include <string.h>

int main(void)
{
    char string1[20];
    int length;
    int flag;

    printf("Enter a string:");
    scanf("%s", string1);
    
    length = strlen(string1);
    
    for(int i = 0; i < length; i++)
    {
        if(string1[i] != string1[length-i-1])
	{
	    flag = 1;
	    break;
	}
    }

    if(flag)
    {
        printf("%s is not a palindrome", string1);
    }
    else
    {
        printf("%s is a palindrome", string1);
    }
    
    return 0;
}
