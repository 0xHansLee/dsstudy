#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE        1
#define FALSE       0

#define HEAP_LEN    100

typedef char HData;
typedef int Priority;

class HeapElem
{
    public:
        Priority pr;
        HData data;
};

class Heap
{
    public:
        int numOfData;
        HeapElem heapArr[HEAP_LEN];

        void Init();
        int IsEmpty();

        void Insert(HData data, Priority pr);
        HData Delete();
};

#endif