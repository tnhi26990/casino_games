#include "../Controller/MinesController.h"
#include <iostream>
#include <string>

MinesController::MinesController():view(), mines(5, view){}

bool MinesController::play() {
    bool activeRound = true;
    bool validRow = false;
    bool validCol = false;
    std::string row;
    std::string col;
    int rowNum;
    int colNum;

    while(activeRound) {
        view.showGrid(mines.grid);
        std::cout << "Please select the row then column you want to select." << std::endl;

        while (!validRow) {
            std::cout << "Enter Row (1-5)" << std::endl;
            std::cin >> rowNum;

            if (1 <= rowNum && rowNum <= 5 && mines.grid) {
                validRow = true;
                rowNum--;
            }
        }

        while (!validCol) {
            std::cout << "Enter a column (1-5)" << std::endl;
            std::cin >> colNum;

            if (1 <= colNum && colNum <= 5) {
                validCol = true;
                colNum--;
            }
        }

        if(mines.grid[rowNum][colNum] == 1){
            std::cout << "already guessed, try another spot" << std::endl;
            validCol = false;
        }

        if(validCol && validRow) {
            if (mines.checkForBomb(rowNum, colNum)){
                std::cout<< "Bomb hit." << std::endl;
                activeRound = false;
                mines.reset();
            }
            else{
                mines.flipSquare(rowNum, colNum);
            }
        }

        validCol = false;
        validRow = false;
    }

    std::string playAgain;
    std::cout << "Would you like to play another round? (y/n)" << std::endl;
    std::cin >> playAgain;

    return playAnotherRound(playAgain);
}

bool MinesController::playAnotherRound(std::string input) {
    return ((input)[0] == 'y');
}

void MinesController::showBombsLocation() {
    view.showGrid(mines.bombGrid);
}


//        if (!activeRound) {
//            break;
//        }

//        while (!validBet) {
//            std::cout << "Please enter how much you want to bet." << std::endl;
//            std::cin >> betAmount;
//            validBet = true;
//        }

//        bettingTable.addPlayerBet(rowNum, colNum, betAmount);

//        validBet = false;

//    std::cout << "Player Bets:" << std::endl;
//    for (auto& bet : bettingTable.playerBets) {
//        std::cout << "Grid Spot: " << bet.first.first << ", " << bet.first.second << ", Amount: " << bet.second << std::endl;
//    }