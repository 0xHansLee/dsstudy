#include <iostream>
#include <cstring>
#include "CLinkedList.h"
 
void Employee::SetEmployee(int number, const char* name)
{
    this->number = number;
    strcpy(this->name, name);
}

void CList::Init()
{
    this->tail = NULL;
    this->cur = NULL;
    this->before = NULL;
    this->numOfData = 0;
}

void CList::Insert(Data data)
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
    Node * rpos = new Node;
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

int CList::SearchDuty(const char * name, int day)
{
    Data pdata;
    if(this->tail == NULL)
    {
        return FALSE;
    }

    if(this->LFirst(&pdata))
    {
        if((strcmp(pdata.name, name) == 0))
        {
            for(int i=0; i<day; i++)
            {
                this->LNext(&pdata);
            }
            std::cout << pdata.name << " will work for duty!" << std::endl;
            return TRUE;
        }

        while( this->LNext(&pdata) )
        {
            if(strcmp(pdata.name, name) == 0)
            {
                for(int i=0; i<day; i++)
                {
                    this->LNext(&pdata);
                }
                std::cout << pdata.name << " will work for duty!!" << std::endl;
                return TRUE;
                break;
            }
            else if (this->cur == this->tail)
            {
                
                std::cout << "There is no worker under " << name << std::endl;
                return FALSE;
                break;
            }
            
        }
        // return TRUE;
    }
    // else
    // {
        
    //     return FALSE;
    // }
    
}