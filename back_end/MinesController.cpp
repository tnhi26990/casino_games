//
// Created by Adem Durakovic on 4/2/24.
//
//
// Created by Adem Durakovic on 3/28/24.
//
#include "MinesController.h"
#include<utility>
MinesController::MinesController():view(), mines(5, view){

}

void MinesController::play() {
    std::pair pair = view.getPrediction();
    mines.executeRound(pair);

}