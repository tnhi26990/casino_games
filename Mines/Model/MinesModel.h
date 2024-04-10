//
// Created by Adem Durakovic on 3/24/24.
//

#ifndef UNTITLED1_MINES_H
#define UNTITLED1_MINES_H

#include <utility>
#include "../View/MinesView.h"

class MinesModel{
private:
    int totalMines;
    int totalSquares;
    double multiplier;
    MinesView observer;

public:
    MinesModel(int mines, MinesView obs);
    ~MinesModel();

    void generateMineLocations();
    bool checkForBomb(int x, int y);
    void flipSquare(int x, int y);
    double returnMultiplier();
    void reset();
    int (*returnGrid())[5]; // Corrected declaration of returnGrid function

    int bombGrid[5][5];
    int grid[5][5];
};

#endif //UNTITLED1_MINES_H

