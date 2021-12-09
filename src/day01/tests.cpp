#include "catch2/catch_test_macros.hpp"

#include "day01.hpp"

TEST_CASE("works with example input")
{
    REQUIRE(day01({199, 200, 208, 210, 200, 207, 240, 269, 260, 263}) == 7);
}

TEST_CASE("returns 0 if there are not enough measurements")
{
    REQUIRE(day01({}) == 0);
    REQUIRE(day01({1}) == 0);
}

TEST_CASE("works for simple cases")
{
    REQUIRE(day01({1, 2}) == 1);
    REQUIRE(day01({1, 2, 3}) == 2);
    REQUIRE(day01({2, 1}) == 0);
    REQUIRE(day01({3, 2, 1}) == 0);
    REQUIRE(day01({1, 3, 2}) == 1);
    REQUIRE(day01({2, 1, 3}) == 1);
}
