#pragma once

#include <string>
#include <string_view>
#include <vector>

[[nodiscard]] std::vector<int> read_numbers(std::string_view filename);
[[nodiscard]] std::vector<std::string> read_lines(std::string_view filename);
