#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0
 
class Employee
{
    public:
        int number;
        char name[10];

        void SetEmployee(int number, const char* name);
};

typedef Employee Data;

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

        int SearchDuty(const char * name, int day);
};

#endif