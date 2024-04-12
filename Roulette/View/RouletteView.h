#ifndef ROULETTE_VIEW_H
#define ROULETTE_VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <cmath>

class RouletteView {
private:
    std::string bettingGrid[3][17];

public:
    RouletteView() {
        bettingGrid[0][0] = "3";
        bettingGrid[0][1] = "6";
        bettingGrid[0][2] = "9";
        bettingGrid[0][3] = "12";
        bettingGrid[0][4] = "15";
        bettingGrid[0][5] = "18";
        bettingGrid[0][6] = "21";
        bettingGrid[0][7] = "24";
        bettingGrid[0][8] = "27";
        bettingGrid[0][9] = "30";
        bettingGrid[0][10] = "33";
        bettingGrid[0][11] = "36";
        bettingGrid[0][12] = "1st 2 to 1";
        bettingGrid[0][13] = "1st 12";
        bettingGrid[0][14] = "1 to 18";
        bettingGrid[0][15] = "Black";
        bettingGrid[0][16] = "00";

        bettingGrid[1][0] = "2";
        bettingGrid[1][1] = "5";
        bettingGrid[1][2] = "8";
        bettingGrid[1][3] = "11";
        bettingGrid[1][4] = "14";
        bettingGrid[1][5] = "17";
        bettingGrid[1][6] = "20";
        bettingGrid[1][7] = "23";
        bettingGrid[1][8] = "26";
        bettingGrid[1][9] = "29";
        bettingGrid[1][10] = "32";
        bettingGrid[1][11] = "35";
        bettingGrid[1][12] = "2nd 2 to 1";
        bettingGrid[1][13] = "2nd 12";
        bettingGrid[1][14] = "Even";
        bettingGrid[1][15] = "Odd";
        bettingGrid[1][16] = "0";

        bettingGrid[2][0] = "1";
        bettingGrid[2][1] = "4";
        bettingGrid[2][2] = "7";
        bettingGrid[2][3] = "10";
        bettingGrid[2][4] = "13";
        bettingGrid[2][5] = "16";
        bettingGrid[2][6] = "19";
        bettingGrid[2][7] = "22";
        bettingGrid[2][8] = "25";
        bettingGrid[2][9] = "28";
        bettingGrid[2][10] = "31";
        bettingGrid[2][11] = "34";
        bettingGrid[2][12] = "3rd 2 to 1";
        bettingGrid[2][13] = "3rd 12";
        bettingGrid[2][14] = "Red";
        bettingGrid[2][15] = "19 to 36";
        bettingGrid[2][16] = "X";
    }


    void printMap(const std::unordered_map<int, std::list<std::pair<int, int> > >& lookupTable);
    void displayBettingTable();
};

#endif