#include <iostream>
#include "CircularQueue.h"

void CQueue::Init()
{
    this->front = 0;
    this->rear = 0;
}

int CQueue::IsEmpty()
{
    if(this->front == this->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)     // next index in circular array
{
    if(pos == QUE_LEN-1)
        return 0;
    else
        return pos+1;
}

void CQueue::Enqueue(cData data)
{
    if(NextPosIdx(this->rear) == this->front)       
    {
        std::cout << "Queue Memory is Full!" << std::endl;
        exit(-1);
    }

    this->rear = NextPosIdx(this->rear);
    this->queArr[this->rear] = data;
}

cData CQueue::Dequeue()      // array에는 데이터가 남아있음.
{
    if(this->IsEmpty())
    {
        std::cout << "This queue is empty" << std::endl;
        exit(-1);
    }

    this->front = NextPosIdx(this->front);
    return this->queArr[this->front];
}

cData CQueue::Peek()
{
    if(this->IsEmpty())
    {
        std::cout << "This queue is empty" << std::endl;
        exit(-1);
    }

    return this->queArr[NextPosIdx(this->front)];
}