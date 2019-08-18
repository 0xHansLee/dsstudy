#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0
#include "Pointcpp.h" // cpp파일을 include하면 안됨!

typedef Point * LData;

class Node {
    public:
        LData data;
        Node * next;
};

class LinkedList {
    public:
        Node * head;
        Node * cur;
        Node * before;
        int numofData;
        int (*comp)(LData d1, LData d2);

        void ListInit();
        void LInsert(LData data);
        // void FInsert(LData data);
        int LFirst(LData * pdata);
        int LNext(LData * pdata);

        LData LRemove();
        int LCount();

        void SetSortRule(int (*comp)(LData d1, LData d2));

};

typedef LinkedList List;

#endif