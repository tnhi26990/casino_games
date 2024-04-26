#include "../Model/MinesModel.h"
#include <iostream>
#include <string>
#include <cstdlib> // for rand()

MinesModel::MinesModel(int mines) : totalMines(mines), payOut(0) {
    multiplier = 1.0;
    totalSquares = 25 - totalMines;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = 0;
            bombGrid[i][j] = 0;
        }
    }

    generateMineLocations();

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
    if (bombGrid[x][y] == 1) {
        return true;
    }
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
    multiplier = 1.0;
    payOut = 0;
    generateMineLocations();
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

MinesModel::~MinesModel() {}