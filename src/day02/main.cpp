#include <iostream>
#include <optional>

#include "input_filename.hpp"
#include "read_input.hpp"

#include "day02.hpp"

std::optional<Command> parse_command(const std::string& line)
{
    const auto pos = line.rfind(' ');

    if (pos == std::string::npos)
        return std::nullopt;

    const std::string direction = line.substr(0, pos);
    const int amount = std::stoi(line.substr(pos + 1));

    if (amount <= 0)
        return std::nullopt;

    std::optional<Command> opt_command{std::nullopt};

    if (direction == "forward")
        opt_command = Command{Direction::forward, amount};
    else if (direction == "up")
        opt_command = Command{Direction::up, amount};
    else if (direction == "down")
        opt_command = Command{Direction::down, amount};

    return opt_command;
}

std::vector<Command> parse_lines(const std::vector<std::string>& lines)
{
    std::vector<Command> commands;

    for (const auto& line : lines) {
        const auto opt_command = parse_command(line);

        if (opt_command.has_value())
            commands.push_back(opt_command.value());
    }

    return commands;
}

int main(int argc, char* argv[])
{
    const auto filename = input_filename({argv, static_cast<std::size_t>(argc)});

    if (!filename.has_value())
        return 1;

    std::vector<Command> commands = parse_lines(read_lines(filename.value()));

    std::cout << "day 02, part 1: " << day02_part1(commands) << '\n';
}
