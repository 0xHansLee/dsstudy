#include <iostream>
#include "UsefulHeap.h"

int DataPriorityComp(char c1, char c2)
{
    return c1-c2;
}

int main(void)
{
    Heap heap;
    heap.Init(DataPriorityComp);

    heap.Insert('A');
    heap.Insert('B');
    heap.Insert('C');

    std::cout << heap.Delete() << std::endl;

    heap.Insert('A');
    heap.Insert('B');
    heap.Insert('C');

    std::cout << heap.Delete() << std::endl;

    while(!heap.IsEmpty())
        std::cout << heap.Delete() << " ";

    return 0;
}