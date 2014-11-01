#ifndef WORLD_H
#define WORLD_H

#include "Ball.h"
#include "Stick.h"
#include "Commands.h"
#include "KeyMappingStruct.h"
#include <vector>

class World
{
private:
    KeyMappingStruct _keyMapping;
    std::vector<Command> commands;
    std::vector<int> ints;

    void update_world();
    void update_from_commands();
    void update_from_collision();


public:
    Ball ball;
    Stick left_stick;
    Stick right_stick;
    int world_height;
    int world_width;

    int left_points;
    int right_points;

    World(Ball ball, Stick left_stick, Stick right_stick, int world_height, int world_width, KeyMappingStruct keyMapping)
        : ball(ball)
        , left_stick(left_stick)
        , right_stick(right_stick)
        , world_height(world_height)
        , world_width(world_width)
        , _keyMapping(keyMapping)
    {
        left_points = 0;
        right_points = 0;
    };
    void run_world_loop();
    void key_pressed(char key);
};

#endif