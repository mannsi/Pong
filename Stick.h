#ifndef STICK_H
#define STICK_H

#include "BoxShape.h"

class Stick: public BoxShape
{
private:
    int _step_size;
    int _max_height;

public:
    Stick(int x, int y, int width, int height, int step_size, int max_height)
        : BoxShape(x, y, width, height)
        , _step_size(step_size)
        , _max_height(max_height)
    { };
    void move_up();
    void move_down();


};

#endif