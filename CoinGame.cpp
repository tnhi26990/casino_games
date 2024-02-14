
#include <iostream>
#include "CasinoGameInterface.cpp"
#include <random>
#include <chrono>

using namespace std;

class CoinGame : public CasinoGameInterface{
    bool tossCoin() {
        // Seed the random number generator using the high-resolution clock
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        // Define a uniform distribution over the range [0, 1]
        uniform_real_distribution<double> distribution(0.0, 1.0);\
        // Generate a random number between 0 and 1
        double random_number = distribution(rng);
        cout << random_number << endl;
        // Return true if the random number is greater than 0.5, else false
        return random_number > 0.5;
    }
    bool checkWinner(bool prediction, bool outcome){
        if(prediction == outcome){
            cout << "You Win!" << endl;
        }
        else{
            cout << "L" << endl;
        }
        return prediction == outcome;
    }
    bool executeRound(bool prediction){
        bool outcome = tossCoin();
        return checkWinner(prediction, outcome);
    }
};
