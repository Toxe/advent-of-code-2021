#include <iostream>
#include <optional>

#include "input_filename.hpp"
#include "read_input.hpp"

#include "day03.hpp"

int main(int argc, char* argv[])
{
    const auto filename = input_filename({argv, static_cast<std::size_t>(argc)});

    if (!filename.has_value())
        return 1;

    std::vector<unsigned int> numbers = read_binary_numbers(filename.value());

    std::cout << "day 03, part 1: " << day03_part1(numbers, 12) << '\n';
}
