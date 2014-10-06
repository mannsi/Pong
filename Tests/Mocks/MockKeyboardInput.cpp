#include "MockKeyboardInput.h"

MockKeyboardInput::MockKeyboardInput(std::vector<Command> commands)
{
    this->commands = commands;
}


std::vector<Command> MockKeyboardInput::get_list_of_commands() {
    return commands;
}
