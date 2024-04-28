#include "../Model/MinesModel.h"
#include <iostream>
#include <string>
#include <cstdlib> // for rand()

MinesModel::MinesModel() {
    multiplier = 1.0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = 0;
            bombGrid[i][j] = 0;
        }
    }

    //generateMineLocations();

}
void MinesModel::setTotalMines(int mines) {
    this->totalMines = mines;
    this->totalSquares = 25 - mines;

    switch (mines) {
        case 3:
            multiplier = 1.0;
            break;
        case 5:
            multiplier = 1.3;
            break;
        case 10:
            multiplier = 1.5;
            break;
        case 15:
            multiplier = 1.7;
            break;
        case 24:
            multiplier = 10.0;
            break;
        default:
            multiplier = 1.0;
            break;
    }

    generateMineLocations();
    printGridWithBombs();
}


bool MinesModel::gridClicked(int row,int col){
    if (grid[row][col] == 1 ) {
        return true;
    }
    return false;
}

std::string MinesModel::returnGridString() {
    std::string gridStr = "";
    for (int i = 0; i< 5; i++){
        for (int j=0; j<5; j++) {
            gridStr += std::to_string(grid[i][j]);
        }
    }

    return gridStr;
}

int (*MinesModel::returnGrid())[5] {
    return grid;
}

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

bool MinesModel::checkForBomb(int x, int y) {
    std::cout<< "In check for bomb "<< bombGrid[y][x] << std::endl;
    if (bombGrid[y][x] == 1) {
        grid[y][x] =2;
        return true;
    }
    totalSquares -= 1;
    return false;
}

void MinesModel::flipSquare(int x, int y) {
    multiplier += .1;
    payOut *= multiplier;
    grid[x][y] = 1;
}

void MinesModel::reset() {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            grid[i][k] = 0;
            bombGrid[i][k] = 0;
        }
    }
    totalMines = 0;
    multiplier = 1.0;
    payOut = 0;
   // generateMineLocations();
}

void MinesModel::initPayout(int money) {
    payOut = money;
}

double MinesModel::returnMultiplier() {
    return multiplier;
}

void MinesModel::executeLoss() {
    reset();
}

void MinesModel::executeWin(int first, int second) {
    flipSquare(first, second);
}

int MinesModel::getPayOut(){
    return payOut;
}
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