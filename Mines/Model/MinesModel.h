//
// Created by Adem Durakovic on 3/24/24.
//

#ifndef UNTITLED1_MINES_H
#define UNTITLED1_MINES_H
//
// Created by Adem Durakovic on 3/23/24.
//

#include <utility>
#include "../View/MinesView.h"
class MinesModel{
private:
    int totalMines;
    int totalSquares;
    double multiplier;
    int grid[5][5];  // initializes all to 0
    int bombGrid[5][5];  // initializes all to 0
    MinesView observer;

public:
    MinesModel(int mines, MinesView obs);
    ~MinesModel();

    void generateMineLocations();
    void executeRound(std::pair<int, int>);
    bool checkForBomb(int x, int y);
    void flipSquare(int x, int y);
    void displayGrid();
    void displayBombGrid();
    void reset();
    int (*returnGrid())[5]; // Corrected declaration of returnGrid function

};

#endif //UNTITLED1_MINES_H

