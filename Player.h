#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Casino;

class Player {
private:
    int betAmount;
    int credits;
    Casino* casino;

public:
    Player();
    int getCredits();
    int getBet();
    int setBet(int bet);
    void registerCasino(Casino* casinoObs);
    void playRound(bool prediction);
    void increaseBet(int bet);
    void updateCredits(int money);
    void printCredits();
    ~Player();
};

#endif