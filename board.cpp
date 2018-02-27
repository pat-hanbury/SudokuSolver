//
// Created by Patrick on 2/25/2018.
//

#include "board.h"

void board::addValue(int value, location position) {
    //get coordinates
    row = position.row;
    col = position.column;
    sqNum = getSqNum(position);

    //add value to board data matrix
    boardData[row][col] = value;

    //update conflicts
    conflictsCols[col][value-1] = TRUE;
    conflictsRows[row][value-1] = TRUE;
    conflictsSqr[sqNum][value-1] = TRUE;
}

int board::getSqNum(location position) {
    row = position.row;
    col = position.column;

    if(row > 8 || col > 8){
        throw "range error.";
    }

    //squares 0-2
    if (row < 3){
        if (col < 3){
            return 0;
        }

        if (col > 2 && col < 6){
            return 1;
        }

        if (col > 5){
            return 2;
        }
    }

    //squares 3-5
    if (row > 2 && row < 6){
        if (col < 3){
            return 3;
        }

        if (col > 2 && col < 6){
            return 4;
        }

        if (col > 5){
            return 5;
        }
    }

    if (row > 5){
        if (col < 3){
            return 6;
        }

        if (col > 2 && col < 6){
            return 7;
        }

        if (col > 5){
            return 8;
        }
    }
}

constructor
resize vectors
