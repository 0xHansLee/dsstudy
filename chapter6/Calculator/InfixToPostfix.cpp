#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#include "../ListBaseStack.h"

int GetOpPrec(char op)
{
    switch(op)
    {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }
    return -1;
}

int WhichPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec > op2Prec)
        return 1;
    else if(op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

void ConvToRPNExp(char exp[])
{
    Stack opStack;
    int expLen = strlen(exp);
    char * convExp = new char[expLen+1]; // +1한 이유?

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char)*(expLen+1));
    opStack.StackInit();

    for(i=0; i<expLen; i++)
    {
        tok = exp[i];       // get char from exp
        if(isdigit(tok))
        {
            convExp[idx++] = tok;
        }
        else
        {
            switch(tok)
            {
                case '(':
                    opStack.Push(tok);
                    break;

                case ')':
                    while(1)
                    {
                        popOp = opStack.Pop();
                        if(popOp == '(')
                            break;
                        convExp[idx++] = popOp;
                    }
                    break;

                case '+': case '-':
                case '*': case '/':
                    while( (!opStack.IsEmpty()) && (WhichPrecOp(opStack.Peek(), tok) >=0) ) // stack에 쌓여있고 && stack에 있는 operator가 더 크다면 stack에서 꺼내서 convExp에 다 넣음
                        convExp[idx++] = opStack.Pop();

                    opStack.Push(tok);
                    break;
            }
        }
    }

    while(!opStack.IsEmpty())
        convExp[idx++] = opStack.Pop(); // stack에 남아있는거 모두 이동

    strcpy(exp, convExp);
    delete[] convExp;       // char array delete
}