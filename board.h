//
// Project 4 - Patrick Hanbury and John Kang
// 26 February 2018
//

#ifndef PROJ4SUDUKO_BOARD_H
#define PROJ4SUDUKO_BOARD_H

#include "location.h"

class board {
    public:
        const boardSize = squareSize * squareSize;
		int getCell(int, int);
		bool isBlank(int, int); 
        void print(std::ofstream &);
    	void clear();
    	
};


#endif //PROJ4SUDUKO_BOARD_H
