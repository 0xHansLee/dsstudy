#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE        1
#define FALSE       0
#define STACK_LEN   100

typedef int Data;

class ArrayStack
{
    public:
        Data stackArr[STACK_LEN];
        int topIndex;

        void StackInit();
        int SIsEmpty();

        void SPush(Data data);
        Data SPop();
        Data SPeek();
};

typedef ArrayStack Stack;

#endif