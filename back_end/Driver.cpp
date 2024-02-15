
#include <iostream>
#include "Casino.cpp"
using namespace std;

int main(){

    Casino* casino = new Casino(); //Makes casino
    CoinGame* coinGame = new CoinGame();
    casino->switchGame(coinGame);
    bool outcome = casino->playRound(false); //need number under .5

    delete casino;
    casino = NULL;
    delete coinGame;
    coinGame = NULL;
}
