#include <iostream>
#include "Player.h"
#include <string>
#include "App.h"
#include "CoinGame.h"
#include "Mines/Model/MinesModel.h"
#include <typeinfo>
#include <sstream>


using namespace std;

bool startsWith(const std::string_view str, const std::string_view prefix) {
    return str.size() >= prefix.size() && str.substr(0, prefix.size()) == prefix;
}

int main() {
    Player* player = new Player();
    string playerBalance = "coinFlip";
    string game = "mines";
    int currentPayout = 0;
    int amount = 0; // Declare amount as int
    string amountToFront = "";
    CoinGame* coinGame = new CoinGame();
    MinesModel* minesGame = new MinesModel();


    struct PerSocketData {
        /* Fill with user data */
    };

    uWS::App().ws<PerSocketData>("/*", {
            .open = [](auto *ws) {
                std::cout << "Client connected" << std::endl;
            },
            .message = [&minesGame, &coinGame, &player,&currentPayout, &amountToFront, &game](auto *ws, std::string_view message, uWS::OpCode opCode) {
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
            if (game == "coin") {
                std::string type = std::string(message.substr(0, pos));  // e.g., "T" or "H"
                int value = std::stoi(std::string(message.substr(pos + 1)));  // bet amount

                // Setting user prediction
                bool prediction = (type == "T");  // true for tails, false for heads

                // Execute game round and determine outcome
                bool outcome = coinGame->executeRound(prediction);

                // Send the result back and update credits accordingly
                if (outcome == prediction) {
                    ws->send(prediction ? "1" : "0", uWS::OpCode::TEXT); // Correct prediction
                    player->updateCredits(value);
                } else {
                    ws->send(prediction ? "0" : "1", uWS::OpCode::TEXT); // Incorrect prediction
                    player->updateCredits(-value);
                }
            } else if (game == "mines"){
                if (message == "request grid") {
                    string gridString = minesGame->returnGridString();
                    string identifier = "Grid ";
                    string mes = identifier + gridString;
                    ws->send(mes, uWS::OpCode::TEXT);
                }

                if (message == "user QUIT") {
                    player->setBet(0);
                    player->setPlaying(false);
                    minesGame->executeLoss();
                }

                if (player->isPlaying() && startsWith(message, "Clicked ")){ // cell was clicked
                    int row = std::stoi(std::string(message.substr(8)));
                    int col = std::stoi(std::string(message.substr(10)));

                    if ( !(minesGame->gridClicked(row,col)) ) { // ensuring the same cell isnt clicked
                        if (minesGame->checkForBomb(row,col)) {
                            std::string lossMessage = "Player Lost " + std::to_string(row) + "," + std::to_string(col);
                            cout << "Bomb hit at: " << row << ", " << col << endl;
                            currentPayout = 0;
                            cout << "Sending loss message: " << lossMessage << endl;
                            ws->send(lossMessage, uWS::OpCode::TEXT);
                            player->setBet(0);
                            player->setPlaying(false);
                            minesGame->executeLoss();
                        } else { // did not hit a bomb
                            string rowColStr = std::to_string(row) + "," + std::to_string(col);
                            minesGame->executeWin(row, col);
                            currentPayout = currentPayout * minesGame->returnMultiplier();
                            cout << "No bomb hit" << endl;
                            std::string winMessage = "Player Wins " + std::to_string(currentPayout) + " " + rowColStr;
                            ws->send(winMessage, uWS::OpCode::TEXT);
                        }
                    }
                } else if (player->isPlaying() && startsWith(message, "cashed")) {
                    player->updateCredits(currentPayout);
                    std::string cashOutMessage = std::to_string(currentPayout) + " starting";
                    ws->send(cashOutMessage, uWS::OpCode::TEXT);
                    minesGame->reset();
                    player->setPlaying(false);
                } else if (!(player->isPlaying()) && startsWith(message, "Bet ")) {
                    std::string numbersStr = std::string(message.substr(4));
                    std::istringstream iss(numbersStr);
                    int bet, totalMines;
                    iss >> bet >> totalMines;
                    cout << "Bet: " << bet << endl;
                    cout << "Total Mines: " << totalMines << endl;
                    minesGame->setTotalMines(totalMines);
                    player->setBet(bet);
                    currentPayout = bet;
                    player->setPlaying(true);
                }
            }
            else {
                
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
    delete coinGame;

    return 0;
}

