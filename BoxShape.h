#ifndef BOXSHAPE_H
#define BOXSHAPE_H

class BoxShape
{
public:
    float x;
    float y;
    float width;
    float height;

    BoxShape(){};
    BoxShape(float x, float y, float width, float height)
        : x(x)
        , y(y)
        , width(width)
        , height(height)
    {};
};

#endif