#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

class ExpTree : public BTNode
{
    public:
        BTNode * ExpBTNode;     // root node

        BTNode * MakeExpTree(char exp[]);
        int EvaluateExpTree(BTNode * nodee);

        void ShowPrefixTypeExp();
        void ShowInfixTypeExp();
        void ShowPostfixTypeExp();
};

#endif