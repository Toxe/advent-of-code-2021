#pragma once

#include <vector>

enum class Direction {
    forward,
    up,
    down
};

struct Command {
    Direction direction;
    int amount;
};

int day02_part1(const std::vector<Command>& commands);
int day02_part2(const std::vector<Command>& commands);
