#include <iostream>
#include "Player.h"
#include "Casino.h"
#include <string>
#include "App.h"
#include "CoinGame.h"
#include <typeinfo>


using namespace std;

int main() {
    Player* player = new Player();
    string playerBalance = "coinFlip";
    string game = "coin";
    int amount = 0; // Declare amount as int
    string amountToFront = "";
    CoinGame* coinGame = new CoinGame();

    struct PerSocketData {
        /* Fill with user data */
    };

    uWS::App().ws<PerSocketData>("/*", {
            .open = [](auto *ws) {
                std::cout << "Client connected" << std::endl;
            },
            .message = [&coinGame, &playerBalance, &game, &amount, &player, &amountToFront](auto *ws, std::string_view message, uWS::OpCode opCode) {
                std::cout << "Received message from client: " << message << std::endl;

                try{
                    // Find the position of the space
                    size_t pos = message.find(' ');
                    if (pos == std::string::npos) {
                        std::cerr << "Invalid message format" << std::endl;
                        return;
                    }
                    std::string type = std::string(message.substr(0, pos));  //guess
                    int value = std::stoi(std::string(message.substr(pos + 1)));  //bet amount
                    cout<<type << " " << value <<endl;

                    //setting user prediction
                    bool prediciton;
                    if (type == "T"){ prediciton = true;}
                    else{ prediciton = false;}

                    bool outcome = coinGame->executeRound(prediciton); //flip coin and check winner
                    //send the code that matches with either h or t
                    if (outcome == true){
                        if (prediciton == true){
                            ws->send("1", uWS::OpCode::TEXT); //they chose tails, won so we send back tails
                        }
                        else{
                            ws->send("0", uWS::OpCode::TEXT);
                        }
                        player->updateCredits(value);
                    }
                    else{
                        if (prediciton == true){ //they chose heads, lost so we send back tails
                            ws->send("0", uWS::OpCode::TEXT);
                        }
                        else{
                            ws->send("1", uWS::OpCode::TEXT);
                        }
                        player->updateCredits(-value);
                    }
                }
                catch(const std::exception& e){
                    cout<<"Just user asking for credits at start"<<endl;
                }

                amount = player->getCredits();
                amountToFront = to_string(amount);
                ws->send(amountToFront, uWS::OpCode::TEXT);
                cout << player->getCredits() << endl; // Corrected syntax
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
    delete coinGame;

    return 0;
}

