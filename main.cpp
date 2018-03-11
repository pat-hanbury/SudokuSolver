#include <iostream>
#include "board.h"

int main() {
    //initilize board
    board board1("sudoku1.txt");
    std::cout<<"board 1" << endl;
    board board2("sudoku2.txt");
    std::cout<<"board 2" << endl;
    //board board3("sudoku3.txt");
    std::cout<<"board 3" << endl;

    /*
    //print boards
    board1.print();
    board1.printConflicts();
    board2.print();
    board2.printConflicts();
    board3.print();
    board3.printConflicts();
     */
    return 0;
}