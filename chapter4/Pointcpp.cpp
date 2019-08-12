#include <iostream>
#include "Pointcpp.h"

void Point::SetPointPos(int xpos, int ypos)
{
    this->xpos = xpos;
    this->ypos = ypos;
}

void Point::ShowPointPos()
{
    std::cout << "[" << this->xpos << ", " << this->ypos << "] " << std::endl;
}

int Point::PointComp(Point * pos2)
{
    if (this->xpos == pos2->xpos && this->ypos == pos2->ypos)
        return 0;
    else if(this->xpos == pos2->xpos)
        return 1;
    else if(this->ypos == pos2->ypos)
        return 2;
    else
        return -1;  
}