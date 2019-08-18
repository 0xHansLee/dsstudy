#include <iostream>
#include "DLinkedList2.h"

void LinkedList::ListInit()
{
    this->head = new Node;
    this->head->next = NULL;
    this->comp = NULL;
    this->numofData = 0;
}

void LinkedList::LInsert(LData data)
{
    if(this->comp == NULL)
    {
        Node * newNode = new Node;
        newNode->data = data;
        newNode->next = this->head->next;
        this->head->next = newNode;
        (this->numofData)++;
        // void FInsert(LData data);
    }
    else
    {
        Node * newNode = new Node;
        Node * pred = this->head;
        newNode->data = data;
        while( (pred->next != NULL) && (this->comp(data,pred->next->data) != 0) )
        {
            pred = pred->next;
        }

        newNode->next = pred->next;
        pred->next = newNode;

        (this->numofData)++;
    }
}

int LinkedList::LFirst(LData * pdata)
{
    if(this->head->next == NULL)
        return FALSE;
    
    this->before = this->head;        // dummy
    this->cur = this->head->next;     // first node

    *pdata = this->cur->data;
    return TRUE;
}

int LinkedList::LNext(LData * pdata)
{
    if(this->cur->next == NULL)
        return FALSE;

    this->before = this->cur;
    this->cur = this->cur->next;

    *pdata = this->cur->data;
    return TRUE;
}

LData LinkedList::LRemove()
{
    Node * rpos = this->cur;
    LData rdata = rpos->data;

    this->before->next = this->cur->next;
    this->cur = this->before;

    delete rpos;
    (this->numofData)--;
    return rdata;
}

int LinkedList::LCount()
{
    return this->numofData;
}

void LinkedList::SetSortRule(int (*comp)(LData d1, LData d2))
{
    this->comp = comp;
}

// void LinkedList::FInsert(LData data)
// {
//     Node * newNode = new Node;
//     newNode->data = data;
//     newNode->next = head->next;
//     plist->head->next = newNode;
//     (plist->numofData)++;
// }

// void SInsert(LData data)
// {

// }