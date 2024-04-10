#ifndef UNTITLED1_MINESCONTROLLER_H
#define UNTITLED1_MINESCONTROLLER_H

#include "../Model/MinesModel.h"
#include "../View/MinesView.h"
#include "../../Player.h"

class MinesController {
private:
    MinesModel mines;
    MinesView view;
    Player* player;

public:
    MinesController(Player* player);
    bool play();
    bool playAnotherRound(std::string input);
    void showBombsLocation(); // for dev purposes only
    bool cashout();
    void testPlayerCon();
};

#endif
