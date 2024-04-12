#include <iostream>
#include "Player.h"
#include "Casino.h"

int main() {
    Player* player = new Player();
    Casino* playerCasino = new Casino(player);

    std::string game;
    std::cout << "Welcome to the casino!" << std::endl;
    std::cout<< "Please select a game: "<< std::endl;
    std::cin >> game;

    if(game[0] == 'm') {
        playerCasino -> playMines();
    }
    else if(game[0] == 'r') {
        playerCasino -> playRoulette();
    }
    else {
        std::cout << "TRY AGAIN" << std::endl;
    }

    delete playerCasino;
    delete player;

    return 0;
}
