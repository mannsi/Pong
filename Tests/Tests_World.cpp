#include "gtest/gtest.h"
#include "../World.h"
#include "Mocks/MockKeyboardInput.h"

World get_mock_world(std::vector<Command> commands,
        int ball_x,
        int ball_y,
        int ball_speed_x,
        int ball_speed_y,
        int left_stick_x,
        int left_stick_y,
        int right_stick_x,
        int right_stick_y);
World run_one_world_loop();
void setup();

static const int world_width = 1000;
static const int world_height = 500;
static const int ball_initial_x = world_width / 2;
static const int ball_initial_y = world_height / 2;
static const int ball_width = 1;
static const int ball_height = 1;
static const int ball_step_size = 1;
static const int stick_step_size = 1;
static const int stick_height = 10;
static const int stick_width = 2;
static const int stick_top_position = world_height - stick_height;


std::vector<Command> commands;
int ball_x = 100;
int ball_y = 100;
int ball_speed_x = 1;
int ball_speed_y = 1;
int left_stick_x = 0;
int left_stick_y = 0;
int right_stick_x = world_width;
int right_stick_y = 0;

TEST(WorldTest, no_collision_no_commands)
{
    setup();

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x, ball_x + ball_speed_x) << "Should be no collision. Ball should move at x speed";
    ASSERT_EQ(mock_world.ball.y , ball_y + ball_speed_y) << "Should be no collision. Ball should move at y speed";
    ASSERT_EQ(mock_world.left_stick.x , left_stick_x) << "Left should not have moved";
    ASSERT_EQ(mock_world.left_stick.y , left_stick_y) << "Left should not have moved";
    ASSERT_EQ(mock_world.right_stick.x , right_stick_x) << "Right should not have moved";
    ASSERT_EQ(mock_world.right_stick.y , right_stick_y) << "Right should not have moved";
}

TEST(WorldTest, no_collision_with_commands)
{
    setup();

    commands.push_back(LeftMoveUp);
    commands.push_back(RightMoveUp);

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x , ball_x + ball_speed_x) << "Should be no collision. Ball should move at x speed";
    ASSERT_EQ(mock_world.ball.y , ball_y + ball_speed_y) << "Should be no collision. Ball should move at y speed";
    ASSERT_EQ(mock_world.left_stick.x , left_stick_x) << "Left should not have moved";
    ASSERT_EQ(mock_world.left_stick.y , left_stick_y + stick_step_size) << "Left should have moved";
    ASSERT_EQ(mock_world.right_stick.x , right_stick_x) << "Right should not have moved";
    ASSERT_EQ(mock_world.right_stick.y , right_stick_y + stick_step_size) << "Right should have moved";
}

TEST(WorldTest, collision_with_left_stick_no_commands)
{
    setup();

    ball_x = 2;
    ball_y = 5;
    ball_speed_x = -1;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x ,ball_x + (ball_speed_x * -1)) << "There was a left stick collision and the ball should bounce off it to the right";
    ASSERT_EQ(mock_world.ball.y ,ball_y + ball_speed_y) << "There was a collision but on the x axis. Ball should move at y speed";
    ASSERT_EQ(mock_world.left_stick.x ,left_stick_x) << "Left should not have moved";
    ASSERT_EQ(mock_world.left_stick.y ,left_stick_y) << "Left should not have moved";
    ASSERT_EQ(mock_world.right_stick.x ,right_stick_x) << "Right should not have moved";
    ASSERT_EQ(mock_world.right_stick.y ,right_stick_y) << "Right should not have moved";
}

TEST(WorldTest, collision_with_left_stick_with_commands)
{
    setup();

    commands.push_back(LeftMoveUp);

    ball_x = 2;
    ball_y = 5;
    ball_speed_x = -1;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x , ball_x + (ball_speed_x * -1)) << "There was a left stick collision and the ball should bounce off it to the right";
    ASSERT_EQ(mock_world.ball.y , ball_y + ball_speed_y) << "There was a collision but on the x axis. Ball should move at y speed";
    ASSERT_EQ(mock_world.left_stick.x , left_stick_x) << "Left should not have moved";
    ASSERT_EQ(mock_world.left_stick.y , left_stick_y + stick_step_size) << "Left should have moved";
    ASSERT_EQ(mock_world.right_stick.x , right_stick_x) << "Right should not have moved";
    ASSERT_EQ(mock_world.right_stick.y , right_stick_y) << "Right should not have moved";
}

TEST(WorldTest, collision_with_top_wall)
{
    setup();

    ball_y = world_height - 1;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x, ball_x + ball_speed_x) << "Ball should move normally in x direction";
    ASSERT_EQ(mock_world.ball.y, ball_y - ball_speed_y) << "Because of collision with top wall the ball should move ball_speed_y down";
}

