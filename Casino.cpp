#include "Casino.h"
#include "Player.h" // Include Player header to access its members

Casino::Casino() : currentGame(nullptr), player(nullptr) {}

Casino::~Casino() = default;

void Casino::switchGame(CasinoGameInterface* game) {
    currentGame = game;
}


void Casino::playRound(bool prediction, int bet) {
    double outcomeMultiplier = currentGame->executeRound(prediction);  //will return payout or nothing
    payout(bet, outcomeMultiplier);
}

void Casino::payout(int bet, double multiplier) {
    if (player) { // Check if player is not nullptr
        player->updateCredits(bet * multiplier);
    }
}

void Casino::update(int bet, bool prediction) {
    playRound(prediction, bet);
}

void Casino::registerPlayer(Player* newPlayer) {
    player = newPlayer;
    if (player) { // Check if player is not nullptr
        player->registerCasino(this);
    }
}
