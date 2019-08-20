#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0
 
typedef int Data;

class Node
{
    public:
        Data data;
        Node * next;
        Node * prev;
};

class DBLinkedList
{
    public:
        Node * head;
        Node * tail;
        Node * cur;
        int numOfData;

        void Init();
        void Insert(Data data); // insert data at tail

        int LFirst(Data * pdata);
        int LNext(Data * pdata);
        int LPrev(Data * pdata);
        Data LRemove();
        int LCount();
};

typedef DBLinkedList List;

#endif