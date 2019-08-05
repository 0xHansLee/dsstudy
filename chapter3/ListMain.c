#include <stdio.h>
#include "ArrayList.h"
#include "ArrayList.c"

int main(void)
{
    // ArrayList의 생성 및 초기화
    List list;
    int data;
    int sum = 0;    
    ListInit(&list);

    // 5개의 데이터 저장
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);
    LInsert(&list, 9);

    // 저장된 데이터의 전체 출력

    if(LFirst(&list, &data))
    {
        sum = sum + data;
        while(LNext(&list, &data))
            sum = sum + data;
    }
    printf("(2) List의 총 합은 : %d \n", sum);

    // 숫자 22을 탐색하여 모두 삭제
    if(LFirst(&list, &data))
    {
        if((data%2 == 0) || (data%3 == 0))
            LRemove(&list);

        while(LNext(&list, &data))
        {
            if((data%2 == 0) || (data%3 == 0))
                LRemove(&list);
        }
    }

    if(LFirst(&list, &data))
    {
        printf("(3) 2의 배수와 3의 배수를 제거한 후 : %d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n");
    return 0;
}