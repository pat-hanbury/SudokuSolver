#include <iostream>
#include "board.h"

int main() {
    //initilize board
    board board1("sudoku1.txt");
    board board2("sudoku2.txt");
    board board3("sudoku3.txt");

    //print boards
    board1.print();
    board1.printConflicts();
    board2.print();
    board2.printConflicts();
    board3.print();
    board3.printConflicts();
    return 0;
}