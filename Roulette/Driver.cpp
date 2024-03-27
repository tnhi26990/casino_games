#include <iostream>
#include "Controller/RouletteController.h"
#include "Model/BettingTable.h"
#include "Model/RouletteWheel.h"
#include "View/RouletteView.h"

int main() {
    RouletteWheel *playerWheel = new RouletteWheel();
    BettingTable *playerTable = new BettingTable(*playerWheel);
    RouletteView *tableView = new RouletteView();
    RouletteController *player = new RouletteController(*tableView, *playerTable);
    bool userActive = true;

    player->placeBets();
    std::cout << "Thank you for playing!! Please come again!" << std::endl;

    delete playerTable;
    delete playerWheel;
    delete tableView;
    delete player;

    return 0;
}