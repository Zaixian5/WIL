#include <stdio.h>

int main()
{
    char gender;
    int age;

    scanf(" %c %d", &gender, &age);
    if(gender=='M'){
        if(age>=18){
            printf("MAN");
        }
        else{
            printf("BOY");
        }
    }
    if(gender=='F'){
        if(age>=18){
            printf("WOMAN");
        }
        else{
            printf("GIRL");
        }
    }
    return 0;
}
