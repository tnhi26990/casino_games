#include <iostream>
#include "Player.h"
#include "Casino.h"
#include <string>
#include "App.h"
#include "Roulette/Model/BettingTable.h"
#include "Roulette/Model/RouletteWheel.h"
#include <typeinfo>

using namespace std;

bool startsWith(const std::string_view str, const std::string_view prefix) {
    return str.size() >= prefix.size() && str.substr(0, prefix.size()) == prefix;
}

int main() {
    Player* player = new Player();
    string playerBalance = "coinFlip";
    string game = "roulette";
    int currentPayout = 0;
    int amount = 0;
    string amountToFront = "";
    RouletteWheel* rouletteWheel = new RouletteWheel();
    BettingTable* rouletteGame = new BettingTable(*rouletteWheel);
    cout<< "starting credits : " << player->getCredits() <<endl;


    struct PerSocketData {
        /* Fill with user data */
    };

    uWS::App().ws<PerSocketData>("/*", {
            .open = [](auto *ws) {
                std::cout << "Client connected" << std::endl;
            },
            .message = [&rouletteWheel, &rouletteGame, &player,&currentPayout, &amountToFront, &game](auto *ws, std::string_view message, uWS::OpCode opCode) {
                    std::cout << "Received message from client: " << message << std::endl;

                if (message.substr(0,18) == "Button was clicked"){
                    cout<<"button clicked"<<endl;
                    std::string chipVal((message.substr(19)));
                    cout<<chipVal<<endl;
                    int chipValInt = stoi(chipVal); //converting str to int
                    player->updateCredits(-chipValInt);
                    amountToFront = std::to_string(player->getCredits());
                    ws->send(amountToFront , uWS::OpCode::TEXT);
                }
                else if (message == "hi"){

                }
                else{
                        std::string messageStr(message);
                        int spinRes = rouletteWheel ->generateNumber();
                        cout<<"Spin result is : " << spinRes <<endl;
                        int payout = rouletteGame ->executeRound(messageStr, spinRes);
                        cout<< "player payout is:" << payout << endl;
                        player->updateCredits(payout);
                        spinRes -=1;
                        ws->send(to_string(spinRes )+ " " + "slot", uWS::OpCode::TEXT);
                    }
        // Update the front end with the new credits amount
                cout<< "current credits : " << player->getCredits() <<endl;
                amountToFront = std::to_string(player->getCredits());
                ws->send(amountToFront, uWS::OpCode::TEXT);


    },


            .close = [](auto *ws, int code, std::string_view message) {
                std::cout << "Client disconnected" << std::endl;
            }
    }).listen(9001, [](auto *listen_socket) {
        if (listen_socket) {
            std::cout << "WebSocket server listening on port " << 9001 << std::endl;
        }
    }).run();

    delete player;
    delete rouletteGame;
    delete rouletteGame;

    return 0;
}