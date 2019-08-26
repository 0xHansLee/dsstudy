#include <iostream>
#include "CLinkedListStack.cpp"

int main(void)
{
    Stack stack;
    Data rr;
    stack.Init();

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);

    while(!stack.IsEmpty())
        std::cout << stack.Pop() << " ";
        
    return 0;
}