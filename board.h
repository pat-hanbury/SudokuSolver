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
#include "d_matrix.h"
#include "d_except.h"
#include <list>

using namespace std;


class board 
{
	public:
		//member variables
		const int blank = -1;  // Indicates that a cell is blank
		const int squareSize = 3;  //  The number of cells in a small square
		const int minValue = 1; 
		const int maxValue = 9;
		const int boardSize = squareSize * squareSize;
        int numCalls = 0; //keeps track of the number or recursive calls required to solve board

            //Methods
        board();
		void getInput(std::string boardName);
        void updateConflicts( int, int, int);
        bool checkConflicts(int, int, int); //checks if there is a confilct in a particular position
        int squareNumber (int, int); //outputs number 0-8 corresponding to a the square number of a position
        bool setCell(int i, int j, int val);
		int getCell(int, int);
		void clearCell(int i, int j);
		bool isBlank(int, int); 
        void print(); //prints board function
        void printConflicts(std::ofstream &); //prints conflicts
    	void clear();
        void solve(); //solves board
        bool solveRecursive(int row, int col); //recursive solve function used in solve()
    	
    	//
    	bool checkSolved();
    	
    	
    //private declarations	
	private:
		matrix<int> value; //matrix that stores all current values of a sudoku board
		matrix<bool> rows; //matrix that stors all row conflicts
		matrix<bool> columns; //matrix that stores all column conflicts
		matrix<bool> squares; //matrix that stores all square conflicts
};


#endif //PROJ4SUDUKO_BOARD_H
