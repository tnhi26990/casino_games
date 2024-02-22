#include <iostream>
#include "Casino.h"
#include "Player.h"
#include "CoinGame.cpp" // Assuming CoinGame is defined in CoinGame.h

int main() {
    Casino* casino = new Casino();
    CoinGame* coinGame =  new CoinGame();
    casino->switchGame(coinGame);

    Player* player = new Player();
    casino->registerPlayer(player);
    player->registerCasino(casino);

    bool flag = true;

    std::cout << "Welcome to the casino, you are playing coin flip!" << std::endl;

    while (flag) {
        int bet;
        std::cout << "Enter Bet: ";
        std::cin >> bet;
        if (bet == 0) {
            flag = false;
        }
        else {
            player->increaseBet(bet);
            player->playRound(true);
            player->printCredits();
        }
    }

    delete casino; // Delete dynamically allocated Casino object
    delete player; // Delete dynamically allocated Player object
    delete coinGame;




    return 0;
}
