#include <iostream>
#include "board.h"

int main() {
    //initilize board
    board board1("sudoku1.txt");
    board board2("sudoku2.txt");
    board board3("sudoku3.txt");

    //print boards
    board1.print();
    board2.print();
    board3.print();

    return 0;
}