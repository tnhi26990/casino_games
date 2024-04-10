#include <iostream>
#include "Controller/RouletteController.h"
#include "../Player.h"

int main() {
    Player* testPlayer = new Player();
    RouletteController* rouletteController = new RouletteController(testPlayer);
    bool userActive = true;

    std::cout << "Player credits" << std::endl;
    rouletteController -> testPlayerCon();

    while(userActive) {
        userActive = rouletteController->placeBets();
    }

    std::cout << "Player credits" << std::endl;
    rouletteController -> testPlayerCon();

    std::cout << "Thank you for playing!! Please come again!" << std::endl;

    delete rouletteController;

    return 0;
}