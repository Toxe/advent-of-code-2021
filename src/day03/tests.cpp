#include "catch2/catch_test_macros.hpp"

#include "day03.hpp"

#include <limits>

TEST_CASE("part 1")
{
    SECTION("works with example input")
    {
        std::vector<unsigned int> numbers = {
            0b00100,
            0b11110,
            0b10110,
            0b10111,
            0b10101,
            0b01111,
            0b00111,
            0b11100,
            0b10000,
            0b11001,
            0b00010,
            0b01010,
        };

        CHECK(day03_part1(numbers, 5) == 198);
    }

    SECTION("returns 0 if there are no numbers")
    {
        CHECK(day03_part1({}, 12) == 0);
    }

    SECTION("returns 0 if width is invalid")
    {
        std::vector<unsigned int> numbers = {
            0b00000,
            0b00001,
        };

        CHECK(day03_part1(numbers, 0) == 0);
        CHECK(day03_part1(numbers, std::numeric_limits<unsigned int>::digits + 1) == 0);
    }
}
