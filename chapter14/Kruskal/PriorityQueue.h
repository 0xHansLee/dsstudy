#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"

// typedef Heap PQueue;
typedef HData PQData;

// class PQueue
// {
//     friend class Heap;
//     public:
//         void PQInit(Heap& heap, PriorityComp pc);
//         int PQIsEmpty(Heap& heap);

//         void Enqueue(Heap& heap, PQData data);
//         PQData Dequeue(Heap& heap);
// };

class PQueue : public Heap
{
    public:
        void PQInit(PriorityComp pc);
        int PQIsEmpty();

        void Enqueue(PQData data);
        PQData Dequeue();
};

#endif