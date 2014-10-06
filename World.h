#ifndef WORLD_H
#define WORLD_H

#include "Ball.h"
#include "Stick.h"
#include "KeyboardInput.h"
#include "DrawingStuff.h"

class World
{
private:
    int _world_height;
    int _world_width;


    void update_world();
    void draw_world();
    void update_from_input();
    void update_from_collision();


public:
    Ball ball;
    Stick left_stick;
    Stick right_stick;
    KeyboardInput* input;
    DrawingStuff drawing_stuff;

    int left_points;
    int right_points;

    World(Ball ball, Stick left_stick, Stick right_stick, KeyboardInput* input, DrawingStuff drawing_stuff, int world_height, int world_width)
        : ball(ball)
        , left_stick(left_stick)
        , input(input)
        , right_stick(right_stick)
        , drawing_stuff(drawing_stuff)
        , _world_height(world_height)
        , _world_width(world_width)
    {
        left_points = 0;
        right_points = 0;
    };
    void run_world_loop();
};

#endif