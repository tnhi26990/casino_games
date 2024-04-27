#include <iostream>
#include "Player.h"
#include "Casino.h"
#include <string>
#include "App.h"
#include "Roulette/Model/BettingTable.h"
#include "Roulette/Model/RouletteWheel.h"
#include <typeinfo>

using namespace std;

int main() {
    Player* player = new Player();
    string playerBalance = "coinFlip";
    string game = "coin";
    float amount = 0.0f; // Declare amount as float
    string amountToFront = "";

    struct PerSocketData {
        /* Fill with user data */
    };

    uWS::App().ws<PerSocketData>("/*", {
            .open = [](auto *ws) {
                std::cout << "Client connected" << std::endl;
            },
            .message = [&playerBalance, &game, &amount, &player, &amountToFront](auto *ws, std::string_view message, uWS::OpCode opCode) {
                std::cout << "Received message from client: " << message << std::endl;

              {
                    try {
                        amount = std::stof(std::string(message)); // Convert string to float
                        player->updateCredits(amount);
                    } catch (const std::invalid_argument &e) {
                        std::cerr << "Invalid argument: " << e.what() << std::endl;
                        // Handle invalid argument error
                    } catch (const std::out_of_range &e) {
                        std::cerr << "Out of range: " << e.what() << std::endl;
                        // Handle out of range error
                    }
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

    return 0;
}