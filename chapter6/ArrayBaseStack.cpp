#include <iostream>
#include "ArrayBaseStack.h"

void ArrayStack::StackInit()
{
    this->topIndex = -1;
}

int ArrayStack::SIsEmpty()
{
    if(this->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void ArrayStack::SPush(Data data)
{
    this->topIndex += 1;
    this->stackArr[this->topIndex] = data;
}

Data ArrayStack::SPop()
{
    int rIdx;
    Data tmp1;

    if(this->SIsEmpty())
    {
        std::cout << "Stack Memory Error";
        exit(-1);
    }

    rIdx = this->topIndex;
    // this->stackArr[rIdx] = NULL;
    // tmp1 =  this->stackArr[rIdx];
    // this->stackArr[rIdx] = NULL;
    this->topIndex -= 1;

    return this->stackArr[rIdx];
}

Data ArrayStack::SPeek()
{
    if(this->SIsEmpty())
    {
        std::cout << "Stack Memory Error";
        exit(-1);
    }

    return this->stackArr[this->topIndex];
}