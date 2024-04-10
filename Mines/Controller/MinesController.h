#ifndef UNTITLED1_MINESCONTROLLER_H
#define UNTITLED1_MINESCONTROLLER_H

#include "../Model/MinesModel.h"
#include "../View/MinesView.h"

class MinesController {
private:
    MinesModel mines;
    MinesView view;

public:
    MinesController();
    bool play();
    bool playAnotherRound(std::string input);
    void showBombsLocation(); // for dev purposes only
};

#endif
