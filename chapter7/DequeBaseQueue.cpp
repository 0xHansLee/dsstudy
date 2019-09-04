#include <iostream>
#include "DequeBaseQueue.h"

void Queue::DInit()     // 부모클래스 Deque와 함수명이 같으면 안됨!
{
    this->Init();
}

int Queue::DIsEmpty()
{
    this->IsEmpty();
}

void Queue::DEnqueue(Data data)
{
    this->AddLast(data);
}

Data Queue::DDequeue()
{
    return this->RemoveFirst();
}

Data Queue::DPeek()
{
    return this->GetFirst();
}