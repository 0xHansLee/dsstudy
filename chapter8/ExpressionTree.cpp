#include <iostream>
#include <cstring>
#include "BinaryTree.h"
#include "ListBaseStack2.h"
#include "ExpressionTree.h"

void ShowNodeData(int data)
{
    if(data>=0 && data<=9)
        std::cout << data;
    else
        std::cout << (char)data;
}



BTNode * ExpTree::MakeExpTree(char exp[])
{
    BTNode * center;
    // BTNode * left;
    // BTNode * right;
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok;
    stack.StackInit();

    for(i=0; i<expLen; i++)
    {
        tok = exp[i];

        if(isdigit(tok))
        {
            // stack.Push(tok-'0');
            center = center->MakeBTreeNode(tok-'0');
            // stack.Push(center);
        }
        else
        {
            center = center->MakeBTreeNode(tok);
            // right = right->MakeBTreeNode(stack.Pop());
            // left = left->MakeBTreeNode(stack.Pop());

            // center->MakeRightSubTree(right);
            // center->MakeLeftSubTree(left);

            center->MakeRightSubTree(stack.Pop());
            center->MakeLeftSubTree(stack.Pop());

            // stack.Push(center);
        }
        stack.Push(center);
    }
    this->ExpBTNode = stack.Peek();
    return stack.Pop();
}

int ExpTree::EvaluateExpTree(BTNode * nodee)
{
    int op1, op2;
    // BTNode * nodee = this->ExpBTNode->GetLeftSubTree();

    if(nodee->GetLeftSubTree() == NULL && nodee->GetRightSubTree() == NULL)
        return nodee->GetData();

    op1 = this->EvaluateExpTree(nodee->GetLeftSubTree());// this->ExpBTNode->GetLeftSubTree->EvaluateExpTree();
    op2 = this->EvaluateExpTree(nodee->GetRightSubTree());// this->ExpBTNode->GetRightSubTree->EvaluateExpTree();
    // op1 = this->ExpBTNode->left

    switch(nodee->GetData())
    {
        case '+':
            return op1+op2;
        
        case '-':
            return op1-op2;
        
        case '*':
            return op1*op2;

        case '/':
            return op1/op2;
    }
    return 0;
}

void ExpTree::ShowPrefixTypeExp()
{
    this->ExpBTNode->PreorderTraverse(ShowNodeData);
}

void ExpTree::ShowInfixTypeExp()
{
    int tmp = this->ExpBTNode->GetData();

    // if(!(tmp>=0 && tmp<=9))
    //     std::cout << "(";

    this->ExpBTNode->InorderTraverse(ShowNodeData);

    // if(!(tmp>=0 && tmp<=9))
    //     std::cout << ")";
}

void ExpTree::ShowPostfixTypeExp()
{
    this->ExpBTNode->PostorderTraverse(ShowNodeData);
}