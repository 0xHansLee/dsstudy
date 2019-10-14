#include <iostream>
#include "Table.h"

void Table::TBLInit(HashFunc f)
{
    for(int i=0; i<MAX_TBL; i++)
        this->tbl[i].status = EMPTY;

    this->hf = f;    
}

void Table::TBLInsert(Key k, Value v)
{
    int hv = this->hf(k);
    if(this->tbl[hv].status == INUSE)
        std::cout << "Already filled under the key" << std::endl;
    
    else
    {    
        this->tbl[hv].val = v;
        this->tbl[hv].key = k;
        this->tbl[hv].status = INUSE;
    }
}

Value Table::TBLDelete(Key k)
{
    int hv = this->hf(k);
    if(this->tbl[hv].status != INUSE)
    {
        std::cout << "No data to delete" << std::endl;
        return NULL;
    }
    
    else
    {
        this->tbl[hv].status = DELETED;     // not actual deletion of value
        return this->tbl[hv].val;
    } 
}

Value Table::TBLSearch(Key k)
{
    int hv = this->hf(k);
    if(this->tbl[hv].status != INUSE)
        return NULL;

    else
        return this->tbl[hv].val;
}
