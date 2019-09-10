#include <iostream>
#include "BinaryTree.cpp"

// void InorderTraverse(BTNode * bt)
// {
//     if(bt == NULL)
//         return;

//     InorderTraverse(bt->left);
//     std::cout << "data : " << bt->GetData() << std::endl;
//     InorderTraverse(bt->right);
// }


void ShowIntData(BTData data)   // main 앞에 선언이 되어야함
{
    std::cout << data << " ";
}

void DeleteNode(BTNode * tNode)
{
    BTNode * rNode = new BTNode;
    rNode = tNode;
    delete rNode;
    rNode = NULL;
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

    bt1->PreorderTraverse(ShowIntData);         // Traverse 함수의 input으로 root를 넣어줌. this같이 자기자신을 넣을 수는 없는지?
    std::cout << std::endl;                     // 멤버 함수에서 자기 자신의 left, right을 recursive하게 불러줘야하기 때문에 input으로 받음

    bt1->InorderTraverse(ShowIntData);
    std::cout << std::endl;        

    bt1->PostorderTraverse(ShowIntData);
    std::cout << std::endl;

    bt1->DeleteTree(DeleteNode);
    // bt1->DeleteTree();
    // bt1->PreorderTraverse(ShowIntData);         // delete되면서 garbage값이 들어가기때문에 traverse되면서 garbage값이 무한루프로 출력됨!
    // std::cout << bt1->right->right->GetData() << std::endl;
    std::cout << "All deleted!" << std::endl;

    return 0;

}
