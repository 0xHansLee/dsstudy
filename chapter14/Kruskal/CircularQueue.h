#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#include "ALEdge.h"

#define TRUE        1
#define FALSE       0

#define QUE_LEN     30
typedef Edge cData;

class CQueue{
    public:
        int front;
        int rear;
        cData queArr[QUE_LEN];

        void Init();
        int IsEmpty();

        void Enqueue(cData data);
        cData Dequeue();
        cData Peek();
};

typedef CQueue Queue;

#endif