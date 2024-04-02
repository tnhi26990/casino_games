//#include <iostream>
//#include "Casino.h"
//#include "Player.h"
//#include "Roulette/RouletteDriver.cpp"
//
//int main() {
//    Casino* casino = new Casino();
//
//    //make the RouletteGame
//
//    Player* player = new Player();
//    casino->registerPlayer(player);
//    player->registerCasino(casino);
//
//    bool playingFlag = false;
//
//    std::cout << "Welcome to the casino!" << std::endl;
//    std::cout<< "Please select a game: "<< std::endl;
//
//    while (playingFlag) {
//        char game;
//        std::cout<< "C: Coin Flip |||| M: Mines |||| R: Roulette: "<<std::endl;
//        std::cin >> game;
//        if(game == 'M'){
//            std::cout << "Game not ready yet, please try again later....." << std::endl;
////            casino->switchGame(mineGame);
//
//        }
//        else if (game == 'C'){
//            std::cout << "Game not ready yet, please try again later....." << std::endl;
////            casino->switchGame(coinGame);
//        }
//        else if (game == 'R') {
//            std::cout << "Game not ready yet, please try again later....." << std::endl;
//            //switch game to roulette
//        }
//        else{std::cout<<"Select C, R or M" <<std::endl; continue;}
//
//        int bet;
//        std::cout << "Enter Bet: ";
//        std::cin >> bet;
//        if (bet == 0) {
//            playingFlag = false;
//        }
//        else {
//            player->increaseBet(bet);
//            player->playRound(true);
//            player->printCredits();
//        }
//    }
//
//    delete casino;
//    delete player;
//
//    return 0;
//}