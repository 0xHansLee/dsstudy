#include <iostream>
#include <cstring>
#include "CLinkedListStack.h"

void CList::Init()
{
    this->tail = NULL;
    this->cur = NULL;
    this->before = NULL;
    this->numOfData = 0;
}

void CList::Insert(Data data) // insert at tail (No before)
{
    Node * newNode = new Node;
    newNode->data = data;

    if(this->tail == NULL)
    {
        this->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = this->tail->next;
        this->tail->next = newNode;
        this->tail = newNode;
    }
    (this->numOfData)++;
}

void CList::InsertHead(Data data)
{
    Node * newNode = new Node;
    newNode->data = data;

    if(this->tail == NULL)
    {
        this->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = this->tail->next;
        this->tail->next = newNode;
    }
    (this->numOfData)++;
}

int CList::LFirst(Data * pdata)
{
    if(this->tail == NULL)
    {
        return FALSE;
    }

    this->before = this->tail;
    this->cur = this->tail->next;

    *pdata = this->cur->data;
    return TRUE;
}

int CList::LNext(Data * pdata)
{
    if(this->tail == NULL)
    {
        return FALSE;
    }

    this->before = this->cur;
    this->cur = this->cur->next;

    *pdata = this->cur->data;
    return TRUE;
}

Data CList::LRemove()
{
    Node * rpos = this->cur;
    Data rdata = rpos->data;

    if(rpos == this->tail)
    {
        if(this->tail == this->tail->next)
        {
            this->tail = NULL;
        }
        else
        {
            this->tail = this->before;
        }
    }

    this->before->next = this->cur->next;
    this->cur = this->before;

    delete rpos;
    (this->numOfData)--;
    return rdata;
}

int CList::LCount()
{
    return this->numOfData;
}

// --------------------------------- for stack --------------------------------------
int CList::IsEmpty()
{
    if(this->numOfData == 0)
        return TRUE;
    else
        return FALSE;
    
}

void CList::Push(Data data)
{
    this->InsertHead(data);
}

Data CList::Pop()
{
    Data rdata;
    this->LFirst(&rdata);
    // this->cur = this->tail;
    // rdata = this->LRemove();
    this->LRemove();

    return rdata;
}

Data CList::Peek()
{
    this->cur = this->tail;
    return this->cur->data;
}


