#include <iostream>
#include "DBLinkedList.cpp"

int main(void)
{
    List list;
    Data pdata;

    list.Init();

    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.Insert(6);
    list.Insert(7);
    list.Insert(8);

    if(list.LFirst(&pdata))
    {
        if(pdata%2 == 0)
        {
            list.LRemove();
        }

        // while(list.LNext(&pdata))
        // {
        //     if(pdata%2 == 0)
        //     {
        //         list.LRemove();
        //     }
        // }
    }

    // if(list.LFirst(&pdata))
    // {
    //     std::cout << pdata << ", " << std::endl;

    //     while(list.LNext(&pdata))
    //     {
    //         std::cout << pdata << ", " << std::endl;
    //     }
    // }
    return 0;
}