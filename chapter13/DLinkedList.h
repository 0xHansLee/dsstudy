#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0

#include "Slot2.h"

typedef Slot LData;

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

        int LFirst(LData * pdata);
        int LNext(LData * pdata);

        LData LRemove();
        int LCount();

        void SetSortRule(int (*comp)(LData d1, LData d2));

};

typedef LinkedList List;

#endif