TEST(WorldTest, test_collision_with_bottom_wall)
{
    setup();

    ball_y = 0;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x, ball_x + ball_speed_x) << "Ball should move normally in x direction";
    ASSERT_EQ(mock_world.ball.y, ball_y + ball_speed_y) << "Because of collision with bottom wall the ball should move ball_speed_y up";
}

TEST(WorldTest, collision_with_bottom_wall_and_right_stick)
{
    setup();

    ball_y = 0;
    ball_x = world_width - 3;
    ball_speed_y = -1;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x, ball_x + (ball_speed_x * -1)) << "Ball should reverse move because of collision with right wall";
    ASSERT_EQ(mock_world.ball.y, ball_y + (ball_speed_y * -1)) << "Ball should reverse move because of collision with bottom wall";
}

TEST(WorldTest, collision_with_top_wall_and_left_stick)
{
    setup();

    ball_y = world_height - 1;
    ball_x = stick_width;
    ball_speed_x = -1;
    left_stick_y = stick_top_position;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x, ball_x + (ball_speed_x * -1)) << "Ball should reverse move because of collision with left wall";
    ASSERT_EQ(mock_world.ball.y, ball_y + (ball_speed_y * -1)) << "Ball should reverse move because of collision with bottom wall";
}

TEST(WorldTest, collision_when_left_stick_moves_in_front_of_ball)
{
    setup();

    commands.push_back(LeftMoveDown);

    ball_y = 1;
    ball_x = stick_width;
    ball_speed_x = -1;
    ball_speed_y = -1;
    left_stick_y = 1;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x, ball_x + (ball_speed_x * -1)) << "Ball should reverse move because of collision with left wall";
    ASSERT_EQ(mock_world.ball.y, ball_y + ball_speed_y) << "Ball starts in 1 pos and should just go to bottom";
}

TEST(WorldTest, collision_when_right_stick_moves_in_front_of_ball)
{
    setup();

    commands.push_back(RightMoveUp);

    ball_y = world_height - 2;
    ball_x = world_width - stick_width;
    right_stick_y = world_height - stick_height - stick_step_size;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x, ball_x + (ball_speed_x * -1)) << "Ball should reverse move because of collision with left wall";
    ASSERT_EQ(mock_world.ball.y, ball_y + ball_speed_y) << "Ball should not collide with top and continue moving";
}

TEST(WorldTest, no_collision_because_stick_moves_away)
{
    setup();

    commands.push_back(RightMoveDown);

    ball_y = world_height - 2;
    ball_x = world_width - stick_width;
    right_stick_y = world_height - stick_height;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.ball.x, ball_x + ball_speed_x) << "Ball should move on because stick just moved away";
    ASSERT_EQ(mock_world.ball.y, ball_y + ball_speed_y) << "Ball should move on because stick just moved away";
}

TEST(WorldTest, point_scored_left_side)
{
    setup();

    ball_y = 1;
    ball_x = 0;
    ball_speed_x = -1;
    left_stick_y = stick_top_position;

    World mock_world = run_one_world_loop();
    ASSERT_EQ(mock_world.left_points, 1) << "First point for left";
    ASSERT_EQ(mock_world.right_points, 1) << "No points scored by right";
    ASSERT_EQ(mock_world.ball.x, ball_initial_x) << "A point was scored so ball should go back to initial position";
    ASSERT_EQ(mock_world.ball.y, ball_initial_y) << "A point was scored so ball should go back to initial position";
}

void setup()
{
    commands.clear();
    ball_x = ball_initial_x;
    ball_y = ball_initial_y;
    ball_speed_x = 1;
    ball_speed_y = 1;
    left_stick_x = 0;
    left_stick_y = 0;
    right_stick_x = world_width - 2;
    right_stick_y = 0;
}

World get_mock_world(std::vector<Command> commands,
    int ball_x,
    int ball_y,
    int ball_speed_x,
    int ball_speed_y,
    int left_stick_x,
    int left_stick_y,
    int right_stick_x,
    int right_stick_y)
{
    KeyboardInput* input = new MockKeyboardInput(commands);
    Ball ball = Ball(ball_x, ball_y, ball_width, ball_height, ball_step_size, ball_speed_x, ball_speed_y);
    Stick left_stick = Stick(left_stick_x, left_stick_y, stick_width, stick_height, stick_step_size, world_height);
    Stick right_stick = Stick(right_stick_x, right_stick_y, stick_width, stick_height, stick_step_size, world_height);
    DrawingStuff drawing_stuff;
    World world(ball, left_stick, right_stick, input, drawing_stuff, world_height, world_width);
    return world;
}

World run_one_world_loop()
{
    World mock_world = get_mock_world(commands, ball_x, ball_y, ball_speed_x, ball_speed_y, left_stick_x, left_stick_y, right_stick_x , right_stick_y);
    mock_world.run_world_loop();
    return mock_world;
}



