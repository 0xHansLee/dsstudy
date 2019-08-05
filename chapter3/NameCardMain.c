#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "ArrayList.c"
#include "NameCard.h"
#include "NameCard.c"

int main(void)
{
    List list;
    NameCard * pnamecard;

    ListInit(&list);

    // (1)
    pnamecard = MakeNameCard("hansol", "000-0000-0000");
    LInsert(&list, pnamecard);
    pnamecard = MakeNameCard("yeonsu", "111-1111-1111");
    LInsert(&list, pnamecard);
    pnamecard = MakeNameCard("sewoong", "222-2222-2222");
    LInsert(&list, pnamecard);

    // (2)
    if(LFirst(&list, &pnamecard))
    {
        if(NameCompare(pnamecard, "hansol") == 0)
            ShowNameCardInfo(pnamecard);

        while(LNext(&list, &pnamecard))
        {
            if(NameCompare(pnamecard, "hansol") == 0)
                ShowNameCardInfo(pnamecard);
        }
    }

    // (3)
    if(LFirst(&list, &pnamecard))
    {
        if(NameCompare(pnamecard, "yeonsu") == 0)
            ChangePhoneNum(pnamecard, "333-3333-3333");

        while(LNext(&list, &pnamecard))
        {
            if(NameCompare(pnamecard, "yeonsu") == 0)
                ChangePhoneNum(pnamecard, "333-3333-3333");
        }
    }

    // (4)
    if(LFirst(&list, &pnamecard))
    {
        if(NameCompare(pnamecard, "sewoong") == 0)
        {
            pnamecard = LRemove(&list);
            free(pnamecard);
        }

        while(LNext(&list, &pnamecard))
        {
            if(NameCompare(pnamecard, "sewoong") == 0)
            {
                pnamecard = LRemove(&list);
                free(pnamecard);
            }
        }
    }

    // (5) 
    printf("남아있는 모든 사람의 정보 : \n");
    if(LFirst(&list, &pnamecard))
    {
        printf("%s \n", pnamecard->phone);

        while(LNext(&list, &pnamecard))
        {
            printf("%s \n", pnamecard->phone);
        }
    }
}