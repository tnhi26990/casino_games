#ifndef BETTING_TABLE_H
#define BETTING_TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <cmath>
#include <regex>
#include <vector>
#include "../Model/RouletteWheel.h"

class BettingTable {
private:
    std::unordered_map<int, std::list<std::pair<int, int> > > lookupTable;
    std::unordered_map<int, std::list<std::string > > frontendLookupTable;

    RouletteWheel wheel;
    int payoutGrid[3][17] = {
            {35, 35, 35, 35,35, 35, 35, 35,35, 35, 35, 35, 2 ,2, 1, 1, 35},
            {35, 35, 35, 35,35, 35, 35, 35,35, 35, 35, 35, 2, 2, 1, 1, 35},
            {35, 35, 35, 35,35, 35, 35, 35,35, 35, 35, 35,2, 2, 1, 1, 0},
    };

    std::list<int> frontendPayoutGrid = {35, 2, 1};

public:
    BettingTable(RouletteWheel wheel)
            : wheel(wheel) {reactAssignMapValues();}

    // methods for the termial version of the game
    void addPlayerBet(int rowNum, int colNum, int betAmount);
    int handleInput(const std::string& input);
    std::string toLowerCase(const std::string &str);
    int isEven(int num);
    int firstHalf(int num);
    int checkBlock(int num);
    int checkRow(int num);
    bool isBlack(int num);
    int checkCol(int num);
    int checkResults();
    int payout(std::pair<int, int> betSpot, int betAmount);
    std::list<std::pair<int, int> > getValues(int key);
    void assignMapValues();
    std::vector<std::pair<std::pair<int, int>, int> > playerBets;

    // methods for the front end connectivity
    int executeRound(std::string betString, int spinRes);
    std::vector<std::string> split(const std::string& s, const std::string& delimiter);
    void reactAssignMapValues();
    std::list<std::string > getFrontendValues(int key);
    int frontendPayout(std::string betSpot, int betAmount);
    int getSpinNumber();
    std::string removeLeadingSpaces(const std::string& str);
};

#endif