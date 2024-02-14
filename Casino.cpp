
#include "CoinGame.cpp"
#include <iostream>
#include "Player.cpp"
using namespace std;
class Casino{
private:
    CasinoGameInterface* currentGame = NULL;
    Player* player = NULL;
public:
    void switchGame(CasinoGameInterface* game) {
        // Delete the current game object
        delete currentGame;
        // Assign the new game object
        currentGame = game;
    }

    bool playRound(bool prediction){
        currentGame->executeRound(prediction); //simulate a round where they think true.
    }

    void registerPlayer(Player* newPlayer){
        player = newPlayer;
    }
};
