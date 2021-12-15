#include "day04.hpp"

void mark_number_on_all_boards(const int number, std::vector<Board>& boards)
{
    for (auto& board : boards)
        board.mark_number(number);
}

const Board* find_winning_board(const std::vector<Board>& boards)
{
    for (const auto& board:boards)
        if (board.is_winner())
            return &board;

    return nullptr;
}

int day04_part1(const std::vector<int>& random_numbers, std::vector<Board>& boards)
{
    if (random_numbers.empty() || boards.empty())
        return 0;

    for (const int number : random_numbers) {
        mark_number_on_all_boards(number, boards);
        const Board* winning_board = find_winning_board(boards);

        if (winning_board)
            return number * winning_board->score();
    }

    return 0;
}
