#include "World.h"
#include <iostream>
#include "Collision.h"

using namespace std;


void World::run_world_loop()
{
    cout << "Run world loop" << endl;
    update_world();
    draw_world();

}

void World::draw_world()
{
    // TODO
}

void World::update_world()
{
    ball.calculate_next_step();
    update_from_input();
    update_from_collision();
    ball.update_location();
}

void World::update_from_input()
{
    std::vector<Command> list_of_input_commands = (*input).get_list_of_commands();
    for (int i = 0; i < list_of_input_commands.size() ; ++i) {
        Command command = list_of_input_commands[i];
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
}

void World::update_from_collision()
{
    BoxShape ball_next(ball.next_x, ball.next_y, ball.width, ball.height);

    if (ball_next.y < 0)
    {
        ball.reverse_y_speed();
        ball.calculate_next_step();
        ball_next.y = 0; // For stick collision detection
    }

    if (ball_next.y > _world_height - 1) // Negative 1 because we measure the ball from the bottom left coordinate
    {
        ball.reverse_y_speed();
        ball.calculate_next_step();
        ball_next.y = _world_height - 1; // For stick collision detection
    }

    // Collision between ball and sticks
    if (collision_detection(ball_next, left_stick) || collision_detection(ball_next, right_stick))
    {
        ball.reverse_x_speed();
        ball.calculate_next_step();
    }
}




