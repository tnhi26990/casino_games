#include <iostream>
#include "Mines.h"
#include "Casino.h"
#include "MinesController.h"
int main() {

    MinesController* controller = new MinesController();
    controller->play();
    delete controller;
    controller = NULL;

    return 0;
}

