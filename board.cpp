// Project 4b- Patrick Hanbury and John Kang
// Created by Patrick on 2/25/2018.
// TRIAL

#include "board.h"

//Board constructor that initializes the value matrix to 9x9
board::board()
{
	value.resize(boardSize + 1, boardSize + 1);
	//initialize conflict matrices to 9 X 9
	//initializes the row matrices to 9 X 9 
	rows.resize(boardSize + 1, boardSize + 1);
	//initializes the column matrics to 9 X 9 
	columns.resize(boardSize + 1, boardSize + 1);
	//initiazlies the squares matrics to 9 x 9
	squares.resize(boardSize + 1, boardSize + 1);
}

//getInput function to read in the sudoku board from the input fil.e
void board::getInput(std::string boardName){
    //declaration of fin and the variable boardName
    ifstream fin;
    fin.open(boardName);

	//if the file is able to be opened
	//return pause
    if(!fin){
        cout << "ERROR: File not opened correctly." << endl;
        system("pause");
        exit(0);
    }
	//assign variable ch for each variable stored as its read in.
	//clear the board
	char ch; 
	clear();
	
	//for statement that iterates over th entire board
	for (int i = 1; i <= boardSize; i++){
		for (int j = 1; j <= boardSize; j++)
		{
			fin >> ch;
			// If statement that compares if the read char is not Blank
			if (ch != '.')
			{	
				//calls the setCell function and converts the character into an integer
				bool test = setCell(i, j, int(ch - '0'));   
                //if unable to convert the character into an integer then throw an error
                //return system pause
				if (!test){
                    throw("ERROR: Input board has inherent conflicts");
                    system("pause");
                    exit(0);
                    }
			}
			
			//else statement that can clear the cell, otherwise
			else clearCell(i, j); 
		}
	}
	//close the file
    fin.close();
}

//squareNumber function that returns the squzrenumber of the cell
int board::squareNumber(int i, int j)
{
	//these show the x-y coordinates of the square that the cell is in. 
	return squareSize * ((i - 1) / squareSize) + (j - 1) / squareSize + 1;
}

//clear function that clears the entire board.
void board::clear()
{
	//for statement that iterates over the matrix
	for (int i = 1; i <= boardSize; i++){ 
		for (int j = 1; j <= boardSize; j++){
			//sets the value to blank
			value[i][j] = blank; //set every value to blank
			//set each of the rows and columns and squares to 0. 
			rows[i][j] = 0;
			columns[i][j] = 0;
			squares[i][j] = 0;

		}
	}
}

//setCell function that is able to update conflicts
bool board::setCell(int i, int j, int val)
{
	//if statement that checks if there are conflicts for the value. 
	if (!checkConflicts(i, j, val)) { 
		//update the value of the cell to the identified value
		value[i][j] = val; 
		//update the conflicts of the cell and value.
		updateConflicts(i, j, val); 
		//return true
		return true;
	}
	//return false otherwise
	return false;
}

//getCell function that returns the value stored in the cell
int board::getCell(int i, int j)
{
	//if statement that compares the rows and columns to the boardSize
    if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
        //Simply returns the value of the cell
		return value[i][j];
    //else statement that throws an error otherwise. 
	else {
        cout << "error in getCell" << endl;
        throw rangeError("bad value in getCell");
    }
}

//clearCell function that clears the cell
void board::clearCell(int i, int j) {
	//stores the value in the cell before the clear. 
	int holder = getCell(i, j); //store the value that was in the cell before clear
	//clears the specified cell of blank.
	value[i][j] = blank; 
	//if statement that checks to see if there was anything in the cell beore
	if (holder != blank) 
		//calls the updateConflicts to update the conflicts
		updateConflicts(i, j, holder); 
}

//bool function that checks to see if the board is blank
bool board::isBlank(int i, int j){
	//if statement that checks to see if the cell is blank or not.
	if (i < 1 || i > boardSize || j < 1 || j > boardSize) {
        //throws error
        cout << endl << "i = " << i << "j = " << j << endl;
        throw rangeError("Bad Value");
    }
	//if statement that checks to see if cell or true
	if (value[i][j] == blank){
		//return true
		return true;
	}
	//else return false
	return false;
}

//print function that prints out the board size and each of the vectors
void board::print()
{
	for (int i = 1; i <= boardSize; i++)
	{
		if ((i - 1) % squareSize == 0)
		{
			cout << " -";
			for (int j = 1; j <= boardSize; j++)
				cout << "---";
			cout << "-";
			cout << endl;
		}
		for (int j = 1; j <= boardSize; j++)
		{
			if ((j - 1) % squareSize == 0)
				cout << "|";
			if (!isBlank(i, j))
				cout << " " << getCell(i, j) << " ";
			else
				cout << "   ";
		}
		cout << "|";
		cout << endl;
	}

	cout << " -";
	for (int j = 1; j <= boardSize; j++)
		cout << "---";
	cout << "-";
	cout << endl;
}


