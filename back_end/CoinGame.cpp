
#include <iostream>
#include "CasinoGameInterface.h"
#include <random>
#include <chrono>

using namespace std;

class CoinGame : public CasinoGameInterface{
    bool tossCoin() {
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());    // Seed the random number generator using the high-resolution clock
        uniform_real_distribution<double> distribution(0.0, 1.0);         // Define a uniform distribution over the range [0, 1]
        double random_number = distribution(rng);     // Generate a random number between 0 and 1

        // Return true if the random number is greater than 0.5, else false
        if ( random_number > 0.5 ) {
            cout<< "COIN FLIPPED: HEADS" << " TRUE "<< endl;
        }
        else{
            cout<< "COIN FLIPPED: TAILS" << " FALSE "<< endl;
        }
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
    double executeRound(bool prediction){
        bool predict = getPrediction();
        bool outcome = tossCoin();
        if (checkWinner(predict, outcome)){
            return 2;
        }
        return 0;
    }
    bool getPrediction(){
        char prediction;
        cout<<"Select Heads or Tails: (ENTER 'H' OR 'T')"<<endl;
        cin>>prediction;
        if (prediction == 'H') {
            return true;
        }
        return false;
    }
};
