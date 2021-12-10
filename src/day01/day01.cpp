#include "day01.hpp"

#include <numeric>

int sum_of_window(const std::vector<int>::const_iterator& it, const int window_size)
{
    return std::accumulate(it, it + window_size, 0);
}

int compare_measurements(const std::vector<int>& measurements, const int window_size)
{
    if (std::ssize(measurements) < window_size + 1)
        return 0;

    int count = 0;

    for (auto it = measurements.cbegin(); it != measurements.cend() - window_size; ++it)
        if (sum_of_window(it, window_size) < sum_of_window(it + 1, window_size))
            ++count;

    return count;
}

int day01_part1(const std::vector<int>& measurements)
{
    return compare_measurements(measurements, 1);
}

int day01_part2(const std::vector<int>& measurements)
{
    return compare_measurements(measurements, 3);
}
