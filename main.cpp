#include <iostream>
#include "board.h"
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <fstream>
#include <string>

void getInput(std::string boardName, vector<board>& vectorInput);

int main() {
    //initialize board

    vector<board> boardsVector;
    std::string boardName = "sudoku2.txt"; //file name of input board
    getInput(boardName, boardsVector);

    int numBoards = boardsVector.size();
    int totalCalls = 0; //total number of calls for all the boards

    //print all initial boards
    for(int i = 0; i < numBoards ; i++){
        cout << "Board Number: " << i << endl << "Unsovled Board: " << endl;
        boardsVector[i].print(); //print original board
        boardsVector[i].solve(); //solves board
        cout << "Solved Board: " << endl;
        boardsVector[i].print();
        cout << "Number of calls for Board Number " << i << " was " << boardsVector[i].numCalls << endl;

        //update total calls
        totalCalls += boardsVector[i].numCalls;
    }

    int averageCalls = totalCalls/numBoards;

    cout << endl << endl << "The average number of calls per board was " << averageCalls;


    return 0;
}


void getInput(std::string boardName, vector<board>& vectorInput){
// Read a Sudoku board from the input file.

    //declare input stream
    ifstream fin;
    //open file
    fin.open(boardName);

    if(!fin){
        cout << "ERROR: File not opened correctly." << endl;
        system("pause");
        exit(0);
    }

    char ch; //stores each character as its read in
    int boardCount = 0;

    while(fin) {
        board* boardPointer = new board;

        for (int i = 1; i <= boardPointer->boardSize; i++) {//iterate over entire board
            for (int j = 1; j <= boardPointer->boardSize; j++) {
                fin >> ch;
                if(ch == 'Z')
                {
                    return; //exit
                }
                // If the read char is not Blank
                if (ch != '.') {
                    bool test = boardPointer->setCell(i, j, int(ch - '0'));   // Convert char to int
                    if (!test) {
                        throw ("ERROR: Input board has inherent conflicts");
                        system("pause");
                        exit(0);
                    }
                } else boardPointer->clearCell(i, j); //if the read char is blank, clear the cell
            }
        }

        vectorInput.push_back(*boardPointer); //add the contents of board pointer to the board vector
    }
    fin.close();
}

