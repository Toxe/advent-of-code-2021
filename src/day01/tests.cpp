#include "catch2/catch_test_macros.hpp"

#include "day01.hpp"

TEST_CASE("part 1")
{
    SECTION("works with example input")
    {
        CHECK(day01_part1({199, 200, 208, 210, 200, 207, 240, 269, 260, 263}) == 7);
    }

    SECTION("returns 0 if there are not enough measurements")
    {
        CHECK(day01_part1({}) == 0);
        CHECK(day01_part1({1}) == 0);
    }

    SECTION("works for simple cases")
    {
        CHECK(day01_part1({1, 2}) == 1);
        CHECK(day01_part1({1, 2, 3}) == 2);
        CHECK(day01_part1({2, 1}) == 0);
        CHECK(day01_part1({3, 2, 1}) == 0);
        CHECK(day01_part1({1, 3, 2}) == 1);
        CHECK(day01_part1({2, 1, 3}) == 1);
    }
}

TEST_CASE("part 2")
{
    SECTION("works with example input")
    {
        CHECK(day01_part2({199, 200, 208, 210, 200, 207, 240, 269, 260, 263}) == 5);
    }

    SECTION("returns 0 if there are not enough measurements")
    {
        CHECK(day01_part2({}) == 0);
        CHECK(day01_part2({1}) == 0);
        CHECK(day01_part2({1, 2}) == 0);
        CHECK(day01_part2({1, 2, 3}) == 0);
    }

    SECTION("works for simple cases")
    {
        CHECK(day01_part2({1, 2, 3, 4}) == 1);
        CHECK(day01_part2({1, 2, 3, 4, 5}) == 2);
        CHECK(day01_part2({1, 2, 3, 4, 5, 6}) == 3);
        CHECK(day01_part2({4, 3, 2, 1}) == 0);
        CHECK(day01_part2({5, 4, 3, 2, 1}) == 0);
        CHECK(day01_part2({6, 5, 4, 3, 2, 1}) == 0);
        CHECK(day01_part2({1, 1, 0, 1, 1}) == 0);
        CHECK(day01_part2({1, 1, 0, 1, 1, 1}) == 1);
        CHECK(day01_part2({1, 2, 1, 2, 1, 2}) == 2);
    }
}
