#include <iostream>
#include "BinarySearchTree.h"

int main(void)
{
    // BTNode * bstRoot;
    BTNode * sNode;
    BSTree bstree;
    
    bstree.BSTMakeAndInit(9);
    bstree.BSTInsert(1);
    // std::cout << bstree.rootNode->GetData() << std::endl;
    // std::cout << bstree.rootNode->left->GetData() << std::endl;
    bstree.BSTInsert(6);
    bstree.BSTInsert(2);
    bstree.BSTInsert(8);
    bstree.BSTInsert(3);
    bstree.BSTInsert(5);

    sNode = bstree.BSTSearch(1);
    if(sNode == NULL)
        std::cout << "Search Fail" << std::endl;
    else
        std::cout << "Key : " << sNode->GetData() << std::endl;

    sNode = bstree.BSTSearch(4);
    if(sNode == NULL)
        std::cout << "Search Fail" << std::endl;
    else
        std::cout << "Key : " << sNode->GetData() << std::endl;

    sNode = bstree.BSTSearch(6);
    if(sNode == NULL)
        std::cout << "Search Fail" << std::endl;
    else
        std::cout << "Key : " << sNode->GetData() << std::endl;

    sNode = bstree.BSTSearch(7);
    if(sNode == NULL)
        std::cout << "Search Fail" << std::endl;
    else
        std::cout << "Key : " << sNode->GetData() << std::endl;

    return 0;
}