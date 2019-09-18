#include <iostream>
#include "SimpleHeap.h"

int main(void)
{
    Heap heap;
    heap.Init();

    heap.Insert('A', 1);
    heap.Insert('B', 2);
    heap.Insert('C', 3);

    std::cout << heap.Delete() << std::endl;

    heap.Insert('A', 1);
    heap.Insert('B', 2);
    heap.Insert('C', 3);

    std::cout << heap.Delete() << std::endl;

    while(!heap.IsEmpty())
        std::cout << heap.Delete() << std::endl;

    return 0;
}