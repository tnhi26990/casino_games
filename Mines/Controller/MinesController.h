#ifndef MINES_CONTROLLER_H
#define MINES_CONTROLLER_H

#include "../Model/MinesModel.h"
#include "../View/MinesView.h"
#include "../../Player.h"
#include "../../ControllerInterface.h"

class MinesController : public ControllerInterface {
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
