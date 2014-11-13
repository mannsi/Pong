#include "World.h"
#include "OpenGlUi.h"

//#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/thread/thread.hpp>

World create_world();

int main(int argc, char **argv)
{
    World world = create_world();
    show_ui(world, argc, argv);
    return 0;
}

World create_world()
{
    static const int world_width = 1000;
    static const int world_height = 500;
	static const int ball_speed_x = 1;
	static const int ball_speed_y = 1;
	static const int ball_width = 10;
	static const int ball_height = 10;
	static const int stick_step_size = 3;
	static const int stick_height = 100;
	static const int stick_width = 20;
    static const int ball_starting_position_x = world_width / 2;
    static const int ball_starting_position_y = world_height / 2;
    
	KeyMappingStruct mapping;
	mapping.LeftMoveDownKey = 'w';
	mapping.LeftMoveDownKey = 's';
	mapping.RightMoveUpKey = '8';
	mapping.RightMoveDownKey = '2';

    Ball ball = Ball(ball_starting_position_x, ball_starting_position_y, ball_width, ball_height, ball_speed_x, ball_speed_y);

    int sticks_starting_position_y = (world_height / 2 - stick_height / 2);
    int left_stick_starting_position_x = 0;
    int right_stick_starting_position_x = world_width - stick_width - 1;
    Stick left_stick = Stick(left_stick_starting_position_x, sticks_starting_position_y, stick_width, stick_height, stick_step_size, world_height);
    Stick right_stick = Stick(right_stick_starting_position_x, sticks_starting_position_y, stick_width, stick_height, stick_step_size, world_height);

    World world(ball, left_stick, right_stick, world_height, world_width, mapping);
    return world;
}