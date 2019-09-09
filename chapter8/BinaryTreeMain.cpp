#include <iostream>
#include "BinaryTree.h"

// void InorderTraverse(BTNode * bt)
// {
//     if(bt == NULL)
//         return;

//     InorderTraverse(bt->left);
//     std::cout << "data : " << bt->GetData() << std::endl;
//     InorderTraverse(bt->right);
// }


void ShowIntData(BTData data)
{
    std::cout << data << " ";
}

int main(void)
{
    BTNode * bt1 = bt1->MakeBTreeNode(1);
    BTNode * bt2 = bt2->MakeBTreeNode(2);
    BTNode * bt3 = bt3->MakeBTreeNode(3);
    BTNode * bt4 = bt4->MakeBTreeNode(4);
    BTNode * bt5 = bt5->MakeBTreeNode(5);
    BTNode * bt6 = bt6->MakeBTreeNode(6);

    // bt1 = bt1->MakeBTreeNode(1);
    // bt2 = bt2->MakeBTreeNode(2);
    // bt3 = bt3->MakeBTreeNode(3);
    // bt4 = bt4->MakeBTreeNode(4);

    bt1->MakeLeftSubTree(bt2);
    bt1->MakeRightSubTree(bt3);
    bt1->left->MakeLeftSubTree(bt4);
    bt1->left->MakeRightSubTree(bt5);
    bt1->right->MakeRightSubTree(bt6);


    std::cout << "data of left node : " << bt1->left->GetData() << std::endl;
    std::cout << "data of left node of left : " << bt1->left->left->GetData() << std::endl;

    // InorderTraverse(bt1);

    bt1->PreorderTraverse(ShowIntData);        // Traverse 함수의 input으로 root를 넣어줌. this같이 자기자신을 넣을 수는 없는지?
    bt1->InorderTraverse(ShowIntData);        // 멤버 함수에서 자기 자신의 left, right을 recursive하게 불러줘야하기 때문에 input으로 받음
    bt1->PostorderTraverse(ShowIntData);

    return 0;

}
