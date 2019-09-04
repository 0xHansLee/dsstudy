#include <iostream>
#include <ctime>
#include "CircularQueue.h"

#define CUS_COME_TERM   15  // 고객이 오는 시간 텀

#define CHE_BUG     0
#define BUL_BUG     1
#define DOUB_BUG    2

#define CHE_TIME    12
#define BUL_TIME    15
#define DOUB_TIME   24

int main(void)
{
    int t;
    int making=0;
    int cheeseCount=0, bulgogiCount=0, doubleCount=0;
    Queue waitingRoom;
    waitingRoom.Init();

    srand(time(NULL));

    for(t=0; t<3600; t++)
    {
        if( (t % CUS_COME_TERM) == 0)   // queue에 다 찼을때 'Queue Memory is Full!' error msg가 뜸
        {
            switch(rand() % 3)
            {
                case CHE_BUG:     // Cheese burger, 12s
                    waitingRoom.Enqueue(CHE_TIME);
                    cheeseCount++;
                    break;

                case BUL_BUG:     // Bulgogi burger, 15s
                    waitingRoom.Enqueue(BUL_TIME);
                    bulgogiCount++;
                    break;

                case DOUB_BUG:     // Double Bulgogi Burger, 24s
                    waitingRoom.Enqueue(DOUB_TIME);
                    doubleCount++;
                    break;
            }
        }
        // making = waitingRoom.Peek();
        if(making<=0 && !waitingRoom.IsEmpty())     // 처음에 일단 꺼내서 작업하면서 --하고 작업 다했는지 check후, 다했으면 다시 dequeue!
            making = waitingRoom.Dequeue();

        making--;
    }

    std::cout <<"Cheese : " << cheeseCount << std::endl;
    std::cout <<"Bulgogi : " << bulgogiCount << std::endl;
    std::cout <<"Double Bulgogi : " << doubleCount << std::endl;
}