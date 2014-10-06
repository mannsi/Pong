#ifndef BALL_H
#define BALL_H

#include "BoxShape.h"

class Ball: public BoxShape
{
private:
    int _step_size;
    int _speed_x;
    int _speed_y;
    int _initial_x;
    int _initial_y;

public:
    int next_y;
    int next_x;

    Ball(int x,
            int y,
            int width,
            int height,
            int step_size,
            int speed_x,
            int speed_y)
        : BoxShape(x, y, width, height)
        , _initial_x(x)
        , _initial_y(y)
        , _step_size(step_size)
        , _speed_x(speed_x)
        , _speed_y(speed_y)
    { };
    void calculate_next_step();
    void update_location() {
        x = next_x;
        y = next_y;
    }
    void reverse_x_speed() {
        _speed_x *= -1;
    }
    void reverse_y_speed() {
        _speed_y *= -1;
    }
    void initialize_ball(){
        next_x = _initial_x;
        next_y = _initial_y;
    }

};

#endif