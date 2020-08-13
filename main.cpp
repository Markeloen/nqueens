#include <iostream>
#include "Board.h"

int main() {
    Board my_board = Board(6);
    // my_board.showBoard();
    solve(my_board);
        
    // my_board.showSols();
    std::cout << "\n" << "number of sols:" << my_board.num_sols << "\n";
}

