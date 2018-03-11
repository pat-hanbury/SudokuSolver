// Project 4a- Patrick Hanbury and John Kang
// Created by Patrick on 2/25/2018.
//


#include "board.h"


void board::addValue(int value, location position) {
    //get coordinates
    int row = position.row;
    int col = position.column;
    int sqNum = getSqNum(position);

    //add value to board data matrix
    boardData[row][col] = value;

    //update conflicts
    conflictsCols[col][value-1] = true;
    conflictsRows[row][value-1] = true;
    conflictsSqr[sqNum][value-1] = true;
}

int board::getSqNum(location position) {
    int row = position.row;
    int col = position.column;

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

board::board(std::string boardFileName) {
    /*Determine Number of Boards in File */

    std::ifstream finSizeTest;
    //String variable to store the string from the read file
    std::string storeString;

    finSizeTest.open(boardFileName);

    //If statement that checks if the file is there or not
    //Outputs a message if file is not there
    if (!finSizeTest){
        std::cout << "No file";
        system("pause");
        exit(0);
    }

    //determine size of board
    finSizeTest >> storeString; //put contents of board into a string

    double numberOfCharacters = storeString.size(); //indicates number of tiles in board
    cout<<"board Size: " << boardSize;
    int numberOfBoards = int(numberOfCharacters/81);
    //close the file for first time
    finSizeTest.close();



    //resize conflict vectors
    conflictsRows.resize(boardLength,std::vector<bool>(boardLength));
    conflictsCols.resize(boardLength,std::vector<bool>(boardLength));
    conflictsSqr.resize(boardLength,std::vector<bool>(boardLength));

    std::cout<<"made it past resize" << endl;

    //resize board vectors (FOO)
    boardData.resize(boardLength,std::vector<int>(boardLength));

    //get board input
    std::ifstream fin;

    //Open the the text file
    fin.open(boardFileName);

    //If statement that checks if the file is there or not
    //Outputs a message if file is not there
    if (!fin){
        std::cout << "No file";
        system("pause");
        exit(0);
    }

    int i = 0;
    int j = 0;

    //Take the first board. Can modify this is Other boards are desired
    while(fin){
        char finChar;
        fin >> finChar;


        while (i < 9) {
            //increment arithmetic

            if (finChar == '.') {
                boardData[i][j] = 0;
            } else {
                boardData[i][j] = finChar - '0'; //minus 0 is needed to normalize
            }


            j++;

            if (j == boardLength) {
                i++;
                j = 0;
            }


            fin >> finChar;
        }
        }


}


void board::print() {
    cout << endl << endl; //make some space
    cout << endl << "-------------------------------"; //divider
    for(int i = 0 ; i < boardLength ; i++){
        cout << endl; //move to next line


        for(int j = 0 ; j < boardLength ; j++){
            cout << boardData[i][j] << "  " ;
            if(j==2 || j == 5 || j == 8){
                cout << "|"; //divider
            }
        }

        if(i==2 || i == 5 || i == 8){
            cout << endl << "-------------------------------"; //divider
        }
    }

    cout << endl << endl;
}


//print function that prints out the board size and each of the vectors
/*
 * JOHN's Print Function: FOO - Didn't really work
 *
void board::print() {
    location position;

	//for statement that iterates over matrix
	for (int i = 1 ; i <= boardSize; i++) {
        //if statement that checks if rows of the square is 0
        if ((i - 1) % 9 == 0) {
            //variable set to
            cout << " -";
            //for statement that iterates through the j
            for (int j = 1; j <= boardSize; j++)
                //input variable for "----"
                cout << "---";
            cout << "-";
            cout << endl;
        }
        //for statement that will iterate over the matrix
        for (int j = 1; j <= boardSize; j++) {
            //if statement to see if the columns of the square is 0
            if ((j - 1) % 9 == 0) {
                //outputs break
                cout << "|";
            }

            //if statement that checks if the cell is blank
            if (!isBlank(i, j)) {
                //checks to see if there is a value within cell
                position.column = i;
                position.row = j;
                cout << " " << getCell(position) << " ";
            }
                //else statement
            else {
                //outputs blank
                cout << " ";
            }
            //outputs break
            cout << "|";
            cout << endl;
        }
        //outputs hash
        cout << " -";
        //another for statement
        for (int j = 1; j <= boardSize; j++) {
            //outputs dash lines
            cout << "---";
        }
        //outputs hash line
        cout << "-";
        cout << endl;
    }
}

//print Conflicts function
void board::printConflicts(){
	//prints out row conflicts
	cout << "Row Conflicts" << std::endl;
	//for statuement tat iterates over th ematrix
	for (int i=1; i < 9; i++){
		for (int j =1; j < 9; j++){
			//prints out the rows and leaves a space behind it.
			cout << conflictsRows[i][j] << " ";
		}
	//prints out a line
	cout << std::endl;
	}	
	
	//prints out column conflicts
	cout << "Column Conflicts" << std::endl;
	//for statement that iterates over the matrix
	for (int i=1; i < 9; i++){
		for (int j =1; j < 9; j++){
			//prints out the columns and leaves a space behind it
			cout << conflictsCols[i][j] << " ";
		}
	//prints out a line
	cout << std::endl;
	}
	
	//prints out squares conflicts
	cout << "Squares Conflicts" << std::endl;
	//for statement iterates over the matrix
	for (int i=1; i < 9; i++){
		for (int j =1; j < 9; j++){
			//prints out the columns and leaves a space behind it
			cout << conflictsSqr[i][j] << " ";
		}
	//prints out a line
	cout << std::endl;
	}
}
*/

//getCell function that returns the value stored in the cell
int board::getCell(location position){
	//if statement that returns a value
    int i = position.row;
    int j = position.column;
	if (i >= 1 && i <= 9 && j >= 1 && j <= 9)
		//returns a value
		return boardData[i][j];
}

//clearCell function that clears the cell
void board::clearCell(location position){
	//store the value that was in the cell calling getCall
	int hold = getCell(position);
	//initializes sqNum
	int sqNum = getSqNum(position);
    int row = position.row;
    int col = position.column;
	//clears the value of the cell
	boardData[row][col] = 0;
	//check to see if there was anything in the cell before
	if (hold != 0)
		//updates each of the vectors
		//for rows columns, and square to false
		conflictsRows[row][hold -1 ] = false;
		conflictsCols[col][hold - 1]	= false;
		conflictsSqr[sqNum][hold - 1] = false;
}

//bool function that checks to see if the board is blank
bool board::isBlank(int i, int j){
	//if statement that checks to see if the cell is blank or not.
	if (i < 1 || i > boardSize || j < 1 || j > boardSize)
		//throws error
		throw ("Bad Value");
	//if statement that checks to see if cell or true
	if (boardData[i][j] == 0){
		//return true
		return true;
	}
	//else return false
	return false;
}

//isSolved function to check if the board is solved or not
bool board::isSolved(){
    location position;
	//for statememt to iterate over i values
	for (int i = 1; i < boardSize; i++) {
        //for statement to iterate over other values
        for (int j = 1; j < boardSize; j++) {
            //checks to see if cell is blank, then return false
            position.row = i;
            position.column = j;
            if (getCell(position) == 0)
                return true;
        }
    }
	//returns true otherwise
	return true;
}


//clear function that sets the conflicts to 0. 
void board::clear(){

	//for statement that iterates over matrix
	for (int i = 1 ; i <= boardSize; i++){
		//for statement that will iterate
		for (int j = 1; j <= boardSize; j++){
					
			//sets values to blank
			boardData[i][j] = 0;
			//row vector set the conflicts to 0
			//column vector sets the conflicts to 0
			//square vector sets the conflicts to 0
			conflictsRows[i][j] = 0;
			conflictsCols[i][j] = 0;
			conflictsSqr[i][j] = 0;
		}
	}
}

bool board::checkConflict(int value, location position) {
    int row = position.row;
    int col = position.column;
    int sqNum = getSqNum(position);

    if (conflictsCols[col][value - 1]) {
        return true;
    }

    if (conflictsRows[row][value - 1]) {
        return true;
    }

    if (conflictsSqr[sqNum][value - 1]) {
        return true;
    }

    return false;
}

