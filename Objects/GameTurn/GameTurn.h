//
// Created by Miguel Jimenez on 2/28/18.
//

#ifndef SMALL_WORLD_GAMETURN_H
#define SMALL_WORLD_GAMETURN_H

#include <string>

using namespace std;

class GameTurn {

public:
    // Constructors
    GameTurn();

    // Getters
    int getTurn();

    // Setters
    void setTurn(int newTurn);

    // Other functions
    string toString();

private:
    int turn;

};

#endif //SMALL_WORLD_GAMETURN_H
