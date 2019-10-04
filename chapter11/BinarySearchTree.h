#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "../chapter8/BinaryTree.h"

typedef BTData BSTData;

class BSTree : public BTNode
{
    public:
        BTNode * rootNode;
        
        void BSTMakeAndInit(BSTData rootData);      
        BSTData BSTGetNodeData(BTNode * bst);
        void BSTInsert(BSTData data);
        BTNode * WhichChild(BTNode * parentNode, BSTData data);
        BTNode * BSTSearch(BSTData target);
};

#endif