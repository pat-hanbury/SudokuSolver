// Project 4a- Patrick Hanbury and John Kang
// Created by Patrick on 2/25/2018.
//

#include "board.h" 

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
}





