#ifndef ROULETTE_CONTROLLER_H
#define ROULETTE_CONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <cmath>
#include "../Model/RouletteWheel.h"
#include "../Model/BettingTable.h"
#include "../View/RouletteView.h"

class RouletteController {
private:
    BettingTable bettingTable;
    RouletteView tableView;
    std::vector<std::pair<std::pair<int, int>, int> > playerBets;

public:
    RouletteController(RouletteView tableView, BettingTable bettingTable)
            : bettingTable(bettingTable), tableView(tableView) {}

    bool placeBets();
    static bool playAnotherRound(std::string input);
};

#endif