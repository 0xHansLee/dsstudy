#include <iostream>
#include <string.h>
#include "PostCalculator.h"

int main(void)
{
    char postExp1[] = "42*8+";
    char postExp2[] = "123+*4/";

    std::cout << postExp1 << " = " << CalculRPNExp(postExp1) << std::endl;
    std::cout << postExp2 << " = " << CalculRPNExp(postExp2) << std::endl;

    // char a, b;
    // a = '1'-'0';
    // b = '2'-'0';
    // char c = a+b;
    // std::cout << a-b;
    return 0;
}