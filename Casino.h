#ifndef CASINO_H
#define CASINO_H

#include "CasinoInterface.cpp"
#include "CasinoGameInterface.h"

class Player;

class Casino : public CasinoInterface {
private:
    CasinoGameInterface* currentGame;
    Player* player;

public:
    Casino();
    ~Casino();
    void switchGame(CasinoGameInterface* game);
    void playRound(bool prediction, int bet);
    void payout(int bet, double multiplier);
    void update(int bet, bool prediction);
    void registerPlayer(Player* newPlayer);
};

#endif // CASINO_H
