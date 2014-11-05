#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
#include "OpenGlUi.h"


using namespace std;

void update(int value);
void enable2D(int width, int height);
void drawText(float x, float y, std::string text);
void drawRect(BoxShape rect);
void drawCircle(float x, float y, float r, int segments);
void KeyPressed(unsigned char, int, int);
void KeyUp(unsigned char, int, int);
void KeyOperations();;
void draw();
void draw_left_stick(World world);
void draw_right_stick(World world);
void draw_ball(World world);
void draw_score(World world);
BoxShape world_object_to_screen_object(BoxShape world_object);

int number_of_chars = 256;
World* _world;
bool* keyStates = new bool[number_of_chars]; // Create an array of boolean values of length 256 (0-255)

const int window_width = 1000;
const int window_height = 400;
const int update_interval = 1000 / 240;

void show_ui(World world, int argc, char *argv[])
{
    _world = &world;
    std::fill_n(keyStates, number_of_chars, false);
    // initialize opengl (via glut)
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("MF Pong");

    // Register callback functions
    glutDisplayFunc(draw);
    glutTimerFunc(update_interval, update, 0);
    glutKeyboardFunc(KeyPressed);
    glutKeyboardUpFunc(KeyUp);

    // setup scene to 2d mode and set draw color to white
    enable2D(window_width, window_height);
    glColor3f(1.0f, 1.0f, 1.0f);

    // start the whole thing
    glutMainLoop();
}

void enable2D(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}

void draw() {
    // clear (has to be done at the beginning)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    draw_score(*_world);
    draw_left_stick(*_world);
    draw_right_stick(*_world);
    draw_ball(*_world);

    // swap buffers (has to be done at the end)
    glutSwapBuffers();
}

void draw_left_stick(World world) {
    BoxShape screen_left_stick = world_object_to_screen_object(world.left_stick);
    drawRect(screen_left_stick);
}

void draw_right_stick(World world) {
    BoxShape screen_right_stick = world_object_to_screen_object(world.right_stick);
    drawRect(screen_right_stick);
}

void draw_ball(World world) {
    BoxShape screen_ball_rect = world_object_to_screen_object(world.ball);
    float ball_center_x = screen_ball_rect.x + screen_ball_rect.width/2;
    float ball_center_y = screen_ball_rect.y + screen_ball_rect.height/2;
    float ball_radius = screen_ball_rect.width/2;
    drawCircle(ball_center_x, ball_center_y, ball_radius, 100);
}

void draw_score(World world) {
    string left_score = to_string(world.left_points);
    string right_score = to_string(world.right_points);
    drawText(window_width / 2 - 10, window_height - 15,  left_score + ":" + right_score);
}

BoxShape world_object_to_screen_object(BoxShape world_object)
{
    BoxShape screen_object = BoxShape();

    float height_factor = window_height / (float)(*_world).world_height;
    float width_factor = window_width / (float)(*_world).world_width;

    screen_object.y = world_object.y * height_factor;
    screen_object.x = world_object.x * width_factor;
    screen_object.height = world_object.height * height_factor;
    screen_object.width = world_object.width * width_factor;

    return screen_object;

}

void update(int value) {
    // Call update() again in 'interval' milliseconds
    glutTimerFunc(update_interval, update, 0);

    KeyOperations();
    (*_world).run_world_loop();

    // Redisplay frame
    glutPostRedisplay();
}

void drawText(float x, float y, string text) {
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void drawRect(BoxShape rect) {
    glBegin(GL_QUADS);
    glVertex2f(rect.x, rect.y);
    glVertex2f(rect.x + rect.width, rect.y);
    glVertex2f(rect.x + rect.width, rect.y + rect.height);
    glVertex2f(rect.x, rect.y + rect.height);
    glEnd();
}

void drawCircle(float x, float y, float r, int segments)
{
    glBegin( GL_TRIANGLE_FAN );
    glVertex2f(x, y);
    for( int n = 0; n <= segments; ++n ) {
        float const t = 2*M_PI*(float)n/(float)segments;
        glVertex2f(x + sin(t)*r, y + cos(t)*r);
    }
    glEnd();
}

void KeyPressed (unsigned char key, int x, int y) {
    keyStates[key] = true; // Set the state of the current key to pressed
}

void KeyUp (unsigned char key, int x, int y) {
    keyStates[key] = false; // Set the state of the current key to not pressed
}

void KeyOperations() {
    for (int i = 0; i < number_of_chars; ++i) {
        if (keyStates[i])
        {
            (*_world).key_pressed((char)i);
        }
    }
}

//void KeyboardFunction(unsigned char key, int x, int y)
//{
//    cout << key << endl;
//    (*_world).key_pressed(key);
//}