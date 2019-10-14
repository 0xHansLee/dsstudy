#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define MAX_TBL     100

typedef int (*HashFunc)(Key k);

class Table
{
    public:
        Slot tbl[MAX_TBL];
        HashFunc hf;

        void TBLInit(HashFunc f);
        void TBLInsert(Key k, Value v);
        Value TBLDelete(Key k);
        Value TBLSearch(Key k);
};

#endif