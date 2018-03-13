#include <iostream>
#include "board.h"

int main() {
    //initialize board
    board board1;
    std::string boardName = "sudoku2.txt"; //file name of input board
    board1.getInput(boardName);
    board1.print(); //print initial board

    board1.solve(); //solve the board
    board1.print(); //print solved board
    cout << "Num Calls  = " << board1.numCalls << endl;

    return 0;
}