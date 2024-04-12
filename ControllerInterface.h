#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include "Player.h"
#include "Mines/Controller/MinesController.h"
//#include "Roulette/Controller/RouletteController.h"

class MinesController;
//class RouletteController;

class ControllerInterface {
private:
    MinesController* minesController;
//    RouletteController* rouletteController;
    Player* player;

public:
    ControllerInterface(Player* player);
    void testFunction();
};

#endif
