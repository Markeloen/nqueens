#include "Board.h"
#include <iostream>


Board::Board(size_t n) {
    this->board = std::vector<std::vector<size_t>>(n, std::vector<size_t>(n, 0));
    this->n = n;
}


bool Board::isNotChecked(size_t r,size_t c) {
    for (size_t i = 0; i < n; i++) { //column check
        if (board[r][i] == 1 && i != c)
            return false;
        if (board[i][c] == 1 && i != r)
            return false;
    }
        for(size_t i = 0; i < n; i++)
            for(size_t j = 0; j < n; j++) {
                // if(i == r && j == c)
                //     continue;
                if(board[i][j] == 1 && abs(i-r) == abs(j-c) && i!=r && j!= c)
                    return false;
            }
    return true;
    
        
    
}


void Board::showBoard() {
    for(size_t i = 0; i < n;i++) {
        for (size_t j = 0; j < n; j++)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
        
    }
    std::cout << std::endl;
}


bool Board::isSoloution() {
    for(size_t i = 0; i < this->n; i++)
        for(size_t j = 0; j < this->n; j++)
            if(this->board[i][j] == 1 && !this->isNotChecked(i,j))
                return false;
    return true;
}       

void Board::empty() {
    for(size_t i = 0; i < this->n; i++)
        for(size_t j = 0; j < n; j++)
            this->board[i][j] = 0;
}

void Board::showSols() {
    for(auto &x:solved_formations)
        x.showBoard();
}

void solve(Board &myBoard, size_t queensPlaced) {

    for (size_t j = 0; j < myBoard.n; j++)
    {
        if (queensPlaced == myBoard.n) {
            myBoard.num_sols++;
            // myBoard.solved_formations.push_back(myBoard);
            myBoard.showBoard();
            return;
        }

        if(myBoard.isNotChecked(queensPlaced, j)) {
            myBoard.board[queensPlaced][j] = 1;
            solve(myBoard, queensPlaced + 1);
            
            myBoard.board[queensPlaced][j] = 0;

        }
        
        
        
        
    }
    
}

