#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include "Roulette/Controller/RouletteController.h"
#include "Mines/Controller/MinesController.h"

class ControllerInterface {
private:
    MinesController minesController;
    RouletteController rouletteController;
    Player* player;

public:
    ControllerInterface(Player* player);
    void switchToMinesGame();
    void switchToRouletteGame();
    void playMinesGame();
    void playRouletteGame();

    // Other methods for interacting with the games, such as placing bets, cashing out, etc.

};

#endif