//print Conflicts function
void board::printConflicts(std::ofstream & fout) {
	//returns fout for the conflicts
	fout << "row conflicts" << std::endl;
	//iterates over the row conflict matrices 
	for (int i = 1; i < boardSize + 1; i++) { 
		for (int j = 1; j < boardSize + 1; j++) {
			//print the conflict value with a space after it
			fout << rows[i][j] << " "; 
		}
		//new line after every matrix row
		fout << std::endl; 
	}
	//returns fout for the conflicts columns
	fout << "column conflicts" << std::endl;
	//iterate over the column conflict matrix
	for (int i = 1; i < boardSize + 1; i++) { 
		for (int j = 1; j < boardSize + 1; j++) {
			//print the conflict value with a space after
			fout << columns[i][j] << " "; 
		}
		//new line after every row of the matrix
		fout << std::endl; 
	}
	//returns fout for the square conflicts
	fout << "square conflicts" << std::endl;
	//iterate over the square conflict matrix
 	for (int i = 1; i < boardSize + 1; i++) { 
		for (int j = 1; j < boardSize + 1; j++) {
			//print the conflict value with a space
			fout << squares[i][j] << " "; 
		}
		//new line after every row of the matrix
		fout << std::endl; 
	}
}

//updateconflicts function that takes in 3 arguements
void board::updateConflicts(int i, int j, int value){
	//if statement that checks to see if the cell has a value
	if (getCell(i, j) != blank) { 
		//if conflicts exist then sets the specified row, column, and square to true
		//applied for rows, columns, and square
		rows[i][value] = true; 
		columns[j][value] = true;
		squares[squareNumber(i, j)][value] = true;
	}
	//else statement that chceks to see if the cell has a value or not.
	else { 
		//because the cells are blank, sets to false.
		//applied for rows, columns, and squares. 
		rows[i][value] = false; 
		columns[j][value] = false;
		squares[squareNumber(i, j)][value] = false;
	}
}

//checkconflicts that takes in 3 arugments.
bool board::checkConflicts(int i, int j, int value) {
	//if statement that checks if any of the matrics has a specified value in its specified location.
	if (rows[i][value] || columns[j][value] || squares[squareNumber(i, j)][value]) 
		//returns true if there is a conflict
		return true; 
	//returns false if there isnt a conflict.
	return false; 
}

//checksolved function 
bool board::checkSolved(){
	//iterates over the conflict matrices
	for (int i = 1; i < boardSize + 1; i++) { 
		for (int j = 1; j < boardSize + 1; j++) {
			//if statement that calls getCell to check if the cells are blank.
			if (getCell(i, j) == blank) 
				//returns false if the board is not solved
				return false; 
		}
	}
	//returns true if the board is solved.
	return true; //if all cells are not blank, the board is solved
}


void board::solve() {
    /*this function solves the suduko board using recursvie calls and backtracking
     * number of recursive calls used will be stored in numCalls variable */
    int row = 1;
    int col = 1;
    int solved = false;

    //find first blank spot
    cout << "made it to while function" << endl;
    while(!isBlank(row,col)){
        if(col == 9){
            col = 1;
            row++;
        }
        else{
            col++;
        }
    }

	cout << "First Blank is at row: " << row << "   col: " << col << endl;

    solved = this->solveRecursive(row, col);
    numCalls++; //increase the recursion count by one.

    if (solved){
        cout << "Suduko board has been solved!" << endl;
    }
    else{
        cout << "ERROR: Suduko board could not be solved. :( " << endl;
    }
}

bool board::solveRecursive(int rowInput, int colInput){
    numCalls++; //increase the recursive count by 1
    bool solved = false; //return variable indicated if recursion was successful
    int val = 1;
	int row , col; //row and col integers for loop
	bool loopCondition = false;

    //loop will continue until branch fails (val == 9) or the board is solved
    while(val < 10 && !solved){
        if(this->setCell(rowInput,colInput,val)){ //if no conflicts, this both sets the cell and returns true
			//check if adding this value solves the board
			if(checkSolved()){
				return true;
			}
            //find next empty cell
			//first reset the row and col to be their input values
			//this insures that values are not leftover values from previous loops
			row = rowInput;
			col = colInput;

			//determine if loop will start or be skipped
			loopCondition = !this->isBlank(row,col);
            while(loopCondition){
                if(col == 9){
                    col = 1;
                    row++;
                }
                else{
                    col++;
                }
				if (row == 9 && col == 9 && !isBlank(row,col)){
					cout << "ERROR: board is full, but recursive function is returning false" << endl;
					loopCondition = false; //stop loop; at last cell
				}
				else{
					loopCondition = !isBlank(row,col);
				}

            }

			//if we are not at the end
			if (row != 9 || col !=9) {
				solved = this->solveRecursive(row, col);
			}

        }

        if (!solved){
            val++;
			this->clearCell(rowInput,colInput);
        }
    }

    //return true if recursion through this branch was successful and false if not
    return solved;

}

