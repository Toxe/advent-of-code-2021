#include "day01.hpp"

#include <functional>
#include <numeric>

int day01(const std::vector<int>& measurements)
{
    if (measurements.size() < 2)
        return 0;

    int count = std::inner_product(measurements.cbegin(),
        std::prev(measurements.cend()),
        std::next(measurements.cbegin()),
        0,
        std::plus<>(),
        [](int a, int b) { return a < b ? 1 : 0; });

    return count;
}
