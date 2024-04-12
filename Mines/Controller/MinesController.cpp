#include "../Controller/MinesController.h"
#include <iostream>
#include <string>

MinesController::MinesController(Player* player) : view(), mines(5, view), player(player) {}

bool MinesController::play() {
    bool activeRound = true;
    bool validRow = false;
    bool validCol = false;
    bool validBet = false;
    std::string row;
    std::string col;
    int rowNum;
    int colNum;
    int betAmount;

    while(!validBet) {
        std::cout << "Enter how much you want to bet: " << std::endl;
        std::cin >> betAmount;

        if(0 <= betAmount <= player -> getCredits()){
            validBet = true;
        }
    }

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
                player -> updateCredits(-betAmount);
                activeRound = false;
                mines.reset();
            }
            else{
                std::cout<< "Safe space!" << std::endl;
                mines.flipSquare(rowNum, colNum);
            }
        }

        bool endTurn = cashout();

        if(endTurn) {
            player -> updateCredits(betAmount * mines.returnMultiplier());
            activeRound = false;
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

void MinesController::testPlayerCon() {
    std::cout << player -> getCredits() << std::endl;
}

bool MinesController::cashout() {
    std::string input;
    std::cout << "Would you like to cashout? (y/n)" << std::endl;
    std::cin >> input;
    return ((input)[0] == 'y');

}