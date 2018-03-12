//
// Project 4 - Patrick Hanbury and John Kang
// 26 February 2018
//

#ifndef PROJ4SUDUKO_BOARD_H
#define PROJ4SUDUKO_BOARD_H

#include "location.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class board {
    public:
        //member variables
        const int boardLength = 9; //for 9x9 Suduko boards
        const int boardSize = 81;
        int numCalls = 0; //number of recursive calls needed to solve the board

        //matrix containing board
        std::vector<std::vector<int>> boardData;
        //conflicts "improved Conflict Approach"
        std::vector<std::vector<bool>> conflictsRows;
        std::vector<std::vector<bool>> conflictsCols;
        std::vector<std::vector<bool>> conflictsSqr;

            //Methods

        void solve(); //solves suduko board using recursion ; outputs number of recursive calls
        bool isSolved(); //checks if board is solved
        void addValue(int value , location position); //adds value to a certain location. Updates conflicts
        void clearCell(location position);
        bool checkConflict(int value ,location position); //checks if there is a conflict in a particular position
        //constructor. Reads board
        int getSqNum(location position); //outputs number 0-8 corresponding to a the square number of a position
        board(std::string boardFileName);
		int getCell(location position);
		bool isBlank(int, int); 
        void print(); //prints board function
        void printConflicts(); //prints conflicts
    	void clear();
};


#endif //PROJ4SUDUKO_BOARD_H
