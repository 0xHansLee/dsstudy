#include <stdio.h>

int Fibonacci(int num)
{
    printf("func call %d \n", num);

    if(num==1)
        return 0;
    else if(num==2)
        return 1;
    else
        return Fibonacci(num-1)+Fibonacci(num-2);
}

int main(void)
{
    int n=7;
    int res = Fibonacci(n);
    // int i;
    // for(i=1;i<=n;i++)
    // {
    //     printf("%d ",Fibonacci(i));
    // }
    return 0;
}