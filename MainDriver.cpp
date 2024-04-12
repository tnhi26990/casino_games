#include <iostream>
#include "Player.h"
#include "Mines/Controller/MinesController.h"
#include "ControllerInterface.h"

int main() {
    Player* player = new Player();
    ControllerInterface* minesController = new MinesController(player);
    ControllerInterface* playerController = nullptr;

    std::cout << "Welcome to the casino!" << std::endl;
    std::cout<< "Please select a game: "<< std::endl;

    bool playingFlag = false;

    playerController = minesController;
    playerController->testFunction();

    delete minesController;
    delete player;

    return 0;
}
