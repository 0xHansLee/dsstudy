#include <iostream>
#include "Pointcpp.cpp"
// #include "Pointcpp.h"
#include "DLinkedList2.cpp"
// #include "DLinkedList.h"

int SortXY(LData d1, LData d2)
{
    if(d1->xpos < d2->xpos)
        return 0;
    else if(d1->xpos == d2->xpos)
    {
        if(d1->ypos < d2->ypos)
            return 0;
        else
            return 1;
    }
    else
        return 1;
}

int main(void)
{
    List list;
    Point compPos;
    Point * ppos;

    list.ListInit();

    list.SetSortRule(SortXY);

    ppos = new Point;
    ppos->SetPointPos(2 ,1); // pointer의 함수를 사용할때는 ->
    list.LInsert(ppos);

    ppos = new Point;
    ppos->SetPointPos(2 ,2);
    list.LInsert(ppos);

    ppos = new Point;
    ppos->SetPointPos(3 ,1);
    list.LInsert(ppos);

    ppos = new Point;
    ppos->SetPointPos(3 ,2);
    list.LInsert(ppos); 

    std::cout << "The number of data : " << list.LCount() << std::endl;

    if(list.LFirst(&ppos))
    {
        ppos->ShowPointPos();

        while(list.LNext(&ppos))
            ppos->ShowPointPos();
    }

    std::cout << std::endl;

    compPos.xpos = 2;
    compPos.ypos = 0;

    if(list.LFirst(&ppos))
    {
        if(ppos->PointComp(&compPos) == 1)
        {
            ppos = list.LRemove();
            delete ppos;
        }

        while(list.LNext(&ppos))
        {
            if(ppos->PointComp(&compPos) == 1)
            {
                ppos = list.LRemove();
                delete ppos;
            }
        }
    }

    std::cout << "The number of data : " << list.LCount() << std::endl;

    if(list.LFirst(&ppos))
    {
        ppos->ShowPointPos();

        while(list.LNext(&ppos))
        {
            ppos->ShowPointPos();
        }
    }
    std::cout << std::endl;

    return 0;
}