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
    {
        // std::cout << "Empty!" << std::endl;
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

// void BTNode::DeleteTree()
// {
//     BTNode * rLeft = new BTNode;
//     BTNode * rRight = new BTNode;
//     BTNode * rCenter = new BTNode;

//     rLeft = this->GetLeftSubTree();
//     rRight = this->GetRightSubTree();
//     rCenter = this;

//     if(rLeft->left != NULL)
//         rLeft->left->DeleteTree();

//     if(rRight->right != NULL)
//         rRight->right->DeleteTree();

//     delete rCenter;
// }

void BTNode::DeleteTree(DeleteAct action)
{
    if(this == NULL)
        return;         // terminal node만났을 때 return하면 deleteTree바깥으로 빠져나오는건 아닌지?

    this->left->DeleteTree(action);         
    // std::cout << "free memory " << this->data <<std::endl;
    this->right->DeleteTree(action);
    action(this);
    // std::cout << "free memory" << std::endl;
}
