#include <iostream>
#include <string>

#include "PriorityQueue.h"

int StrPriorityComp(std::string s1, std::string s2)
{
    return s2.length()-s1.length();
}

int main(void)
{
    PQueue pq;
    pq.Init(StrPriorityComp);

    pq.Enqueue("Good morning");
    pq.Enqueue("I am a boy");
    pq.Enqueue("Priority Queue");
    pq.Enqueue("Do you like coffee");
    pq.Enqueue("I am so happy");

    while(!pq.IsEmpty())
        std::cout << pq.Dequeue() << std::endl;

    return 0;
}