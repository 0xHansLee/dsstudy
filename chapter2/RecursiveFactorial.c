#include <stdio.h>

int RecursiveFactorial(int num)
{
    // int res;
    if(num<=0)
    {
        return 1;
    }
    return num*RecursiveFactorial(num-1);
    // RecursiveFactorial(num-1);
    // return res;
}

int main(void)
{
    int i=3;
    int res = RecursiveFactorial(i);
    printf("%d ! = %d \n", i, res);
    return 0;
}