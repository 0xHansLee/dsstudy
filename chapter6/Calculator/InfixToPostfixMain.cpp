#include <iostream>
#include "InfixToPostfix.h"

int main(void)
{
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";

    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);

    std::cout << "exp1 = " << exp1 << std::endl;
    std::cout << "exp2 = " << exp2 << std::endl;
    std::cout << "exp3 = " << exp3 << std::endl;

    return 0;
}