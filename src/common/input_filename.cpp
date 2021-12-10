#include "input_filename.hpp"

#include <filesystem>
#include <iostream>

std::optional<std::string_view> input_filename(std::span<char*> args)
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
