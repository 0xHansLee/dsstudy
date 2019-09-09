#include <iostream>
#include "BinaryTree.h"

BTNode * BTNode::MakeBTreeNode(BTData data)
{
    BTNode * newNode = new BTNode;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BTData BTNode::GetData()
{
    return this->data;
}

BTNode * BTNode::GetLeftSubTree()
{
    return this->left;
}

BTNode * BTNode::GetRightSubTree()
{
    return this->right;
}

void BTNode::MakeLeftSubTree(BTNode * sub)
{
    if(this->left != NULL)
        delete this->left;

    this->left = sub;
}

void BTNode::MakeRightSubTree(BTNode * sub)
{
    if(this->right != NULL)
        delete this->right;

    this->right = sub;
}

void BTNode::PreorderTraverse(VisitFuncPtr action)     // VisitFuncPtr 타입인 action은 BTData를 매개변수로 가짐
{
    if(this == NULL)
        return;

    action(this->data);
    this->left->PreorderTraverse(action);
    this->right->PreorderTraverse(action);
}

void BTNode::InorderTraverse(VisitFuncPtr action)
{
    if(this == NULL)
        return;

    this->left->InorderTraverse(action);
    action(this->data);
    this->right->InorderTraverse(action);
}

void BTNode::PostorderTraverse(VisitFuncPtr action)
{
    if(this == NULL)
        return;

    this->left->PostorderTraverse(action);
    this->right->PostorderTraverse(action);
    action(this->data);
}