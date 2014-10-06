#ifndef BOXSHAPE_H
#define BOXSHAPE_H

class BoxShape
{
public:
    int x;
    int y;
    int width;
    int height;

    BoxShape(){};
    BoxShape(int x, int y, int width, int height)
        : x(x)
        , y(y)
        , width(width)
        , height(height)
    {};
};

#endif