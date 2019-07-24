#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
    if(num==1)
    {
        printf("원반 1을 %c 에서 %c 로 이동 \n", from, to);
    }
    else
    {
        HanoiTowerMove(num-1,from,to,by);
        printf("원반 %d(을)를 %c 에서 %c 로 이동 \n",num,from,to);
        HanoiTowerMove(num-1,by,from,to);
    }
}

int main(void)
{
    HanoiTowerMove(10,'A','B','C');
    return 0;
}