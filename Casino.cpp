//
// Created by Jack McPhillips on 4/10/24.
//
#include "Casino.h"

Casino::Casino(Player* player) : player(player) {
    // Initialize pointers to controllers
    minesController = new MinesController(player);
    rouletteController = new RouletteController(player);
}

void Casino::testFunction() {
    std::cout << "Called" << std::endl;
}

void Casino::playMines() {
    minesController -> play();
}

void Casino::playRoulette() {
    rouletteController -> placeBets();
}

//void switchToMinesGame() {
//        // Implement any necessary logic to switch to the Mines game
//        // For example:
//        // - Hide Roulette UI
//        // - Show Mines UI
//}
//
//void switchToRouletteGame() {
//        // Implement any necessary logic to switch to the Roulette game
//        // For example:
//        // - Hide Mines UI
//        // - Show Roulette UI
//}
//
//void playMinesGame() {
//    switchToMinesGame();
//    minesController.play();
//}
//
//void playRouletteGame() {
//    switchToRouletteGame();
//    rouletteController.placeBets();
//        // In case of roulette, you might need to handle multiple rounds of betting and spinning the wheel
//}


