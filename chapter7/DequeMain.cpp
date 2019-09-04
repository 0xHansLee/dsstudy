#include <iostream>
#include "Deque.h"

int main(void)
{
    Deque deque;
    deque.Init();

    deque.AddFirst(3);
    deque.AddFirst(2);
    deque.AddFirst(1);

    deque.AddLast(4);
    deque.AddLast(5);
    deque.AddLast(6);

    // std::cout << deque.GetLast();

    while(!deque.IsEmpty())
        std::cout << deque.RemoveFirst() << " ";

    std::cout << std::endl;

    deque.AddFirst(3);
    deque.AddFirst(2);
    deque.AddFirst(1);

    deque.AddLast(4);
    deque.AddLast(5);
    deque.AddLast(6);

    while(!deque.IsEmpty())
        std::cout << deque.RemoveLast() << " ";

    return 0;
}