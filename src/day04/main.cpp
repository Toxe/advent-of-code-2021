#include <iostream>
#include <sstream>

#include "input_filename.hpp"
#include "read_input.hpp"

#include "day04.hpp"

std::vector<int> read_random_numbers(const std::vector<std::string>& lines)
{
    std::vector<int> random_numbers;

    if (!lines.empty()) {
        std::istringstream line{lines[0]};

        while (line) {
            int number;
            char delim;

            line >> number >> delim;

            if (!line.fail())
                random_numbers.push_back(number);
        }
    }

    return random_numbers;
}

std::array<int, 5> parse_board_line_numbers(const std::string& line)
{
    std::istringstream iss{line};
    std::array<int, 5> line_numbers{0};
    auto iter = line_numbers.begin();

    while (iss && iter != line_numbers.end())
        iss >> *iter++;

    return line_numbers;
}

std::array<int, 25> read_board_numbers(std::vector<std::string>::const_iterator& lines_iter)
{
    std::array<int, 25> numbers{0};
    auto number_inserter = numbers.begin();

    for (int row = 0; row < 5; ++row)
        for (const int number : parse_board_line_numbers(*lines_iter++))
            *number_inserter++ = number;

    return numbers;
}

std::vector<Board> read_boards(const std::vector<std::string>& lines)
{
    std::vector<Board> boards;

    if (lines.size() > 1 && (lines.size() - 1) % 5 == 0) {
        auto lines_iter = std::next(lines.cbegin());  // skip first line of random numbers

        while (lines_iter != lines.cend())
            boards.emplace_back(read_board_numbers(lines_iter));
    }

    return boards;
}

int main(int argc, char* argv[])
{
    const auto filename = input_filename({argv, static_cast<std::size_t>(argc)});

    if (!filename.has_value())
        return 1;

    const std::vector<std::string> lines = read_lines(filename.value());
    const std::vector<int> random_numbers = read_random_numbers(lines);
    const std::vector<Board> boards = read_boards(lines);

    std::cout << "day 04, part 1: " << day04_part1(random_numbers, boards) << '\n';
    std::cout << "day 04, part 2: " << day04_part2(random_numbers, boards) << '\n';
}
