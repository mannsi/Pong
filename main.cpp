#include "World.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

static const int world_width = 1000;
static const int world_height = 500;
static const int ball_starting_position_x = 100;
static const int ball_starting_position_y = 10;
static const int ball_speed_x = 1;
static const int ball_speed_y = 1;
static const int ball_width = 1;
static const int ball_height = 1;
static const int ball_step_size = 1;
static const int stick_step_size = 1;
static const int stick_height = 10;
static const int stick_width = 2;

int main(int argc, char **argv)
{
    KeyMapping mapping = {.LeftMoveUpKey = 'w', .LeftMoveDownKey = 's', .RightMoveUpKey = '8', .RightMoveDownKey = '2'};
    KeyboardInput* input = new KeyboardInput(mapping);
    Ball ball = Ball(ball_starting_position_x, ball_starting_position_y, ball_width, ball_height, ball_step_size, ball_speed_x, ball_speed_y);

    int sticks_starting_position_y = (world_height / 2 - stick_height / 2);
    int left_stick_starting_position_x = 0;
    int right_stick_starting_position_x = world_width - 1;
    Stick left_stick = Stick(left_stick_starting_position_x, sticks_starting_position_y, stick_width, stick_height, stick_step_size, world_height);
    Stick right_stick = Stick(right_stick_starting_position_x, sticks_starting_position_y, stick_width, stick_height, stick_step_size, world_height);
    DrawingStuff drawing_stuff;

    World world(ball, left_stick, right_stick, input, drawing_stuff, world_height, world_width);
    while(true)
    {
        boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        world.run_world_loop();
    }
    return 0;
}