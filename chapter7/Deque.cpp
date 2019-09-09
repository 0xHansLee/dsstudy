#include <iostream>
#include "Deque.h"

void DLDeque::Init()
{
    this->head = NULL;
    this->tail = NULL;
}

int DLDeque::IsEmpty()
{
    if(this->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DLDeque::AddFirst(Data data)
{
    Node * newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(this->IsEmpty())
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->head->prev = newNode;
        newNode->next = this->head;
        this->head = newNode;
    }
}

void DLDeque::AddLast(Data data)
{
    Node * newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(this->IsEmpty())
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
    }
}

Data DLDeque::RemoveFirst()
{
    if(this->IsEmpty())
    {
        std::cout << "Empty Queue!" << std::endl;
        exit(-1);
    }
    else
    {
        Node * rNode;
        Data rdata;

        rNode = this->head;
        rdata = this->head->data;
        if(this->head == this->tail)        // head와 tail이 같을 때 -> 마지막 데이터 꺼낼 때
        {
            this->Init();
        }
        else
        {
            this->head->next->prev = NULL;      // prev를 NULL로 지정 안해줘도 delete하면 그냥 null값을 갖게되는지?
            this->head = this->head->next;
        }

        delete rNode;
        return rdata;
    }
}

Data DLDeque::RemoveLast()
{
    if(this->IsEmpty())
    {
        std::cout << "Empty Queue!" << std::endl;
        exit(-1);
    }
    else
    {
        Node * rNode;
        Data rdata;

        rdata = this->tail->data;
        rNode = this->tail;
        if(this->head == this->tail)        // head와 tail이 같을 때 -> 마지막 데이터 꺼낼 때
        {
            this->Init();
        }
        else
        {
            this->tail->prev->next = NULL;
            this->tail = this->tail->prev;
        }

        delete rNode;
        return rdata;
    }
}

Data DLDeque::GetFirst()
{
    return this->head->data;
}

Data DLDeque::GetLast()
{
    return this->tail->data;
}