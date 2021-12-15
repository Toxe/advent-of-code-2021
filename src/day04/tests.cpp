#include "catch2/catch_test_macros.hpp"

#include "day04.hpp"

TEST_CASE("part 1")
{
    SECTION("works with example input")
    {
        std::vector<int> random_numbers{7, 4, 9, 5, 11, 17, 23, 2, 0, 14, 21, 24, 10, 16, 13, 6, 15, 25, 12, 22, 18, 20, 8, 19, 3, 26, 1};
        std::vector<Board> boards{
            Board{{22, 13, 17, 11, 0, 8, 2, 23, 4, 24, 21, 9, 14, 16, 7, 6, 10, 3, 18, 5, 1, 12, 20, 15, 19}},
            Board{{3, 15, 0, 2, 22, 9, 18, 13, 17, 5, 19, 8, 7, 25, 23, 20, 11, 10, 24, 4, 14, 21, 16, 12, 6}},
            Board{{14, 21, 17, 24, 4, 10, 16, 15, 9, 19, 18, 8, 23, 26, 20, 22, 11, 13, 6, 5, 2, 0, 12, 3, 7}},
        };

        CHECK(day04_part1(random_numbers, boards) == 4512);
    }

    SECTION("returns 0 if there are no random numbers")
    {
        std::vector<int> random_numbers;
        std::vector<Board> boards{
            Board{{22, 13, 17, 11, 0, 8, 2, 23, 4, 24, 21, 9, 14, 16, 7, 6, 10, 3, 18, 5, 1, 12, 20, 15, 19}},
            Board{{3, 15, 0, 2, 22, 9, 18, 13, 17, 5, 19, 8, 7, 25, 23, 20, 11, 10, 24, 4, 14, 21, 16, 12, 6}},
            Board{{14, 21, 17, 24, 4, 10, 16, 15, 9, 19, 18, 8, 23, 26, 20, 22, 11, 13, 6, 5, 2, 0, 12, 3, 7}},
        };

        CHECK(day04_part1(random_numbers, boards) == 0);
    }

    SECTION("returns 0 if there are no boards")
    {
        std::vector<int> random_numbers{7, 4, 9, 5, 11, 17, 23, 2, 0, 14, 21, 24, 10, 16, 13, 6, 15, 25, 12, 22, 18, 20, 8, 19, 3, 26, 1};
        std::vector<Board> boards;

        CHECK(day04_part1(random_numbers, boards) == 0);
    }
}
