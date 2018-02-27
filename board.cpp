// Project 4a- Patrick Hanbury and John Kang
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

void board::board() {
    //resize conflict vectors
    conflictsRows.resize(9,std::vector<bool>(9));
    conflictsCols.resize(9,std::vector<bool>(9));
    conflictsSqr.resize(9,std::vector<bool>(9));

    //resize board vectors (FOO)
    boardData.resize(9,std::vector<int>(9));

    //get board input
    std::ifstream fin;
    //String variable to store the string from the read file
    std::string store;
    //Open the the text file
    fin.open("sudoku1.txt");

    //If statement that checks if the file is there or not
    //Outputs a message if file is not there
    if (!fin){
        std::cout << "No file";
        system("pause");
        exit(0);
    }

    int i = 0;
    int j = 0;

    //"Z" dictates end of board
    while(fin != "Z"){
        //increment arithmetic
        if (j == 9){
            i++;
            j = 0;
        }

        if (fin == "."){
            boardData[i][j] = 0;
        }

        else{
            boardData[i][j] = int(fin);
        }

        j++;
        
    }

}



//print function that prints out the board size and each of the vectors
void board::print(std::ostream& fout){
	
	//for statement that iterates over matrix
	for (int i = 1 ; i <= boardSize; i++){	
		//if statement that checks if rows of the square is 0
		if ((i - 1) % squareSize == 0)
		}
			//variable set to 
			fout << " -";
			//for statement that iterates through the j 
			for (int j = 1; j <= boardSize; j++)
				//input variable for "----"
				fout << "---"; 
			fout << "-";
			fout << endl;
		}
	//for statement that will iterate over the matrix 
	for (int j = 1; j <= boardSize; j++)
		{
		//if statement to see if the columns of the square is 0
		if ((j - 1) % squareSize == 0) 
		//outputs break
		fout << "|";
		
		//if statement that checks if the cell is blank
		if ( !isBlank(i,j))
			//checks to see if there is a value within cell
			fout << " " << getCell(i ,j) << " ";
		//else statement
		else 
			//outputs blank
			fout << " ";
		}
		//outputs break
		fout << "|";
		fout << endl; 
	}	
	//outputs hash
	fout << " -";
	//another for statement
	for (int j = 1; j <= boardSize; j++)
		//outputs dash lines
		fout << "---";
	//outputs hash line
	fout << "-";
	fout << endl;		
}

//getCell function that returns the value stored in the cell
int board::getCell(int i, int j){
	//if statement that returns a value
	if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
		//returns a value
		return value[i][j];
}

//bool function that checks to see if the board is blank
bool board::isBlank(int i, int j){
	//if statement that checks to see if the cell is blank or not.
	if (i < 1 || i > boardSize || j < 1 || j > boardSize)
		//throws error
		throw rangeError("Bad Value");
	//if statement that checks to see if cell or true
	if (value[i][j] == blank){
		//return true
		return true;
	}
	//else return false
	return false;
}

//isSolved function to check if the board is solved or not
bool board::isSolved{
	//for statememt to iterate over i values
	for (int i = 1; i < boardSize; i++)
		//for statement to iterate over other values
		for (int j = 1; j < boardSize; j++){
			//checks to see if cell is blank, then return false
			if (getCell(i,j) == blank)
				return false;
		}
	}
	//returns true otherwise
	return true; 
}



//clear function that sets the conflicts to 0. 
void board::clear()
{
	//for statement that iterates over matrix
	for (int i = 1 ; i <= boardSize; i++){
		//for statement that will iterate
		for (int j = 1; j <= boardSize, j++){
					
			//sets values to blank
			value[i][j] = blank; 
			//row vector set the conflicts to 0
			//column vector sets the conflicts to 0
			//square vector sets the conflicts to 0
			rows[i][j] = 0;
			columns[i][j] = 0;
			squares[i][j] = 0; 	
		}
	}

bool board::checkConflict(int value, location position) {
    row = position.row;
    col = position.column;

    if (conflictsCols[col][value-1] == TRUE){
        return TRUE;
    }

    if (conflictsRows[row][value-1])
}
