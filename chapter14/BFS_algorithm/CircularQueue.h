#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE        1
#define FALSE       0

#define QUE_LEN     30
typedef int Data;

class CQueue{
    public:
        int front;
        int rear;
        Data queArr[QUE_LEN];

        void Init();
        int IsEmpty();

        void Enqueue(Data data);
        Data Dequeue();
        Data Peek();
};

typedef CQueue Queue;

#endif