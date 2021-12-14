#include "day03.hpp"

#include <algorithm>
#include <functional>
#include <limits>
#include <vector>

std::size_t count_ones_in_column(const std::vector<unsigned int>& numbers, const int column)
{
    const unsigned int bit = 1 << column;

    return static_cast<size_t>(std::count_if(numbers.cbegin(), numbers.cend(), [=](const auto n) { return (n & bit) == bit; }));
}

unsigned int day03_part1(const std::vector<unsigned int>& numbers, const int width)
{
    if (numbers.empty() || width < 1 || width > std::numeric_limits<unsigned int>::digits)
        return 0;

    unsigned int gamma_rate = 0;
    unsigned int mask = 0;

    for (int column = 0; column < width; ++column) {
        const unsigned int bit = 1 << column;

        const std::size_t number_of_ones = count_ones_in_column(numbers, column);
        const std::size_t number_of_zeros = numbers.size() - number_of_ones;

        if (number_of_ones > number_of_zeros)
            gamma_rate |= bit;

        mask |= bit;
    }

    const unsigned int epsilon_rate = mask ^ gamma_rate;

    return gamma_rate * epsilon_rate;
}

template <typename Compare>
unsigned int calculate_rating(std::vector<unsigned int> numbers, const int width, const Compare compare)
{
    int column = width - 1;

    while (numbers.size() > 1) {
        const unsigned int bit = 1 << column;

        const std::size_t number_of_ones = count_ones_in_column(numbers, column);
        const std::size_t number_of_zeros = numbers.size() - number_of_ones;

        if (compare(number_of_ones, number_of_zeros))
            std::erase_if(numbers, [=](const auto n) { return (n & bit) == 0; });
        else
            std::erase_if(numbers, [=](const auto n) { return (n & bit) == bit; });

        --column;
    }

    return numbers[0];
}

unsigned int day03_part2(const std::vector<unsigned int>& numbers, const int width)
{
    if (numbers.empty() || width < 1 || width > std::numeric_limits<unsigned int>::digits)
        return 0;

    const unsigned int oxygen_generator_rating = calculate_rating(numbers, width, std::greater_equal<>());
    const unsigned int co2_scrubber_rating = calculate_rating(numbers, width, std::less<>());

    return oxygen_generator_rating * co2_scrubber_rating;
}
