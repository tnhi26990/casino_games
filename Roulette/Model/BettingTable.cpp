#include "BettingTable.h"
#include <iostream>
#include <algorithm>
#include <set>

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