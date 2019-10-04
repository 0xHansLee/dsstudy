#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

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

        typedef void (*DeleteAct)(BTNode * rNode);      // 위의 typedef에 넣으면 BTNode가 declare안되서 안됨.
        void DeleteTree(DeleteAct action);

        BTNode * RemoveLeftSubTree();
        BTNode * RemoveRightSubTree();

        void ChangeLeftSubTree(BTNode * sub);
        void ChangeRightSubTree(BTNode * sub);
};

#endif