#include "BettingTable.h"
#include <iostream>
#include <algorithm>
#include <set>

void BettingTable::addPlayerBet(int rowNum, int colNum, int betAmount) {
    playerBets.push_back(std::make_pair(std::make_pair(rowNum, colNum), betAmount));
}

// If the player types in spin start the round else, subtract one to account for indexing
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

//Iterates through 1-38, on each number assign all of the attributes of that number based off a list of mehtods
//These methods give a grid space that corresponds to the betting table for an easy lookup
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

//The wheel generates a number
//Using the get values method, all of the attibutes of the spin are gathered
//The users bets are matched with each attribute and if they are the same they win
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
///////////////////////////////////////
// Start of the frontend only methods//
///////////////////////////////////////

//The bet string is recivied it is split up based of the comma
//The spin number is recived and all of the attriubutes of the spin are gathered
//Each player bet is check with the spin attribute, if they are the same the player is payed out
//The total payout of all of the wins are retured to the backup so the player credits can be updated
int BettingTable::executeRound(std::string betString, int spinRes) {
    int payoutValue = 0;
    std::vector<std::string> bettingParts = split(betString, ",");
    std::list<std::string > spinAttributes = getFrontendValues(spinRes);

    for(int i = 0; i <= bettingParts.size(); i += 2) {
        for (const auto &attribute : spinAttributes) {
            std::string trimmedBet = removeLeadingSpaces(bettingParts[i]);
            if (trimmedBet == attribute) {
                std::cout << "MATCH" << std::endl;
                payoutValue += frontendPayout(trimmedBet, std::stoi(bettingParts[i + 1]));
            }
        }
    }

    return payoutValue;
}

//Matches the bet string with a value that corresponds with a payout multiplier
int BettingTable::frontendPayout(std::string betSpot, int betAmount) {
    int payoutSlot = NULL;

    if(betSpot.size() <= 2){
        payoutSlot = 0;
    }
    else if ((betSpot.size() <= 5 && betSpot != "2:1:1" && betSpot != "2:1:2" && betSpot != "2:1:3") || betSpot == "19 to 36" || betSpot == "1 to 18") {
        payoutSlot = 2;
    }
    else{
        payoutSlot = 1;
    }

    int multiplier = *std::next(frontendPayoutGrid.begin(), payoutSlot);

    return ((betAmount * multiplier) + betAmount);
}

//Get the values from the lookup table of a correspoding spin
std::list<std::string> BettingTable::getFrontendValues(int key) {
    std::list<std::string> values;
    auto it = frontendLookupTable.find(key);
    if (it != frontendLookupTable.end()) {
        values = it->second;
    }

    return values;
}

//Iterates through 1-38, on each number assign all of the attributes of that number based off a list of mehtods
//These methods give a string that corresponds to an attribute string and adds it to the map
//Map is used for fast look up
void BettingTable::reactAssignMapValues() {
    for (int i = 1; i <= 38; i++) {

        if (i == 38) {
            frontendLookupTable[i].push_back("00");
        }
        else if (i == 37) {
            frontendLookupTable[i].push_back("0");
        }
        else {
            if (isEven(i) == 0) {
                frontendLookupTable[i].push_back("Even");
            }
            else {
                frontendLookupTable[i].push_back("Odd");
            }

            if (firstHalf(i) == 0) {
                frontendLookupTable[i].push_back("1 to 18");
            }
            else {
                frontendLookupTable[i].push_back("19 to 36");
            }

            if (checkBlock(i) == 1) {
                frontendLookupTable[i].push_back("1st 12");
            }
            else if (checkBlock(i) == 2) {
                frontendLookupTable[i].push_back("2nd 12");
            }
            else {
                frontendLookupTable[i].push_back("3rd 12");
            }

            int rowNum = checkRow(i);
            if (rowNum == 0) {
                frontendLookupTable[i].push_back("2:1:1");
            }
            else if (rowNum == 1) {
                frontendLookupTable[i].push_back("2:1:2");
            }
            else {
                frontendLookupTable[i].push_back("2:1:3");
            }

            if (isBlack(i)) {
                frontendLookupTable[i].push_back("Black");
            }
            else {
                frontendLookupTable[i].push_back("Red");
            }

            frontendLookupTable[i].push_back(std::to_string(i));
        }
    }
}

std::vector<std::string> BettingTable::split(const std::string& s, const std::string& delimiter) {
    std::regex regex("\\s*" + delimiter); // Match any number of leading spaces followed by the delimiter
    std::vector<std::string> parts(
        std::sregex_token_iterator(s.begin(), s.end(), regex, -1),
        std::sregex_token_iterator()
    );
    return parts;
}

int BettingTable::getSpinNumber() {
    return wheel.generateNumber();
}

std::string BettingTable::removeLeadingSpaces(const std::string& str) {
    return std::regex_replace(str, std::regex("^\\s+"), ""); // Replace leading spaces with empty string
}