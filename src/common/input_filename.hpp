#pragma once

#include <optional>
#include <span>
#include <string_view>

[[nodiscard]] std::optional<std::string_view> input_filename(std::span<char*> args);
