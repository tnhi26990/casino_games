#include "RouletteView.h"

void RouletteView::printMap(const std::unordered_map<int, std::list<std::pair<int, int> > >& lookupTable) {
    for (auto& entry : lookupTable) {
        std::cout << "Key: " << entry.first << ", Values: ";
        for (auto& value : entry.second) {
            std::cout << "(" << value.first << ", " << value.second << ") ";
        }
        std::cout << std::endl;
    }
}

// Outputs to the termial a roulette board that the player will reference to place bets
void RouletteView::displayBettingTable() {
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 17; k++) {
            std::cout << "[" << bettingGrid[i][k] << "], ";
        }
        std::cout << std::endl;
    }
}