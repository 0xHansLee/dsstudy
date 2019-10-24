#include <iostream>
#include "Table2.h"
#include "DLinkedList.h"

void Table::Init(HashFunc f)
{
    int i;
    for(i=0; i<MAX_TBL; i++)
        tbl[i].ListInit();
    
    this->hf = f;
}

void Table::Insert(Key k, Value v)
{
    int hv = this->hf(k);
    Slot newSlot = {k, v};

    if(this->Search(k) != NULL)
    {
        std::cout << "Key collision" << std::endl;
        return;
    }
    else
    {
        this->tbl[hv].LInsert(newSlot);
    }
}

Value Table::Delete(Key k)
{
    int hv = this->hf(k);
    Slot dSlot;

    if(this->tbl[hv].LFirst(&dSlot))
    {
        if(dSlot.key == k)
        {
            this->tbl[hv].LRemove();
            return dSlot.val;
        }
        else
        {
            while(this->tbl[hv].LNext(&dSlot))
            {
                if(dSlot.key == k)
                {
                    this->tbl[hv].LRemove();
                    return dSlot.val;
                }
            }
        }
    }
    return NULL;
}

Value Table::Search(Key k)
{
    int hv = this->hf(k);
    Slot sSlot;

    if(this->tbl[hv].LFirst(&sSlot))
    {
        if(sSlot.key == k)
        {
            return sSlot.val;
        }
        else
        {
            while(this->tbl[hv].LNext(&sSlot))
            {
                if(sSlot.key == k)
                    return sSlot.val;
            }
        }
    }
    return NULL;
}
