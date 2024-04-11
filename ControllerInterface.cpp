//
// Created by Jack McPhillips on 4/10/24.
//
#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include "Mines/Controller/MinesController.h"
#include "Roulette/Controller/RouletteController.h"

class ControllerInterface {
private:
    MinesController minesController;
    RouletteController rouletteController;
    Player* player;

public:
    ControllerInterface(Player* player) : minesController(player), rouletteController(player), player(player) {}



    void switchToMinesGame() {
        // Implement any necessary logic to switch to the Mines game
        // For example:
        // - Hide Roulette UI
        // - Show Mines UI
    }

    void switchToRouletteGame() {
        // Implement any necessary logic to switch to the Roulette game
        // For example:
        // - Hide Mines UI
        // - Show Roulette UI
    }

    void playMinesGame() {
        switchToMinesGame();
        minesController.play();
    }

    void playRouletteGame() {
        switchToRouletteGame();
        rouletteController.placeBets();
        // In case of roulette, you might need to handle multiple rounds of betting and spinning the wheel
    }

    // Other methods for interacting with the games, such as placing bets, cashing out, etc.

};

#endif

