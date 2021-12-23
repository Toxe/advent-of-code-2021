#include "board.hpp"

#include <algorithm>
#include <numeric>

void Board::mark_number(const int number)
{
    std::replace(numbers_.begin(), numbers_.end(), number, -1);
}

int Board::number_at(const int column, const int row) const
{
    return numbers_[column + row * 5];
}

bool Board::is_winning_row(const int row) const
{
    for (int column = 0; column < 5; ++column)
        if (number_at(column, row) >= 0)
            return false;

    return true;
}

bool Board::is_winning_column(const int column) const
{
    for (int row = 0; row < 5; ++row)
        if (number_at(column, row) >= 0)
            return false;

    return true;
}

bool Board::has_winning_row() const
{
    for (int row = 0; row < 5; ++row)
        if (is_winning_row(row))
            return true;

    return false;
}

bool Board::has_winning_column() const
{
    for (int column = 0; column < 5; ++column)
        if (is_winning_column(column))
            return true;

    return false;
}

bool Board::is_winner() const
{
    return has_winning_row() || has_winning_column();
}

int Board::score() const
{
    return std::accumulate(numbers_.cbegin(), numbers_.cend(), 0, [](const int sum, const int n) { return n >= 0 ? sum + n : sum; });
}
