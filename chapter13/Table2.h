#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL     100

typedef int (*HashFunc)(Key k);

class Table
{
    public:
        List tbl[MAX_TBL];
        HashFunc hf;

        void Init(HashFunc f);
        void Insert(Key k, Value v);
        Value Delete(Key k);
        Value Search(Key k);
};

#endif