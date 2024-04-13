#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include "Player.h"
#include "Mines/Controller/MinesController.h"
#include "Roulette/Controller/RouletteController.h"

class MinesController;
class RouletteController;

class Casino {
private:
    MinesController* minesController;
    RouletteController* rouletteController;
    Player* player;

public:
    Casino(Player* player);
    void testFunction();
    void playMines();
    void playRoulette();
};

#endif