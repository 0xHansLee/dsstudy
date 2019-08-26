#include <iostream>
#include "ArrayBaseStack.cpp"

int main(void)
{
    Stack stack;
    stack.StackInit();

    stack.SPush(1);
    stack.SPush(2);
    stack.SPush(3);
    stack.SPush(4);
    stack.SPush(5);

    // while(!stack.SIsEmpty())
    //     std::cout << stack.SPop() << " ";

    std::cout << stack.SPop() << std::endl;
    std::cout << stack.stackArr[stack.topIndex+1] << std::endl;

    std::cout << stack.SPop() << std::endl;
    std::cout << stack.stackArr[stack.topIndex+2] << std::endl;     // The data isn't deleted     
    
    return 0;

}