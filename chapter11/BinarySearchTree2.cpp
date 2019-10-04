#include <iostream>
#include "BinarySearchTree2.h"

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

BTNode * BSTree::BSTRemove(BSTData target)
{
    // 삭제할 노드가  root노드일때 예외처리 필요

    BTNode * delNode;
    BTNode * parentNode;

    if(this->rootNode == NULL)     
    {
        std::cout << "There is no binary search tree to remove" << std::endl;
        exit(-1);
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
            if(parentNode->GetLeftSubTree.data == target)
                this->RemoveLeftSubTree(parentNode);

            else
                this->RemoveRightSubTree(parentNode);

            break;
        }
        case ONE:   // 한쪽 노드만 있을때
        {
            if(delNode->GetLeftSubTree == NULL)
            {
                this->ChangeRightSubTree(parentNode, delNode->GetRightSubTree());
            }
            else
            {
                this->ChangeRightSubTree(parentNode, delNode->GetLeftSubTree());
            }

            break;
        }
        case TWO:   // 양쪽 노드 모두 있을때
        {
            // 오른쪽 노드의 가장 작은거 찾기
            BTNode * subRoot = delNode->GetRightSubTree();
            BTNode * tNode = subRoot;
            BTNode * tpNode = tNode;
            
            while(tNode->GetLeftSubTree() != NULL)      // Right subtree에서 가장 작은 거 찾음
            {
                tpNode = tNode;
                tNode = tNode->GetLeftSubTree();        // 대체할 노드
            }

            // 그걸 삭제할 노드에 복사
            delNode->data = tNode->data;
            delNode = tNode;
            
            // 연결 (당연히 왼쪽에 있는 subtree를 change해야하는것 아닌가? 오른쪽 서브트리중 가장 작은 것(왼쪽)으로 대체했기 때문)
            this->ChangeLeftSubTree(tpNode, tNode->GetRightSubTree);
        }
    }

}

void ShowIntData(int data)
{
    std::cout << data << " ";
}

void BSTree::BSTShowAll()
{
    this->InorderTraverse(ShowIntData);
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