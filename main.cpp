#include <iostream>
#include "board.h"

int main() {
    //initilize board
    board board1("sudoku1.txt");

    //print board
    std::cout << "Printed below is the unsolved board: " << endl;
    board1.print();










    return 0;
}