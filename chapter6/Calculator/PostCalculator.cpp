#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
#include "../ListBaseStack.h"

int CalculRPNExp(char exp[]) // char, 즉 ASCII를 input으로 받아 그 ASCII값의 integer를 output으로 뱉는 함수
{
    Stack digitStack;
    int expLen = strlen(exp);

    int i, res;
    char tok, num1, num2;

    digitStack.StackInit();

    for(i=0; i<expLen; i++)
    {
        tok = exp[i];

        if(isdigit(tok))
        {
            digitStack.Push(tok-'0'); // why -'0'? => In ASCII code, difference with '0' means the number 0~9
        }
        else
        {
            num2 = digitStack.Pop();
            num1 = digitStack.Pop();

            switch(tok)
            {
                case '+':
                    digitStack.Push(num1 + num2);   // ASCII 값으로 계산
                    break;
                case '-':
                    digitStack.Push(num1 - num2);
                    break;
                case '*':
                    digitStack.Push(num1 * num2);
                    break;
                case '/':
                    digitStack.Push(num1 / num2);
                    break;
            }
        }
    }
    return digitStack.Pop();
}
