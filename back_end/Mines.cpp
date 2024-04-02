//
// Created by Adem Durakovic on 3/24/24.
//
#include "Mines.h"
#include <iostream>
#include <cstdlib> // for rand()

Mines::Mines(int mines, MinesView obs) : totalMines(mines), observer(obs) {
    // Calculate the multiplier based on the total number of mines
    multiplier = 1;
    totalSquares = 25 - totalMines;
    generateMineLocations();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = 0;
            bombGrid[i][j] = 0;
        }
    }
}


Mines::~Mines() {}

int (*Mines::returnGrid())[5] {
    return grid;
}


void Mines::generateMineLocations() {
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

bool Mines::checkForBomb(int x, int y) {
    if (bombGrid[x][y] == 1) {
        return true;
    }
    return false;
}

void Mines::flipSquare(int x, int y) {
    grid[x][y] = 1;
}


void Mines::reset() {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            grid[i][k] = 0;
            bombGrid[i][k] = 0;
        }
    }
    multiplier = 1;
    generateMineLocations();
}

void Mines::executeRound(std::pair<int, int> guess) {
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



