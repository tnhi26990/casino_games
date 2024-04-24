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

    struct PerSocketData {
        /* Fill with user data */
    };

    uWS::App().ws<PerSocketData>("/*", {
            .open = [](auto *ws) {
                std::cout << "Client connected" << std::endl;
            },
            .message = [&rouletteGame, &player,&currentPayout, &amountToFront, &game](auto *ws, std::string_view message, uWS::OpCode opCode) {
    std::cout << "Received message from client: " << message << std::endl;

    try {
        // Check if message is a special command or a game command
        if (message == "starting creds") {
            // Just a user asking for credits at start
            ws->send(amountToFront + " starting", uWS::OpCode::TEXT);
        } else if(startsWith(message, "Change ")){
            game = std::string(message.substr(7));
        }else {
            // Parse the message to get the type of game action and the bet amount
            size_t pos = message.find(' ');
            if (pos == std::string::npos) {
                throw std::runtime_error("Invalid message format");
            }
            if (game == "roulette") {
                ws->send("Hello frontend this is backend", uWS::OpCode::TEXT);

                int spinRes = rouletteGame->getSpinNumber();
                ws -> send(std::to_string(spinRes), uWS::OpCode::TEXT); // send the spin val to the front end and change the stop value on front end

                int roundPayout = rouletteGame->executeRound(std::string(message), spinRes);
            }
        }

        // Update the front end with the new credits amount
        amountToFront = std::to_string(player->getCredits());
        ws->send(amountToFront, uWS::OpCode::TEXT);
    }
    catch (const std::exception& e) {
        // Log exception and send error message back to the client
        std::cerr << "Error processing message: " << e.what() << std::endl;
        ws->send("Error processing your request", uWS::OpCode::TEXT);
    }
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