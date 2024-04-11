#include "RouletteController.h"

RouletteController::RouletteController(Player* player) : ControllerInterface(player), wheel(),bettingTable(wheel), tableView(), player(player){}

bool RouletteController::placeBets() {
    bool activeRound = true;
    bool validRow = false;
    bool validCol = false;
    bool validBet = false;
    std::string row;
    std::string col;
    int betAmount;
    int rowNum;
    int colNum;

    while(activeRound) {
        tableView.displayBettingTable();
        player -> printCredits();
        std::cout << "Please select the row then column you want to bet on." << std::endl;
        std::cout << "If you are done placing bets type 'spin'" << std::endl;

        while (!validRow) {
            std::cout << "Enter Row (1-3)" << std::endl;
            std::cin >> row;
            rowNum = bettingTable.handleInput(row);

            if (rowNum == -1) {
                activeRound = false;
                std::cout << "All bets are done, spin the wheel" << std::endl;
                break;
            } else if (0 <= rowNum && rowNum <= 3) {
                validRow = true;
            }
        }

        if (!activeRound) {
            break;
        }

        while (!validCol) {
            std::cout << "Enter a column (1-17)" << std::endl;
            std::cin >> col;
            colNum = bettingTable.handleInput(col);

            if (0 <= colNum && colNum <= 16) {
                validCol = true;
            }
        }

        while(!validBet) {
            std::cout << "Enter how much you want to bet: " << std::endl;
            std::cin >> betAmount;

            if(0 <= betAmount <= player -> getCredits()){
                validBet = true;
                player ->updateCredits(-betAmount);
            }
        }

        bettingTable.addPlayerBet(rowNum, colNum, betAmount);

        validBet = false;
        validCol = false;
        validRow = false;
    }

    std::cout << "Player Bets:" << std::endl;
    for (auto& bet : bettingTable.playerBets) {
        std::cout << "Grid Spot: " << bet.first.first << ", " << bet.first.second << ", Amount: " << bet.second << std::endl;
    }

    bettingTable.checkResults();

    std::string playAgain;
    std::cout << "Would you like to play another round? (y/n)" << std::endl;
    std::cin >> playAgain;

    return playAnotherRound(playAgain);
}

bool RouletteController::playAnotherRound(std::string input) {
    return ((input)[0] == 'y');
}

void RouletteController::testPlayerCon() {
    std::cout << player -> getCredits() << std::endl;
}