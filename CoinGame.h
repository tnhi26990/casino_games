#ifndef UNTITLED_COINGAME_H
#define UNTITLED_COINGAME_H

#include <iostream>
#include <random>
#include <chrono>

class CoinGame {
public:
    bool tossCoin();
    bool checkWinner(bool prediction, bool outcome);
    bool executeRound(bool prediction);
};


#endif
