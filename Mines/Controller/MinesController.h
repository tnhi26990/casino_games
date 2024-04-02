#ifndef UNTITLED1_MINESCONTROLLER_H
#define UNTITLED1_MINESCONTROLLER_H

#include "../Model/MinesModel.h"
#include "../Model/MinesModel.h"

class MinesController {
private:
    MinesModel mines;
    MinesView view;
public:
    void play(); // Corrected parameter name
    MinesController(); // Controller makes the model and view.
};

#endif
