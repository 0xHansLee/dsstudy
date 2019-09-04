#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE        1
#define FALSE       0

typedef int Data;

class Node
{
    public:
        Data data;
        Node * next;
        Node * prev;
};

class DLDeque
{
    public:
        Node * head;
        Node * tail;

        void Init();
        int IsEmpty();
        void AddFirst(Data data);
        void AddLast(Data data);
        Data RemoveFirst();
        Data RemoveLast();
        Data GetFirst();
        Data GetLast();
};

typedef DLDeque Deque;

#endif