#ifndef MOCK_KEYBOARD_INPUT_H
#define MOCK_KEYBOARD_INPUT_H

#include "../../KeyboardInput.h"

class MockKeyboardInput: public KeyboardInput
{
    std::vector<Command> commands;
public:
    MockKeyboardInput(std::vector<Command> commands);
    std::vector<Command> get_list_of_commands();
};

#endif