#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Casino;

class Player {
private:
    int betAmount;
    int credits;
    bool playing;
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
    bool isPlaying();
    bool setPlaying(bool);
    ~Player();
};

#endif