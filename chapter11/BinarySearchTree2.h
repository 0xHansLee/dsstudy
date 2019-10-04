#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINART_SEARCH_TREE2_H__

#include "BinaryTree3.h"

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

        BTNode * BSTRemove(BSTData target);
        void BSTShowAll();
};

#endif