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
    ~Player(); // Destructor to release memory
    void registerCasino(Casino* casinoObs);
    void playRound(bool prediction);
    void increaseBet(int bet);
    void updateCredits(int money);
    void printCredits();
};

#endif // PLAYER_H
