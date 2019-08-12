#ifndef __POINTCPP_H__
#define __POINTCPP_H__

class Point
{
    public:
        int xpos;
        int ypos;

        void SetPointPos(int xpos, int ypos);
        void ShowPointPos();
        int PointComp(Point * pos2);
};

#endif