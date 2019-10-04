#include <iostream>
#include "BinarySearchTree.h"

void BSTree::BSTMakeAndInit(BSTData rootData)
{
    this->rootNode = this->MakeBTreeNode(rootData);
}

BSTData BSTree::BSTGetNodeData(BTNode * bst)
{
    return bst->GetData();
}

BTNode * BSTree::WhichChild(BTNode * parentNode, BSTData data)
{
    if(data < parentNode->data)
    {
        return parentNode->GetLeftSubTree();
    }
    else if(data > parentNode->data)
    {
        return parentNode->GetRightSubTree();
    }
    else
    {
        std::cout << "Key exist" << std::endl;
        return nullptr;
    }
    
}

void BSTree::BSTInsert(BSTData data)
{
    BTNode * tempParent;
    if(this->rootNode == NULL)
    {
        std::cout << "Please Initialize the Binary Search Tree First" << std::endl;
        exit(-1);
    }

    BTNode * tempNode = this->rootNode;

    while(tempNode != NULL)                 // tempNode가 NULL이라는것은 말단노드, 즉 위치를 찾았다는 것
    {
        tempParent = tempNode;              // 위치 찾고, 그 위치의 부모 정보를 알아야 추가할 수 있음. 없으면 null에 접근
        tempNode = WhichChild(tempNode, data);
    }

    BTNode * nNode = nNode->MakeBTreeNode(data);    // 새로 Single Binary Tree Node만들고
    if(data < tempParent->GetData())                // 추가
        tempParent->MakeLeftSubTree(nNode);
    else
        tempParent->MakeRightSubTree(nNode);
}

BTNode * BSTree::BSTSearch(BSTData target)
{
    // BTNode * tempParent;
    if(this->rootNode == NULL)
    {
        std::cout << "There is no binary search tree" << std::endl;
        exit(-1);
    }

    BTNode * tempNode = this->rootNode;
    
    while(tempNode->data != target) // 책은 while문 조건을 말단노드까지 다 돌림.
    {
        // tempParent = tempNode;
        tempNode = WhichChild(tempNode, target);
        if(tempNode == NULL)        // 못찾았을 경우
        {
            return NULL;
        }
    }

    return tempNode;
}