#include <iostream>
#include "BinaryTree4.h"

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

void BTNode::DeleteTree(DeleteAct action)
{
    if(this == NULL)
        return;         
    this->left->DeleteTree(action);         
    this->right->DeleteTree(action);
    action(this);
}

BTNode * BTNode::RemoveLeftSubTree()
{
    BTNode * delNode;
    if(this != NULL)
    {
        delNode = this->left;
        this->left = NULL;
    }
    return delNode;
}

BTNode * BTNode::RemoveRightSubTree()
{
    BTNode * delNode;
    if(this != NULL)
    {
        delNode = this->right;
        this->right = NULL;
    }
    return delNode;
}

void BTNode::ChangeLeftSubTree(BTNode * sub)
{
    this->left = sub;
}

void BTNode::ChangeRightSubTree(BTNode * sub)
{
    this->right = sub;
}

BTNode * BTNode::RotateLL()
{
    BTNode * pNode = this;
    BTNode * cNode = this->left;

    pNode->ChangeLeftSubTree(cNode->right);
    cNode->ChangeRightSubTree(pNode);

    return cNode;
}

BTNode * BTNode::RotateRR()
{
    BTNode * pNode = this;
    BTNode * cNode = this->right;

    pNode->ChangeRightSubTree(cNode->left);
    cNode->ChangeLeftSubTree(pNode);

    return cNode;
}

BTNode * BTNode::RotateLR()
{
    // RR -> LL
    BTNode * pNode = this;
    BTNode * cNode = this->left;

    pNode->ChangeLeftSubTree(cNode->RotateRR());
    return pNode->RotateLL();
}

BTNode * BTNode::RotateRL()
{
    // LL->RR
    BTNode * pNode = this;
    BTNode * cNode = this->right;

    pNode->ChangeRightSubTree(cNode->RotateLL());
    return pNode->RotateRR();
}

int BTNode::GetHeight()
{
    if(this == NULL)
        return 0;

    int lDepth, rDepth;

    lDepth = this->left->GetHeight()+1;
    rDepth = this->right->GetHeight()+1;

    return (lDepth > rDepth) ? lDepth : rDepth;
}

int BTNode::GetHeightDiff()
{
    if(this == NULL)
        return 0;

    int leftHeight;
    int rightHeight;

    leftHeight = this->left->GetHeight();
    rightHeight = this->right->GetHeight();

    return leftHeight-rightHeight;
}
