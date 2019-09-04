#ifndef __DB_QUEUE_H__
#define __DB_QUEUE_H__

#include "Deque.h"

class Queue : public DLDeque
{
    public:
        void DInit();
        int DIsEmpty();
        void DEnqueue(Data data);
        Data DDequeue();
        Data DPeek();
};

#endif