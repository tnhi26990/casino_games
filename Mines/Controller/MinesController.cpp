#include "../Controller/MinesController.h"
#include<utility>

MinesController::MinesController():view(), mines(5, view){

}

void MinesController::play() {
    std::pair pair = view.getPrediction();
    mines.executeRound(pair);

}