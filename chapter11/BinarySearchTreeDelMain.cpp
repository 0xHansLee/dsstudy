#include <iostream>
#include "BinarySearchTree2.h"

int main(void)
{
    BSTree bsTree;
    BTNode * sNode;
    bsTree.BSTMakeAndInit(1);
    bsTree.BSTInsert(2);
    bsTree.BSTInsert(3);
    bsTree.BSTInsert(4);
    bsTree.BSTInsert(5);
    bsTree.BSTInsert(6);
    bsTree.BSTInsert(7);
    bsTree.BSTInsert(8);
    bsTree.BSTInsert(9);
    // std::cout << bsTree.rootNode->right->left->right->GetData() << std::endl;

    bsTree.BSTShowAll();
    std::cout << std::endl;
    sNode = bsTree.BSTRemove(1);    // Remove 1 child node (delNode is on the left side)
    delete sNode;
    // std::cout << bsTree.rootNode->left->right->left->GetData() << std::endl;

    bsTree.BSTShowAll();
    std::cout << std::endl;
    sNode = bsTree.BSTRemove(4);    // Remove 1 child node (delNode is on the right side)
    delete sNode;

    bsTree.BSTShowAll();
    std::cout << std::endl;
    sNode = bsTree.BSTRemove(7);    // Remove 0 child node (terminal node)
    delete sNode;

    bsTree.BSTShowAll();
    std::cout << std::endl;
    sNode = bsTree.BSTRemove(8);    // Remove 2 child node
    delete sNode;

    bsTree.BSTShowAll();
    std::cout << std::endl;
    sNode = bsTree.BSTRemove(5);    // Remove 2 child node (root node)
    delete sNode;

    bsTree.BSTShowAll();
    std::cout << std::endl;
    return 0;
}