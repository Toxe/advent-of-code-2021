#include "day02.hpp"

int day02_part1(const std::vector<Command>& commands)
{
    if (commands.empty())
        return 0;

    int pos = 0;
    int depth = 0;

    for (const auto& command : commands) {
        switch (command.direction) {
        case Direction::forward:
            pos += command.amount;
            break;
        case Direction::up:
            depth -= command.amount;
            break;
        case Direction::down:
            depth += command.amount;
            break;
        }
    }

    return pos * depth;
}
