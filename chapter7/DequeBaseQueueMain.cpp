#include <iostream>
#include "DequeBaseQueue.h"

int main(void)
{
    Queue dBQueue;
    dBQueue.Init();

    dBQueue.DEnqueue(1);
    dBQueue.DEnqueue(2);
    dBQueue.DEnqueue(3);
    dBQueue.DEnqueue(4);
    dBQueue.DEnqueue(5);

    while(!dBQueue.IsEmpty())
        std::cout << dBQueue.DDequeue() << " ";

    return 0;
}