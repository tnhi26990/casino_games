#include "../Model/MinesModel.h"
#include <iostream>
#include <string>
#include <cstdlib> // for rand()

MinesModel::MinesModel() {
    multiplier = 1.0;

    // Initialize all elements of grid and bombGrid to zero
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = 0;
            bombGrid[i][j] = 0;
        }
    }

}
void MinesModel::setTotalMines(int mines) {
    this->totalMines = mines; // stores number of mines
    this->totalSquares = 25 - mines; // stores total number of open cells
    this->adder = 0.1; // base incrementer for payouts
    
    // adjusts multiplier and incrementer for payouts based on difficulty (number of mines)
    switch (mines) {
        case 3:
            multiplier = 1.0;
            adder = .01;
            break;
        case 5:
            multiplier = 1.24;
            adder = .02;
            break;
        case 10:
            multiplier = 1.3;
            adder = .03;
            break;
        case 15:
            multiplier = 1.4;
            adder = .1;
            break;
        case 24:
            multiplier = 10.0;
            adder = .1;
            break;
        default:
            multiplier = 1.0; //default case
            break;
    }

    generateMineLocations(); // generates new mine grid
    printGridWithBombs(); // prints grid with bombs for debugging purposes
}

//returns true if a bomb has been clicked
bool MinesModel::gridClicked(int row,int col){
    if (grid[row][col] == 1 ) {
        return true;
    }
    return false;
}

//returns the current state of the grid as a string for front end processing
/*
* ex: [0,1,1,1,0]
*     [0,0,1,0,1]   returns "0111000101..."
*       ...
*/
std::string MinesModel::returnGridString() {
    std::string gridStr = "";
    for (int i = 0; i< 5; i++){
        for (int j=0; j<5; j++) {
            gridStr += std::to_string(grid[i][j]);
        }
    }

    return gridStr;
}

//returns a pointer to grid array
int (*MinesModel::returnGrid())[5] {
    return grid;
}

//randomly places 1's on bomb grid, 1's represent bombs
void MinesModel::generateMineLocations() {
    int bombsPlaced = 0;
    while (bombsPlaced != totalMines) {
        int x = rand() % 5;
        int y = rand() % 5;
        if (bombGrid[x][y] != 1) {
            bombGrid[x][y] = 1;
            bombsPlaced += 1;
        }
    }
}

// checks if a bomb is at a specific grid position
bool MinesModel::checkForBomb(int x, int y) {
    std::cout<< "In check for bomb "<< bombGrid[y][x] << std::endl;
    if (bombGrid[y][x] == 1) {
        grid[y][x] = 2; // marks a 2 if the user clicked a cell with a bomb in the front end
        return true; 
    }
    totalSquares -= 1; // decrements count of open/safe cells
    return false;
}

//flips a cell, updates payout, multiplier, and grid status
void MinesModel::flipSquare(int x, int y) {
    multiplier += adder;
    payOut *= multiplier;
    grid[x][y] = 1;
}

// resets game state
void MinesModel::reset() {
    //clear all grid cells
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            grid[i][k] = 0;
            bombGrid[i][k] = 0;
        }
    }
    totalMines = 0;
    multiplier = 1.0;
    payOut = 0;
   
}

double MinesModel::returnMultiplier() {
    return multiplier;
}

//executes a losing cell click/flip
void MinesModel::executeLoss() {
    reset();
}

// executes a winning cell click/flip
void MinesModel::executeWin(int first, int second) {
    flipSquare(first, second);
}


// prints the grid and bomb positions in the terminal for debugging purposes
void MinesModel::printGridWithBombs() {
    std::cout << "Grid with Bomb Locations:" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (bombGrid[i][j] == 1) {
                std::cout << "B ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
}

MinesModel::~MinesModel() {}