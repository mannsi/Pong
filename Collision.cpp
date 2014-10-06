#include "Collision.h"

bool within_limits(int value, int min, int max);

bool collision_detection(BoxShape a, BoxShape b)
{
    bool collision_x =
            within_limits(a.x, b.x, b.x + b.width) ||
                    within_limits(b.x, a.x, a.x + a.width);

    bool collision_y =
            within_limits(a.y, b.y, b.y + b.height) ||
                    within_limits(b.y, a.y, a.y + a.height);

    return collision_x && collision_y;
}

bool within_limits(int value, int min, int max)
{
    return (value >= min && value < max);
}