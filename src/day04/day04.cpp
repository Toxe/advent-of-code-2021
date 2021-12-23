#include "day04.hpp"

#include <algorithm>
#include <iterator>

void mark_number_on_all_boards(const int number, std::vector<Board>& boards)
{
    for (auto& board : boards)
        board.mark_number(number);
}

const Board* find_winning_board(const std::vector<Board>& boards)
{
    for (const auto& board : boards)
        if (board.is_winner())
            return &board;

    return nullptr;
}

void remove_all_winning_boards(std::vector<Board>& remaining_boards, std::vector<Board>& winning_boards)
{
    std::copy_if(remaining_boards.begin(), remaining_boards.end(), std::back_inserter(winning_boards), [](const Board& board) { return board.is_winner(); });
    std::erase_if(remaining_boards, [](const Board& board) { return board.is_winner(); });
}

int day04_part1(const std::vector<int>& random_numbers, const std::vector<Board>& boards)
{
    if (random_numbers.empty() || boards.empty())
        return 0;

    std::vector<Board> playing_boards = boards;

    for (const int number : random_numbers) {
        mark_number_on_all_boards(number, playing_boards);
        const Board* winning_board = find_winning_board(playing_boards);

        if (winning_board)
            return number * winning_board->score();
    }

    return 0;
}

int day04_part2(const std::vector<int>& random_numbers, const std::vector<Board>& boards)
{
    if (random_numbers.empty() || boards.empty())
        return 0;

    std::vector<Board> remaining_boards = boards;
    std::vector<Board> winning_boards;

    for (const int number : random_numbers) {
        mark_number_on_all_boards(number, remaining_boards);
        remove_all_winning_boards(remaining_boards, winning_boards);

        if (remaining_boards.empty())
            return number * winning_boards.back().score();
    }

    return 0;
}
