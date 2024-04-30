#include "Player.h"
#include <iostream>

// Constructor definition
Player::Player() : credits(5000), casino(nullptr), betAmount(0), playing(false){}

// Other member function definitions remain unchanged
void Player::registerCasino(Casino* casinoObs) {
    casino = casinoObs;
}

int Player::getBet() {
    return betAmount;
}

bool Player::isPlaying(){
    return playing;
}

bool Player::setPlaying(bool play){
    playing = play;
}

int Player::setBet(int bet) {
    this->credits -= bet;
    this->betAmount = bet;
}

void Player::updateCredits(int money) {
    this->credits += money;    
}

int Player::getCredits() {
    return credits;
}

void Player::printCredits() {
    std::cout << "You have " << this->credits << " credits." << std::endl;
}

Player::~Player() {
    // Perform any cleanup here if needed
}