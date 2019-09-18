#include <iostream>
// #include "UsefulHeap.h"
#include "PriorityQueue.h"

int DataPriorityComp(char c1, char c2)
{
    return c2-c1;
}

int main(void)
{
    PQueue pq;
    pq.PQInit(DataPriorityComp);

    pq.Enqueue('A');
    pq.Enqueue('B');
    pq.Enqueue('C');

    std::cout << pq.Dequeue() << std::endl;

    pq.Enqueue('A');
    pq.Enqueue('B');
    pq.Enqueue('C');

    std::cout << pq.Dequeue() << std::endl;

    while(!pq.PQIsEmpty())
        std::cout << pq.Dequeue() << std::endl;

    return 0;  
}