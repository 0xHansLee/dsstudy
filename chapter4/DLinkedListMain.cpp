#include <iostream>
#include "DLinkedList.cpp"

int main(void)
{
    List list;
    int data;
    list.ListInit();

    list.LInsert(11);
    list.LInsert(11);
    list.LInsert(22);
    list.LInsert(22);
    list.LInsert(33);

    std::cout << "The number of data in this list : " << list.LCount() << std::endl;

    // Search
    if(list.LFirst(&data))
    {
        std::cout << data << " ";

        while(list.LNext(&data))
        {
            std::cout << data << " ";
        }
    }

    std::cout << std::endl << std::endl;

    // Remove
    if(list.LFirst(&data))
    {
        if(data == 22)
            list.LRemove();
        
        while(list.LNext(&data))
        {
            if(data == 22)
            {
                list.LRemove();
            }
        }
    }

    // Print all the data after removing
    std::cout << "The number of data in this list AFTER REMOVING : " << list.LCount() << std::endl;

    // Search
    if(list.LFirst(&data))
    {
        std::cout << data << " ";

        while(list.LNext(&data))
        {
            std::cout << data << " ";
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}