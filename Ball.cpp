#include "Ball.h"

void Ball::calculate_next_step()
{
    next_x = x + _speed_x;
    next_y = y + _speed_y;
}