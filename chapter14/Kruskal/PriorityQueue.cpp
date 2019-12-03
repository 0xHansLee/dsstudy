#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueue::PQInit(PriorityComp pc)
{
    this->Init(pc);
}

int PQueue::PQIsEmpty()
{
    return this->IsEmpty();
}

void PQueue::Enqueue(PQData data)
{
    this->Insert(data);
}

PQData PQueue::Dequeue()
{
    return this->Delete();
}