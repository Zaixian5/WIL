#include <stdio.h>

int main()
{
    char name1, name2, name3;
    int age;
    int studentnumber;
    int phonenumber;
    double weight;
    double sight;
    double height;
    int family;
    int birthday1, birthday2;
    int favoritenumber;
    int pet;
    double score;

    printf("영문이름 이니셜 세글자를 입력하세요. ");
    scanf(" %c %c %c", &name1, &name2, &name3);

    printf("나이를 입력하세요. ");
    scanf("%d", &age);

    printf("학번을 입력하세요. ");
    scanf("%d", &studentnumber);

    printf("전화번호 뒷자리를 입력하세요. ");
    scanf("%d", &phonenumber);

    printf("몸무게를 입력하세요. ");
    scanf("%lf", &weight);

    printf ("시력을 입력하세요. ");
    scanf("%lf", &sight);

    printf("키를 입력하세요. ");
    scanf("%lf", &height);

    printf("가족 구성원 수를 입력하세요. ");
    scanf("%d", &family);

    printf("생일을 입력하세요(월 일 순으로 쓰세요). ");
    scanf("%d %d", &birthday1, &birthday2);

    printf("좋아하는 숫자는 무엇인가요?(자연수로 써주세요) ");
    scanf("%d", &favoritenumber);

    printf("애완동물을 키우시나요? 키우신다면 몇마리를 키우시나요?(안 키우신다면 0을 입력하세요.) ");
    scanf("%d", &pet);

    printf("학교생활의 만족도가 어떻게 되세요? 100점 만점에 몇점인가요? ");
    scanf("%lf", &score);

    printf("\n안녕하세요.\n");
    printf("제 이름은 %c%c%c 입니다.\n", name1, name2, name3);
    printf("저는 올해 %d살 입니다.\n", age);
    printf("제 학번은 %d입니다.\n", studentnumber);
    printf("제 전화번호 뒷자리는 %d입니다.\n", phonenumber);
    printf("제 몸무게는 %.1fkg입니다.\n", weight);
    printf("제 시력은 %.3f입니다.\n", sight);
    printf("제 키는 %.1fcm입니다.\n", height);
    printf("저희 가족은 %d명 으로 구성되어 있습니다.\n", family);
    printf("제 생일은 %d월 %d일 입니다.\n", birthday1, birthday2);
    printf("제가 가장 좋아하는 숫자는 %d입니다.\n", favoritenumber);
    printf("저는 %d명의 애완동물을 키우고 있습니다.\n", pet);
    printf("저의 학교생활 만족도는 100점 만점에 %.2f점 입니다.\n감사합니다.\n", score);

    return 0;

}
