#include <iostream>
#include "BinaryTree3.h"

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

void BTNode::PreorderTraverse(VisitFuncPtr action)     
{
    if(this == NULL)
    {
        return;
    }

    action(this->data);
    this->left->PreorderTraverse(action);
    this->right->PreorderTraverse(action);
}

void BTNode::InorderTraverse(VisitFuncPtr action)
{
    if(this == NULL)
        return;

    if(!(this->GetData() >= 0 && this->GetData() <= 9))
    {
        std::cout << "(";
    }
    this->left->InorderTraverse(action);
    action(this->data);
    this->right->InorderTraverse(action);
    if(!(this->GetData() >= 0 && this->GetData() <= 9))
    {
        std::cout << ")";
    }
}

void BTNode::PostorderTraverse(VisitFuncPtr action)
{
    if(this == NULL)
        return;

    this->left->PostorderTraverse(action);
    this->right->PostorderTraverse(action);
    action(this->data);
}

void BTNode::DeleteTree(DeleteAct action)
{
    if(this == NULL)
        return;         
    this->left->DeleteTree(action);         
    this->right->DeleteTree(action);
    action(this);
}

BTNode * RemoveLeftSubTree(BTNode * pNode)
{
    BTNode * delNode;
    if(pNode != NULL)
    {
        delNode = pNode->left;
        pNode->left = NULL;
    }
    return delNode;
}

BTNode * RemoveRightSubTree(BTNode * pNode)
{
    BTNode * delNode;
    if(pNode != NULL)
    {
        delNode = pNode->right;
        pNode->right = NULL;
    }
    return delNode;
}

void ChangeLeftSubTree(BTNode * pNode, BTNode * sub)
{
    pNode->left = sub;
}

void ChangeRightSubTree(BTNode * pNode, BTNode * sub)
{
    pNode->right = sub;
}
