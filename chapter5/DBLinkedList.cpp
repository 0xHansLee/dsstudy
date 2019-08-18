#include <iostream>
#include "DBLinkedList.h"

void DBLinkedList::Init()
{
    this->head = new Node;
    this->tail = new Node;
    this->numOfData = 0;

    head->next = this->tail;
    head->prev = NULL;
    tail->next = NULL;
    tail->prev = this->head;
}

void DBLinkedList::Insert(Data data)
{
    Node * newNode = new Node;
    newNode->data = data;

    newNode->next = this->tail;
    newNode->prev = this->tail->prev;
    this->tail->prev = newNode;
    this->tail->prev->next = newNode;

    (this->numOfData)++;
}

int DBLinkedList::LFirst(Data * pdata)
{
    if(this->head->next == NULL)
        return FALSE;

    this->cur = this->head->next;
    *pdata = this->cur->data;

    return TRUE;
}

int DBLinkedList::LNext(Data * pdata)
{
    if(this->cur->next == NULL)
        return FALSE;

    this->cur = this->cur->next;
    *pdata = this->cur->data;

    return TRUE;
}

int DBLinkedList::LPrev(Data * pdata)
{
    if(this->cur->prev == NULL)
        return FALSE;

    this->cur = this->cur->prev;
    *pdata = this->cur->data;

    return TRUE;
}

Data DBLinkedList::LRemove()
{
    Node * rpos = this->cur;
    Data rdata;
    
    if(this->cur->prev == this->head)
        std::cout << "No data to remove" << std::endl;

    rdata = this->cur->data;
    this->cur->prev->next = this->cur->next;
    this->cur->next->prev = this->cur->prev;

    delete rpos;
    (this->numOfData)--;

    return rdata;
}

int DBLinkedList::LCount()
{
    return this->numOfData;
}