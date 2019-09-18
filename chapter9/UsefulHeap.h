#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE        1
#define FALSE       0

#define HEAP_LEN    100

typedef char HData;
typedef int (*PriorityComp)(HData d1, HData d2);

class Heap
{
    public:
        PriorityComp comp;
        int numOfData;
        HData heapArr[HEAP_LEN];

        void Init(PriorityComp pc);
        int IsEmpty();

        int GetHiPriChildIDX(int idx);

        void Insert(HData data);
        HData Delete();
};

#endif