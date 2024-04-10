#include <iostream>
#include "Controller/MinesController.h"

int main() {
    MinesController* minesController = new MinesController();
    bool userActive = true;

    std::cout << "Bomb Location" << std::endl;
    minesController -> showBombsLocation();

    while(userActive) {
        std::cout << "Guessed so far" << std::endl;
        userActive = minesController -> play();
    }

    std::cout << "Thank you for playing!! Please come again!" << std::endl;

    delete minesController;

    return 0;
}