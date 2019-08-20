#include <iostream>
#include "DBLinkedList.h"

void DBLinkedList::Init()
{
    this->head = new Node;
    this->tail = new Node;
    this->numOfData = 0;

    this->head->next = this->tail;
    this->head->prev = NULL;
    this->tail->next = NULL;
    this->tail->prev = this->head;

    this->numOfData = 0;
}

void DBLinkedList::Insert(Data data)
{
    Node * newNode = new Node;
    newNode->data = data;

    newNode->prev = this->tail->prev;
    this->tail->prev->next = newNode;

    this->tail->prev = newNode;
    newNode->next = this->tail;
    
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
    if(this->cur->next->next == NULL)
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

    this->cur->prev->next = this->cur->next; // rpos->next 로 하면 에러남
    this->cur->next->prev = this->cur->prev;
    this->cur = this->cur->prev;

    delete rpos;

    (this->numOfData)--;

    return rdata;
}

int DBLinkedList::LCount()
{
    return this->numOfData;
}