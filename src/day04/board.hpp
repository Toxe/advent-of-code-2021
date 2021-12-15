#pragma once

#include <array>

class Board {
    std::array<int, 25> numbers_;

    [[nodiscard]] bool is_winning_row(int row) const;
    [[nodiscard]] bool is_winning_column(int column) const;

    [[nodiscard]] bool has_winning_row() const;
    [[nodiscard]] bool has_winning_column() const;

public:
    explicit Board(const std::array<int, 25>& numbers) : numbers_{numbers} { }

    void mark_number(int number);

    [[nodiscard]] bool is_winner() const;
    [[nodiscard]] int score() const;
};
