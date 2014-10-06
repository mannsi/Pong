#include "Stick.h"

void Stick::move_up() {
    if (y + _step_size + height <= _max_height)
    {
        y = y + _step_size;
    }
}

void Stick::move_down() {
    if (y - _step_size >= 0)
    {
        y = y - _step_size;
    }
}