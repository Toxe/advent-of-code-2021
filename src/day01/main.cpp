#include <iostream>

#include "input_filename.hpp"
#include "read_input.hpp"

#include "day01.hpp"

int main(int argc, char* argv[])
{
    const auto filename = input_filename({argv, static_cast<std::size_t>(argc)});

    if (!filename.has_value())
        return 1;

    std::vector<int> measurements = read_numbers(filename.value());

    std::cout << "day 01, part 1: " << day01_part1(measurements) << '\n';
    std::cout << "day 01, part 2: " << day01_part2(measurements) << '\n';
}
