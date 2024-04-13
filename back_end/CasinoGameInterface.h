//
// Created by Adem Durakovic on 2/17/24.
//

#ifndef CASINOGAMEINTERFACE_H
#define CASINOGAMEINTERFACE_H

class CasinoGameInterface {
public:
    virtual double executeRound(bool prediction) = 0; // Pure virtual function
    // Add more virtual functions or member variables if needed
};


#endif
