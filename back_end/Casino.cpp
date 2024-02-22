#include "Casino.h"
#include "Player.h" // Include Player header to access its members

Casino::Casino() : currentGame(nullptr), player(nullptr) {}

Casino::~Casino() {
}

void Casino::switchGame(CasinoGameInterface* game) {
    currentGame = game;
}


bool Casino::playRound(bool prediction, int bet) {
    bool outcome = currentGame->executeRound(prediction);
    if (outcome) {
        payout(bet);
    }
    return outcome;
}

void Casino::payout(int bet) {
    if (player) { // Check if player is not nullptr
        player->updateCredits(bet * 2);
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
