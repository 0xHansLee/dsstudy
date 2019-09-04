#include <iostream>
#include "ListBaseQueue.h"

void LQueue::Init()
{
    this->front = NULL;
    this->rear = NULL;
}

int LQueue::IsEmpty()
{
    if(this->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void LQueue::Enqueue(Data data)
{
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if(this->IsEmpty())
    {
        this->front = newNode;
        this->rear = newNode;
    }
    else
    {
        this->rear->next = newNode;
        this->rear = newNode;
    }
    
}

Data LQueue::Dequeue()
{
    Node * delNode;
    Data retData;

    if(this->IsEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        exit(-1);
    }

    delNode = this->front;
    retData = this->front->data;
    this->front = this->front->next;

    delete delNode;
    return retData;
}

Data LQueue::Peek()
{
    if(this->IsEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        exit(-1);
    }
    
    return this->front->data;
}