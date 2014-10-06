#ifndef INPUT_H
#define INPUT_H

#include <vector>

enum Command
{
    LeftMoveUp,
    LeftMoveDown,
    RightMoveUp,
    RightMoveDown
};

struct KeyMapping
{
    char LeftMoveUpKey;
    char LeftMoveDownKey;
    char RightMoveUpKey;
    char RightMoveDownKey;
};

class KeyboardInput
{
KeyMapping mapping;

public:
    KeyboardInput(){};
    KeyboardInput(KeyMapping keyMapping) {mapping = keyMapping;};
    virtual std::vector<Command> get_list_of_commands();

};

#endif