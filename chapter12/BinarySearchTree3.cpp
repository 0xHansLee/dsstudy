#include <iostream>
#include "BinarySearchTree3.h"
#include "BinaryTree4.h"

#define ZERO    0
#define ONE     1
#define TWO     2

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

    while(tempNode != NULL)                 
    {
        tempParent = tempNode;              
        tempNode = WhichChild(tempNode, data);
    }

    BTNode * nNode = nNode->MakeBTreeNode(data);    
    if(data < tempParent->GetData())                
        tempParent->MakeLeftSubTree(nNode);
    else
        tempParent->MakeRightSubTree(nNode);

    this->rootNode = this->Rebalance();
}

BTNode * BSTree::BSTSearch(BSTData target)
{
    if(this->rootNode == NULL)
    {
        std::cout << "There is no binary search tree" << std::endl;
        exit(-1);
    }

    BTNode * tempNode = this->rootNode;
    
    while(tempNode->data != target)
    {
        tempNode = WhichChild(tempNode, target);
        if(tempNode == NULL)        
        {
            return NULL;
        }
    }

    return tempNode;
}

int WhatType(BTNode * node)
{
    if(node->GetLeftSubTree() == NULL && node->GetRightSubTree() == NULL)       // 1번 케이스
        return ZERO;

    else if(node->GetLeftSubTree() == NULL || node->GetRightSubTree() == NULL)  // 2번 케이스
        return ONE;

    else                                                                        // 3번 케이스
        return TWO;
}

BTNode * BSTree::BSTRemove(BSTData target)
{    
    BTNode * delNode;
    BTNode * parentNode;
    int rootFlag = 0;   

    if(this->rootNode == NULL)     
    {
        std::cout << "There is no binary search tree to remove" << std::endl;
        exit(-1);
    }

    // target이 root인지 확인
    if(this->rootNode->data == target)
    {
        BTNode * tRoot = new BTNode;
        tRoot->MakeRightSubTree(this->rootNode);
        parentNode = tRoot;
        rootFlag = 1;
    }

    // target 노드 찾음
    delNode = this->rootNode;
    
    while(delNode->data != target)
    {
        parentNode = delNode;
        delNode = WhichChild(delNode, target);
        if(delNode == NULL)        
        {
            std::cout << "There is no " << target << " in this tree" << std::endl;
            return NULL;
        }
    }

    // 타입별로 다르게 처리
    switch(WhatType(delNode)){
        case ZERO:  // 말단노드일때
        {
            if(parentNode->GetLeftSubTree() == delNode)
                delNode = parentNode->RemoveLeftSubTree();

            else
                delNode = parentNode->RemoveRightSubTree();

            break;
        }
        case ONE:   // 한쪽 노드만 있을때
        {
            if(delNode->GetLeftSubTree() == NULL)       // delNode의 왼쪽이 없을 때
            {
                if(parentNode->GetLeftSubTree() == delNode)
                {
                    parentNode->ChangeLeftSubTree(delNode->GetRightSubTree());
                }
                else
                {
                    parentNode->ChangeRightSubTree(delNode->GetRightSubTree());
                }
            }
            else        // delNode의 오른쪽이 없을 때
            {
                if(parentNode->GetLeftSubTree() == delNode)
                {
                    parentNode->ChangeLeftSubTree(delNode->GetLeftSubTree());
                }
                else
                {
                    parentNode->ChangeRightSubTree(delNode->GetLeftSubTree());
                }
            }
            break;
        }
        case TWO:   // 양쪽 노드 모두 있을때
        {
            // 오른쪽 노드의 가장 작은거 찾기
            BTNode * subRoot = delNode->GetRightSubTree();
            BTNode * tNode = subRoot;
            BTNode * tpNode = delNode;
            
            while(tNode->GetLeftSubTree() != NULL)      // Right subtree에서 가장 작은 거 찾음
            {
                tpNode = tNode;
                tNode = tNode->GetLeftSubTree();        // 대체할 노드
            }

            // 그걸 삭제할 노드에 복사
            delNode->data = tNode->data;                // data만 대체하고
            delNode = tNode;

            if(tpNode->GetLeftSubTree() == delNode)
                tpNode->ChangeLeftSubTree(tNode->GetRightSubTree());      // 연결하고 끝

            else
                tpNode->ChangeRightSubTree(tNode->GetRightSubTree());
        }
    }
    if(rootFlag == 1)
        delete parentNode;

    this->rootNode = this->Rebalance();
    return delNode;
}

void ShowIntData(int data)
{
    std::cout << data << " ";
}

void BSTree::BSTShowAll()
{
    this->rootNode->InorderTraverse(ShowIntData);
}

BTNode * BSTree::Rebalance()
{
    int heightDiff = this->rootNode->GetHeightDiff();
    // std::cout << heightDiff;

    if(heightDiff > 1)
    {
        if(this->rootNode->left->GetHeightDiff() > 0)
            return this->RotateLL();
        else
            return this->RotateLR();
    }

    if(heightDiff < -1)
    {
        if(this->rootNode->right->GetHeightDiff() < 0)
            return this->RotateRR();
        else
            return this->RotateRL();
    }
}