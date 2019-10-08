#include <iostream>
#include "BinarySearchTree3.h"

int main(void)
{
    BSTree avlTree;
    BTNode * clNode;
    BTNode * crNode;
    
    avlTree.BSTMakeAndInit(1);
    // std::cout << avlTree.rootNode->GetData();
    avlTree.BSTInsert(2);
    // std::cout << avlTree.rootNode->GetRightSubTree()->GetData();
    // avlTree.BSTInsert(3);
    // avlTree.BSTInsert(4);
    // avlTree.BSTInsert(5);
    // avlTree.BSTInsert(6);
    // avlTree.BSTInsert(7);
    // avlTree.BSTInsert(8);
    // avlTree.BSTInsert(9);

    std::cout << "Root Node : " << avlTree.rootNode->GetData() << std::endl;

    // clNode = avlTree.rootNode->GetLeftSubTree();
    // crNode = avlTree.rootNode->GetRightSubTree();
    // std::cout << "left 1 : " << clNode->GetData() << ", right 1 : " << crNode->GetData() << std::endl;

    // clNode = clNode->GetLeftSubTree();
    // crNode = crNode->GetRightSubTree();
    // std::cout << "left 2 : " << clNode->GetData() << ", right 2 : " << crNode->GetData() << std::endl;

    // clNode = clNode->GetLeftSubTree();
    // crNode = crNode->GetRightSubTree();
    // std::cout << "left 3 : " << clNode->GetData() << ", right 3 : " << crNode->GetData() << std::endl;

    // clNode = clNode->GetLeftSubTree();
    // crNode = crNode->GetRightSubTree();
    // std::cout << "left 4 : " << clNode->GetData() << ", right 4 : " << crNode->GetData() << std::endl;
}