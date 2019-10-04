#include <iostream>
#include "BinarySearchTree2.h"

int main(void)
{
    BSTree bsTree;
    BTNode * sNode;
    bsTree.BSTMakeAndInit(5);
    bsTree.BSTInsert(8);
    bsTree.BSTInsert(1);
    bsTree.BSTInsert(6);
    bsTree.BSTInsert(4);
    bsTree.BSTInsert(9);
    bsTree.BSTInsert(3);
    bsTree.BSTInsert(2);
    bsTree.BSTInsert(7);
    // std::cout << bsTree.rootNode->right->left->right->GetData() << std::endl;

    // bsTree.BSTShowAll();
    std::cout << std::endl;
    sNode = bsTree.BSTRemove(3);
    delete sNode;
    std::cout << bsTree.rootNode->left->right->left->GetData() << std::endl;

    // bsTree.BSTShowAll();
    // std::cout << std::endl;
    // sNode = bsTree.BSTRemove(3);
    // delete sNode;

    // bsTree.BSTShowAll();
    // std::cout << std::endl;
    // sNode = bsTree.BSTRemove(3);
    // delete sNode;

    // bsTree.BSTShowAll();
    // std::cout << std::endl;
    // sNode = bsTree.BSTRemove(3);
    // delete sNode;

    // bsTree.BSTShowAll();
    // std::cout << std::endl;
    return 0;
}