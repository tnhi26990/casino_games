#include <iostream>
#include "Casino.h"
#include "Player.h"
#include "CoinGame.cpp" // Assuming CoinGame is defined in CoinGame.h
#include "Mines.cpp"

int main() {
    Casino* casino = new Casino();
    CoinGame* coinGame =  new CoinGame();
    Mines* mineGame = new Mines(3);
    casino->switchGame(mineGame);

    Player* player = new Player();
    casino->registerPlayer(player);
    player->registerCasino(casino);


    bool flag = true;

    cout << "Welcome to the casino!" << std::endl;
    cout<< "Please select a game: "<< endl;

    while (flag) {
        char game;
        cout<< "C: Coin Flip |||| M: Mines: "<<endl;
        cin >> game;
        if(game == 'M'){
            casino->switchGame(mineGame);
        }
        else if (game == 'C'){
            casino->switchGame(coinGame);
        }
        else{cout<<"Select C or M" <<endl; continue;}

        int bet;
        std::cout << "Enter Bet: ";
        std::cin >> bet;
        if (bet == 0) {
            flag = false;
        }
        else {
            player->increaseBet(bet);
            player->playRound(true);
            player->printCredits();
        }
    }

    delete casino; // Delete dynamically allocated Casino object
    delete player; // Delete dynamically allocated Player object
    delete coinGame;
    delete mineGame;




    return 0;
}
