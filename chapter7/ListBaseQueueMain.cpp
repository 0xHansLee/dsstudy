#include <iostream>
#include "ListBaseQueue.h"

int main(void)
{
    Queue q;
    q.Init();

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);

    while(!q.IsEmpty())
        std::cout << q.Dequeue() << " ";

    return 0;
}