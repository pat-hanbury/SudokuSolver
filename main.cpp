#include <iostream>
#include "board.h"

int main() {
    //initilize board
    board board1("sudoku1.txt");
    std::cout<<"board 1" << endl;
    board board2("sudoku2.txt");
    std::cout<<"board 2" << endl;



    //print boards
    board1.print();
    board2.print();

    return 0;
}