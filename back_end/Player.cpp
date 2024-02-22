#include "Player.h"
#include <iostream>
#include "Casino.h"

// Constructor definition
Player::Player() : credits(5000), casino(nullptr), currentBet(0) {}

// Destructor definition
Player::~Player() {
    // Perform any cleanup here if needed
}

// Other member function definitions remain unchanged
void Player::registerCasino(Casino* casinoObs) {
    casino = casinoObs;
}

void Player::playRound(bool prediction) {
    if (currentBet != 0) {
        casino->update(currentBet, prediction);
        this->currentBet = 0;
    }
}

void Player::increaseBet(int bet) {
    if (bet > credits || bet <= 0) {
        std::cout << "You do not have enough for this bet." << std::endl;
    } else {
        currentBet += bet;
        credits -= bet;
    }
}

void Player::updateCredits(int money) {
    this->credits += money;
}

void Player::printCredits() {
    std::cout << "You have " << this->credits << " credits." << std::endl;
}

