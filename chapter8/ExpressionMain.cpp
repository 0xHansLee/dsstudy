#include <iostream>
#include "ExpressionTree.cpp"
#include "BinaryTree.cpp"
#include "ListBaseStack2.cpp"

int main(void)
{
    char exp[] = "12+7*";
    ExpTree eTree;
    eTree.MakeExpTree(exp);

    std::cout << "Prefix Type Expression : ";
    eTree.ShowPrefixTypeExp();
    std::cout << std::endl;

    std::cout << "Infix Type Expression : ";
    eTree.ShowInfixTypeExp();
    std::cout << std::endl;

    std::cout << "Postfix Type Expression : ";
    eTree.ShowPostfixTypeExp();
    std::cout << std::endl;

    std::cout << eTree.EvaluateExpTree(eTree.ExpBTNode) << std::endl;

    return 0;
}