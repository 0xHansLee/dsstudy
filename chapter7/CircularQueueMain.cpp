#include <iostream>
#include "CircularQueue.h"

int main(void)
{
    Queue q;
    q.Init();

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    // std::cout << q.Peek() << std::endl;
    q.Enqueue(6);
    q.Dequeue();
    q.Dequeue();
    q.Enqueue(10);
    q.Enqueue(11);

    while(!q.IsEmpty())
        std::cout << q.Dequeue() << " ";
    
    return 0;
}