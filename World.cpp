#include "World.h"
#include <iostream>
#include "Collision.h"

using namespace std;

void World::run_world_loop()
{
    //cout << "Run world loop" << endl;
    update_world();
}

void World::key_pressed(char key)
{
    if (key == _keyMapping.LeftMoveDownKey)
        commands.push_back(LeftMoveDown);
    else if (key == _keyMapping.LeftMoveUpKey)
        commands.push_back(LeftMoveUp);
    else if (key == _keyMapping.RightMoveDownKey)
        commands.push_back(RightMoveDown);
    else if (key == _keyMapping.RightMoveUpKey)
        commands.push_back(RightMoveUp);
}

void World::update_world()
{
    ball.calculate_next_step();
    update_from_commands();
    update_from_collision();
    ball.update_location();
}

void World::update_from_commands()
{;
    for (int i = 0; i < commands.size() ; ++i) {
        Command command = (Command)commands[i];
        switch (command)
        {
            case LeftMoveDown:
                left_stick.move_down();
                break;
            case LeftMoveUp:
                left_stick.move_up();
                break;
            case RightMoveDown:
                right_stick.move_down();
                break;
            case RightMoveUp:
                right_stick.move_up();
                break;
        }
    }
    commands.clear();
}

void World::update_from_collision() {
    BoxShape ball_next(ball.next_x, ball.next_y, ball.width, ball.height);

    if (ball_next.x < 0)
    {
        right_points++;
        ball.initialize_ball();
        return;
    }

    if (ball_next.x + ball_next.width > world_width)
    {
        left_points++;
        ball.initialize_ball();
        return;
    }

    if (ball_next.y < 0)
    {
        ball.reverse_y_speed();
        ball.calculate_next_step();
        ball_next.y = 0; // For stick collision detection
    }

    if (ball_next.y > world_height - ball.height)
    {
        ball.reverse_y_speed();
        ball.calculate_next_step();
        ball_next.y = world_height - 1; // For stick collision detection
    }

    // Collision between ball and sticks
    if (collision_detection(ball_next, left_stick) || collision_detection(ball_next, right_stick))
    {
        ball.reverse_x_speed();
        ball.calculate_next_step();
    }
}




