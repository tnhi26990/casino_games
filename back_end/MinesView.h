//
// Created by Adem Durakovic on 3/28/24.
//

#ifndef UNTITLED1_MINESVIEW_H
#define UNTITLED1_MINESVIEW_H

#include "CasinoGameInterface.h"
#include <random>
#include <chrono>
#include <utility>

class MinesView {

public:
    void showGrid(int gird[5][5]);
    std::pair<int, int> getPrediction();
};

#endif //UNTITLED1_MINESVIEW_H
