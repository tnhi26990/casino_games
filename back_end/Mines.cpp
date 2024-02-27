#include "CasinoGameInterface.h"
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

class Mines : public CasinoGameInterface {
private:
    int totalMines;
    int totalSquares;
    double multiplier;
    int grid[5][5] = {};  //initializes all to 0
    int bombGrid[5][5] = {};  //initializes all to 0

public:
    Mines(int mines) : totalMines(mines) {
        // Calculate the multiplier based on the total number of mines
        multiplier = 1;
        totalSquares = 25 - totalMines;
        generateMineLocations();
    }
    ~Mines(){}

    void generateMineLocations(){
        int bombsPlaced = 0;
        while( bombsPlaced != totalMines ) {
            int x = rand() % 5;
            int y = rand() % 5;
            if ( bombGrid[x][y] != 1 ){
                bombGrid[x][y] = 1;
                bombsPlaced +=1;
            }
        }
    }

    double executeRound(bool prediction) {
        bool playingFlag = true;
        cout<< "Welcome to mines! 0 INDEXED."<<endl <<"to quit enter 100" << endl;

        cout<<endl;
        reset();
        while( playingFlag) {
            displayGrid();
            int x;
            int y;
            cout<<"Please select a row then column." <<endl;
            cin >> x;
            if ( x == 100) { return multiplier;}
            cin >> y;
            if ( checkForBomb(x, y) == false){
                flipSquare(x, y);
                totalSquares -= 1;
                if ( totalSquares == 0 ){ return multiplier; }
                multiplier += .05;
            }
            else{
                cout<< endl;
                cout<< endl;
                cout<< "BOMB HIT!" << endl;
                displayBombGrid();
                return 0;
            }

        }
    }

    bool checkForBomb(int x, int y) {
        if ( bombGrid[x][y] == 1 ){
            return true;
        }
        return false;
    }

    void flipSquare(int x, int y) {
        grid[x][y] = 1;
    }

    void displayGrid() {
        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 5; k++) {
                cout << grid[i][k] << " ";
            }
            cout << std::endl; // Print newline after each row
        }
    }

    void displayBombGrid() {
        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 5; k++) {
                cout << bombGrid[i][k] << " ";
            }
            cout << std::endl; // Print newline after each row
        }
    }

    void reset(){
        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 5; k++) {
                grid[i][k] = 0;
                bombGrid[i][k] = 0;
            }
        }
        multiplier = 1;
        generateMineLocations();
    }
};
