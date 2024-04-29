#include "RouletteWheel.h"

int RouletteWheel::generateNumber() {
    std::random_device rouletteWheel;
    std::mt19937 gen(rouletteWheel());
    std::uniform_int_distribution<int> dis(1, 38);

    return dis(gen);
}