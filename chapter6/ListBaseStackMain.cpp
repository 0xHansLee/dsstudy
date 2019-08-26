#include <iostream>
#include "ListBaseStack.cpp"

int main(void)
{
    Stack stack;
    stack.StackInit();

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);

    while(!stack.IsEmpty())
        std::cout << stack.Pop() << " ";

    return 0;
}