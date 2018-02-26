//
// Project 4 - Patrick Hanbury and John Kang
// 26 February 2018
//

#ifndef PROJ4SUDUKO_BOARD_H
#define PROJ4SUDUKO_BOARD_H

#include "location.h"
#include <vector>

class board {
    public:
            //member variables

        //conflicts "improved Conflict Approach"
        std::vector<std::vector<std::vector<bool>>> conflictsRows;
        std::vector<std::vector<std::vector<bool>>> conflictsCols;
        std::vector<std::vector<std::vector<bool>>> conflictsSqr;

            //Methods
        void print(); //prints boards and conflicts
        bool isSolved; //checks if board is solved
        void addValue(int value , location position); //adds value to a certain location. Updates conflicts
        void clearValue(location position);
        void checkConflict(int value ,location position); //checks if there is a confilct in a particular position
    

        //constructor. Reads board
        void board();




};


#endif //PROJ4SUDUKO_BOARD_H
