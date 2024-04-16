#ifndef MINES_VIEW_H
#define MINES_VIEW_H

#include <random>
#include <chrono>
#include <utility>

class MinesView {

public:
    virtual void showGrid(int gird[5][5]);
    std::pair<int, int> getPrediction();
};

#endif