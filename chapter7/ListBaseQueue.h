#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE        1
#define FALSE       0

typedef int Data;

class Node
{
    public:
        Data data;
        Node * next;
};

class LQueue
{
    public:
        Node * front;
        Node * rear;

        void Init();
        int IsEmpty();

        void Enqueue(Data data);
        Data Dequeue();
        Data Peek();
};

typedef LQueue Queue;

#endif