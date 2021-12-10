#include "read_input.hpp"

#include <fstream>
#include <iostream>

std::vector<int> read_numbers(const std::string_view filename)
{
    std::ifstream input{filename.data()};

    if (!input.is_open()) {
        std::cerr << "unable to open file: " << filename << '\n';
        return {};
    }

    std::vector<int> numbers;
    int value = 0;

    while (input >> value)
        numbers.push_back(value);

    return numbers;
}

std::vector<std::string> read_lines(const std::string_view filename)
{
    std::ifstream input{filename.data()};

    if (!input.is_open()) {
        std::cerr << "unable to open file: " << filename << '\n';
        return {};
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input, line))
        if (!line.empty())
            lines.push_back(line);

    return lines;
}
