#include "../Model/MinesModel.h"
#include <iostream>
#include <cstdlib> // for rand()

MinesModel::MinesModel(int mines, MinesView obs) : totalMines(mines), observer(obs) {
    multiplier = 1;
    totalSquares = 25 - totalMines;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = 0;
            bombGrid[i][j] = 0;
        }
    }

    generateMineLocations();

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
    grid[x][y] = 1;
}

void MinesModel::reset() {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            grid[i][k] = 0;
            bombGrid[i][k] = 0;
        }
    }
    multiplier = 1;
    generateMineLocations();
}

void MinesModel::executeRound(std::pair<int, int> guess) {
    int x = guess.first;
    int y = guess.second;

    if (checkForBomb(x, y)){
        std::cout<< "Bomb hit.";
        reset();
    }
    else{
        flipSquare(x, y);
        multiplier += .25;
        observer.showGrid(grid);
    }
}

MinesModel::~MinesModel() {}



