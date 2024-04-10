//#include <iostream>
//#include "Controller/MinesController.h"
//#include "../Player.h"
//
//int main() {
//    Player* testPlayer = new Player();
//    MinesController* minesController = new MinesController(testPlayer);
//    bool userActive = true;
//
//    std::cout << "Bomb Location" << std::endl;
//    minesController -> showBombsLocation();
//
//    std::cout << "Player credits" << std::endl;
//    minesController -> testPlayerCon();
//
//    while(userActive) {
//        std::cout << "Guessed so far" << std::endl;
//        userActive = minesController -> play();
//    }
//
//    std::cout << "Player credits" << std::endl;
//    minesController -> testPlayerCon();
//
//    std::cout << "Thank you for playing!! Please come again!" << std::endl;
//
//    delete minesController;
//
//    return 0;
//}