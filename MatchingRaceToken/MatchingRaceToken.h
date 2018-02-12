//
// Created by Miguel Jimenez on 2/6/18.
//

#ifndef SMALL_WORLD_MATCHINGRACETOKEN_H
#define SMALL_WORLD_MATCHINGRACETOKEN_H

#include <string>

using namespace std;

const int MAXOFRACETOKENS = 10;

class MatchingRaceToken {
public:
    MatchingRaceToken(string newType, int newQuantity);
    void activate();

private:
    string type;
    int quantity;

};

#endif //SMALL_WORLD_MATCHINGRACETOKEN_H
