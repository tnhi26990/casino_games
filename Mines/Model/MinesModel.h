#ifndef MINES_MODEL_H
#define MINES_MODEL_H

#include <utility>
#include <string>

class MinesModel{
private:
    double multiplier;
    double adder;

public:
    int payOut;
    int totalMines;
    int totalSquares;
    MinesModel();
    ~MinesModel();
    void executeWin(int, int);
    void executeLoss();
    void generateMineLocations();
    bool gridClicked(int, int);
    bool checkForBomb(int x, int y);
    void flipSquare(int x, int y);
    double returnMultiplier();
    void reset();
    int (*returnGrid())[5]; // Corrected declaration of returnGrid function
    std::string returnGridString();
    int bombGrid[5][5];
    int grid[5][5];
    void setTotalMines(int mines);
    void printGridWithBombs();
};

#endif