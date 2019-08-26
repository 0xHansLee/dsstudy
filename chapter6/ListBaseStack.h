#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE        1
#define FALSE       0

typedef int Data;

class Node
{
    public:
        Data data;
        Node * next;
};

class ListStack
{
    public:
        Node * head;

        void StackInit();
        int IsEmpty();

        void Push(Data data);
        Data Pop();
        Data Peek();
};

typedef ListStack Stack;

#endif