#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <span>
#include <string_view>

#include "day01.hpp"

std::vector<int> read_input(const std::string_view filename)
{
    std::ifstream input{filename.data()};

    if (!input.is_open()) {
        std::cerr << "unable to open file: " << filename << '\n';
        return {};
    }

    std::vector<int> measurements;
    int value = 0;

    while (input >> value)
        measurements.push_back(value);

    return measurements;
}

[[nodiscard]] std::optional<std::string_view> eval_args(std::span<char*> args)
{
    if (args.size() < 2) {
        std::cerr << "missing input file name\n";
        return std::nullopt;
    }

    if (!std::filesystem::exists(args[1])) {
        std::cerr << "input file not found: " << args[1] << '\n';
        return std::nullopt;
    }

    return args[1];
}

int main(int argc, char* argv[])
{
    const auto filename = eval_args({argv, static_cast<std::size_t>(argc)});

    if (!filename.has_value())
        return 1;

    std::vector<int> measurements = read_input(filename.value());

    std::cout << "day 01: " << day01(measurements) << '\n';
}
