#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;
typedef void (*VisitFuncPtr)(BTData data);

class BTNode
{
    public:
        BTData data;
        BTNode * left;
        BTNode * right;

        BTNode * MakeBTreeNode(BTData data);        // node를 만들고 거기에 data도 처음부터 할당. 포인터에는 new로 메모리 할당
        BTData GetData();
        // void SetData(BTData data);

        BTNode * GetLeftSubTree();
        BTNode * GetRightSubTree();

        void MakeLeftSubTree(BTNode * sub);         // sub node를 왼쪽 노드와 연결
        void MakeRightSubTree(BTNode * sub);

        void PreorderTraverse(VisitFuncPtr action);
        void InorderTraverse(VisitFuncPtr action);
        void PostorderTraverse(VisitFuncPtr action);
};

// class BinTree
// {
//     public:
//         BTNode * MakeBTreeNode();       // node 생성 후 그 root node의 주소값 반환
//         BTData GetData(BTNode * bt);
//         void SetData(BTNode * bt, BTData data);

//         BTNode * GetLeftSubTree(BTNode * bt);
//         BTNode * GetRightSubTree(BTNode * bt);

//         void MakeLeftSubTree(BTNode * main, BTNode * bt);
//         void MakeRightSubTree(BTNode * main, BTNode * bt);
// };

#endif