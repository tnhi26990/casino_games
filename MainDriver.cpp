#include <iostream>
#include "Player.h"
#include "Casino.h"

int main() {
    Player* player = new Player();
    Casino* playerCasino = new Casino(player);
    bool playingFlag = true;

    std::string game;
    std::cout << "Welcome to the casino!" << std::endl;
    std::cout << "You have: " << player->getCredits() << " credits" << std::endl;

    while(playingFlag) {
        std::cout << "Please select a game: " << std::endl;
        std::cin >> game;

        if (game[0] == 'm') {
            playerCasino->playMines();
        } else if (game[0] == 'r') {
            playerCasino->playRoulette();
        } else {
            std::cout << "TRY AGAIN" << std::endl;
        }

        std::cout << "You have: " << player->getCredits() << " credits" << std::endl;
        std::string ans;
        std::cout << "Would you like to keep playing games? (y/n)" << std::endl;
        std::cin >> ans;

        if(ans[0] == 'n') {
            playingFlag = false;
        }
    }

    std::cout << "Thanks for coming!" << std::endl;

    delete playerCasino;
    delete player;

    return 0;
}