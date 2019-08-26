#ifndef __CLL_STACK_H__
#define __CLL_STACK_H__

#define TRUE    1
#define FALSE   0

typedef int Data;

class Node
{
    public:
        Data data;
        Node * next;
};

class CList
{
    public:
        Node * tail;
        Node * cur;
        Node * before;
        int numOfData;

        void Init();
        void Insert(Data data);
        void InsertHead(Data data);

        int LFirst(Data * pdata);
        int LNext(Data * pdata);
        Data LRemove();
        int LCount();

        // for stack
        int IsEmpty();
        void Push(Data data);
        Data Pop();
        Data Peek();
};

typedef CList Stack;

#endif