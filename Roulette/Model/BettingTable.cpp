#include "BettingTable.h"
#include <iostream>
#include <algorithm>
#include <set>

void BettingTable::addPlayerBet(int rowNum, int colNum, int betAmount) {
    playerBets.push_back(std::make_pair(std::make_pair(rowNum, colNum), betAmount));
}

int BettingTable::handleInput(const std::string& input) {
    if (toLowerCase(input) == "spin") {
        return -1;
    }
    return (std::stoi(input) - 1);
}

std::string BettingTable::toLowerCase(const std::string &str) {
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

void BettingTable::assignMapValues(){
    for (int i = 1; i <= 38; i++) {
        if (i == 37) {
            lookupTable[i].push_back(std::make_pair(1, 16));
        }

        if (i == 38) {
            lookupTable[i].push_back(std::make_pair(0, 16));
        }

        int resIsEven = isEven(i);
        lookupTable[i].push_back(std::make_pair(1, (14 + resIsEven)));

        int resFirstHalf = firstHalf(i);
        lookupTable[i].push_back(std::make_pair((0 + (resFirstHalf *2)), (14 + resFirstHalf)));

        int blockNum = checkBlock(i) - 1;
        lookupTable[i].push_back(std::make_pair(blockNum, 13));

        int rowNum = checkRow(i);
        lookupTable[i].push_back(std::make_pair(rowNum, 12));

        if (isBlack(i)) {
            lookupTable[i].push_back(std::make_pair(0, 15));
        } else {
            lookupTable[i].push_back(std::make_pair(2, 14));
        }

        int colNum = checkCol(i);
        lookupTable[i].push_back(std::make_pair(rowNum, colNum));
    }
}

int BettingTable::isEven(int num) {
    return (num % 2);
}

int BettingTable::firstHalf(int num) {
    if(num <= 18) {
        return 0;
    }
    else {
        return 1;
    }
}

int BettingTable::checkBlock(int num) {
    if (num <= 12) {
        return 1;
    } else if (12 < num && num <= 24) {
        return 2;
    } else {
        return 3;
    }
}

int BettingTable::checkRow(int num) {
    int rowNum = (num % 3);

    if (rowNum > 0 && rowNum % 2 == 1) {
        rowNum += 1;
    } else if (rowNum > 0 && rowNum % 2 == 0) {
        rowNum -= 1;
    }

    return rowNum;
}

bool BettingTable::isBlack(int num) {
    std::set<int> blacks;
    blacks.insert(2);
    blacks.insert(4);
    blacks.insert(6);
    blacks.insert(8);
    blacks.insert(10);
    blacks.insert(11);
    blacks.insert(13);
    blacks.insert(15);
    blacks.insert(17);
    blacks.insert(20);
    blacks.insert(22);
    blacks.insert(24);
    blacks.insert(26);
    blacks.insert(28);
    blacks.insert(29);
    blacks.insert(31);
    blacks.insert(33);
    blacks.insert(35);
    return (blacks.find(num) != blacks.end());
}

int BettingTable::checkCol(int num) {
    return (((num - 1) / 3) % 12);
}

int BettingTable::checkResults() {
    int spinResult = wheel.generateNumber();
    std::cout << "Spin was: " << spinResult << std::endl;
    std::list<std::pair<int, int> > spinAttributes = getValues(spinResult);
    int payoutValue = 0;

    for (const auto &attribute : spinAttributes) {
        for (const auto &bet : playerBets) {
            if (bet.first == attribute) {
                payoutValue += payout(bet.first, bet.second);
                std::cout << "PLAYER WON " << payoutValue << std::endl;
            }
        }
    }
    return payoutValue;
}

int BettingTable::payout(std::pair<int, int> betSpot, int betAmount) {
    return betAmount * payoutGrid[betSpot.first][betSpot.second];
}

std::list<std::pair<int, int>> BettingTable::getValues(int key) {
    std::list<std::pair<int, int>> values;
    auto it = lookupTable.find(key);
    if (it != lookupTable.end()) {
        values = it->second;
    }
    return values;
}