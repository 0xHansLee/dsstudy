#include <iostream>
#include "ListBaseStack2.h"

void Stack::StackInit()
{
    this->head = NULL;
}

int Stack::IsEmpty()
{
    if(this->head == NULL)
        return TRUE;
    else
        return FALSE;    
}

void Stack::Push(Data data)     // New node is inserted into head. Head point new node.
{
    Node * newNode = new Node;

    newNode->data = data;
    newNode->next = this->head;

    this->head = newNode;
}

Data Stack::Pop()
{
    Data rdata;
    Node * rnode;

    if(this->IsEmpty())
    {
        std::cout << "Stack Memory Error!" << std::endl;
        exit(-1);
    }

    rdata = this->head->data;
    rnode = this->head;

    this->head = this->head->next;
    delete rnode;
    return rdata;    
}

Data Stack::Peek()
{
    if(this->IsEmpty())
    {
        std::cout << "Stack Memory Error!" << std::endl;
        exit(-1);
    }

    return this->head->data;
}