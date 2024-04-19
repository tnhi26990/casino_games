//
// Created by Adem Durakovic on 4/18/24.
//

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


#endif //UNTITLED_COINGAME_H
