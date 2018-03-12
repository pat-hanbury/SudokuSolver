// Project 4b- Patrick Hanbury and John Kang
// Created by Patrick on 2/25/2018.
// TRIAL

#include "board.h"

//constructor
board::board()
{
	//initialize the value matrix to 9 X 
	value.resize(boardSize + 1, boardSize + 1);
	//initialize conflict matrices to 9 X 9
	rows.resize(boardSize + 1, boardSize + 1);
	columns.resize(boardSize + 1, boardSize + 1);
	squares.resize(boardSize + 1, boardSize + 1);
}

void board::initialize(std::ifstream &fin)
// Read a Sudoku board from the input file.
{
	char ch; //stores each character as its read in
	
	clear();
	for (int i = 1; i <= boardSize; i++) {//iterate over entire board
		for (int j = 1; j <= boardSize; j++)
		{
			fin >> ch;
			// If the read char is not Blank
			if (ch != '.')
			{
				setCell(i, j, ch - '0');   // Convert char to int
			}
			else clearCell(i, j); //if the read char is blank, clear the cell
		}
	}
}

int board::squareNumber(int i, int j)
{
	return squareSize * ((i - 1) / squareSize) + (j - 1) / squareSize + 1;
}

void board::clear()
// clear the entire board.
{
	for (int i = 1; i <= boardSize; i++) { //iterate over the entire value matrix
		for (int j = 1; j <= boardSize; j++) {
			value[i][j] = blank; //set every value to blank
			//set every conflict to 0
			rows[i][j] = 0;
			columns[i][j] = 0;
			squares[i][j] = 0;

		}
	}
}

bool board::setCell(int i, int j, int val)
// set cell i,j to val and update conflicts
{
	if (!checkConflicts(i, j, val)) { //only insert the value if there are no conflicts for that value 
		value[i][j] = val; //change the value of the specified index to specified value
		updateConflicts(i, j, val); //update the conflicts of the specified index and value
		return true;
	}
	return false;
}


//getCell function that returns the value stored in the cell
int board::getCell(int i, int j)
// Returns the value stored in a cell.  Throws an exception
// if bad values are passed.
{
	if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
		return value[i][j];
	else
		throw rangeError("bad value in getCell");
}

//clearCell function that clears the cell
void board::clearCell(int i, int j) {
	int holder = getCell(i, j); //store the value that was in the cell before clear
	value[i][j] = blank; //clear the specified cell
	if (holder != blank) //check if there was anything in the cell before
		updateConflicts(i, j, holder); //update conflicts of the specified cell
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

//print function that prints out the board size and each of the vectors
void board::print(std::ofstream& fout)
{
	for (int i = 1; i <= boardSize; i++)
	{
		if ((i - 1) % squareSize == 0)
		{
			fout << " -";
			for (int j = 1; j <= boardSize; j++)
				fout << "---";
			fout << "-";
			fout << endl;
		}
		for (int j = 1; j <= boardSize; j++)
		{
			if ((j - 1) % squareSize == 0)
				fout << "|";
			if (!isBlank(i, j))
				fout << " " << getCell(i, j) << " ";
			else
				fout << "   ";
		}
		fout << "|";
		fout << endl;
	}

	fout << " -";
	for (int j = 1; j <= boardSize; j++)
		fout << "---";
	fout << "-";
	fout << endl;
}


//print Conflicts function
void board::printConflicts(std::ofstream & fout) {
	fout << "row conflicts" << std::endl; 
	for (int i = 1; i < boardSize + 1; i++) { //iterate over row conflict matrix
		for (int j = 1; j < boardSize + 1; j++) {
			fout << rows[i][j] << " "; //print the conflict value with a space after it
		}
		fout << std::endl; //new line after every row of the matrix
	}
	fout << "column conflicts" << std::endl;
	for (int i = 1; i < boardSize + 1; i++) { //iterate over the column conflict matrix
		for (int j = 1; j < boardSize + 1; j++) {
			fout << columns[i][j] << " "; //print the conflict value with a space after
		}
		fout << std::endl; //new line after every row of the matrix
	}
	fout << "square conflicts" << std::endl;
 	for (int i = 1; i < boardSize + 1; i++) { //iterate over the square conflict matrix
		for (int j = 1; j < boardSize + 1; j++) {
			fout << squares[i][j] << " "; //print the conflict value with a space
		}
		fout << std::endl; //new line after every row of the matrix
	}
}


void board::updateConflicts(int i, int j, int value) {
	if (getCell(i, j) != blank) { //if the cell has a value, then conflicts need to be add
		rows[i][value] = true; //set the specified row, column, and square to true because there are conflicts
		columns[j][value] = true;
		squares[squareNumber(i, j)][value] = true;
	}
	else { //if the cell is blank, then conflicts need to be removed
		rows[i][value] = false; //set the specified row, column, and square to false because there aren't conflicts
		columns[j][value] = false;
		squares[squareNumber(i, j)][value] = false;
	}
}

bool board::checkConflicts(int i, int j, int value) {
	if (rows[i][value] || columns[j][value] || squares[squareNumber(i, j)][value]) //if any of the matrices has a with the specified value at the specified index
		return true; //return true because there is a conflict
	return false; //return false if there weren't any conflicts
}


//checksolved function
bool board::checkSolved() {
	for (int i = 1; i < b.boardSize + 1; i++) { //iterate over ever conflict matrix
		for (int j = 1; j < b.boardSize + 1; j++) {
			if (b.getCell(i, j) == b.blank) //if any of the cells in the board are blank
				return false; //the board isnt solved
		}
	}
	return true; //if all cells are not blank, the board is solved
}


void board::solve() {
    /*this function solves the suduko board using recursvie calls and backtracking
     * number of recursive calls used will be stored in numCalls variable */
    int row = 0;
    int col = 0;
    int solved = false;

    //find first blank spot
    while(!isBlank(row,col)){
        if(col == 8){
            col = 0;
            row++;
        }
        else{
            col++;
        }
    }

    solved = this->solveRecursive(row, col);
    numCalls++; //increase the recursion count by one.

    if (solved){
        cout << "Suduko board has been solved!" << endl;
    }
    else{
        cout << "ERROR: Suduko board could not be solved. :( " << endl;
    }


}

bool board::solveRecursive(int row, int col){
    numCalls++; //increase the recursive count by 1

    

}
