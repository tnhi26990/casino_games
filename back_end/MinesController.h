#ifndef UNTITLED1_MINESCONTROLLER_H
#define UNTITLED1_MINESCONTROLLER_H

#include "Mines.h"
#include "MinesView.h"


class MinesController {
private:
    Mines mines;
    MinesView view;
public:
    void play(); // Corrected parameter name
    MinesController(); // Controller makes the model and view.
};

#endif // UNTITLED1_MINESCONTROLLER_H
