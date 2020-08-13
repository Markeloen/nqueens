#ifndef BOARD_H
#define BOARD_H

#include <vector>


class Board
{

public:
    Board(size_t);
    size_t n;
    size_t num_sols{0};
    std::vector<std::vector<size_t>> board;
    std::vector<Board> solved_formations;
    bool isNotChecked(size_t,size_t);
    bool isSoloution(void);
    void showBoard(void);
    void empty();
    void showSols();
};

void solve(Board&, size_t queensPlaced = 0);


#endif