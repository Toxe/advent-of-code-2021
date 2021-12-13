#include "catch2/catch_test_macros.hpp"

#include "day02.hpp"

TEST_CASE("part 1")
{
    SECTION("works with example input")
    {
        std::vector<Command> commands = {
            Command{Direction::forward, 5},
            Command{Direction::down, 5},
            Command{Direction::forward, 8},
            Command{Direction::up, 3},
            Command{Direction::down, 8},
            Command{Direction::forward, 2},
        };

        CHECK(day02_part1(commands) == 150);
    }

    SECTION("returns 0 if there are no commands")
    {
        CHECK(day02_part1({}) == 0);
    }

    SECTION("returns 0 if there are no horizontal commands")
    {
        std::vector<Command> commands = {
            Command{Direction::down, 1},
            Command{Direction::down, 1},
        };

        CHECK(day02_part1(commands) == 0);
    }

    SECTION("returns 0 if there are no depth commands")
    {
        std::vector<Command> commands = {
            Command{Direction::forward, 1},
            Command{Direction::forward, 1},
        };

        CHECK(day02_part1(commands) == 0);
    }

    SECTION("adds up horizontal commands")
    {
        std::vector<Command> commands = {
            Command{Direction::down, 1},
            Command{Direction::forward, 1},
            Command{Direction::forward, 1},
            Command{Direction::forward, 1},
        };

        CHECK(day02_part1(commands) == 3);
    }

    SECTION("adds up depth commands")
    {
        std::vector<Command> commands = {
            Command{Direction::forward, 1},
            Command{Direction::down, 1},
            Command{Direction::down, 1},
            Command{Direction::down, 1},
        };

        CHECK(day02_part1(commands) == 3);
    }

    SECTION("depth commands work")
    {
        std::vector<Command> commands = {
            Command{Direction::forward, 1},
            Command{Direction::down, 5},
            Command{Direction::up, 3},
            Command{Direction::down, 10},
            Command{Direction::up, 2},
        };

        CHECK(day02_part1(commands) == 10);
    }
}
