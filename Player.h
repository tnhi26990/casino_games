#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Casino;

class Player {
private:
    int credits;
    Casino* casino;

public:
    Player();
    int getCredits();
    void registerCasino(Casino* casinoObs);
    void playRound(bool prediction);
    void increaseBet(int bet);
    void updateCredits(int money);
    void printCredits();
    ~Player();
};

#endif // PLAYER_H
