#ifndef MINES_MODEL_H
#define MINES_MODEL_H

#include <utility>
#include "../View/MinesView.h"

class MinesModel{
private:
    int totalMines;
    int totalSquares;
    int payOut;
    double multiplier;

public:
    MinesModel(int mines);
    ~MinesModel();
    int getPayOut();
    void initPayout(int);
    void executeWin(int, int);
    void executeLoss();
    void generateMineLocations();
    bool checkForBomb(int x, int y);
    void flipSquare(int x, int y);
    double returnMultiplier();
    void reset();
    int (*returnGrid())[5]; // Corrected declaration of returnGrid function

    int bombGrid[5][5];
    int grid[5][5];
};

#endif