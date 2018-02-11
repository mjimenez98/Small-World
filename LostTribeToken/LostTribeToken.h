//
// Created by Miguel Jimenez on 2/6/18.
//

#ifndef SMALL_WORLD_LOSTTRIBETOKEN_H
#define SMALL_WORLD_LOSTTRIBETOKEN_H

#include <string>
#include <vector>

using namespace std;

const int NUMOFLOSTTRIBETOKENS = 18;

class LostTribeToken {

public:
    // Constructors
    LostTribeToken();

    // Other functions
    static string demoLostTribeTokens(vector<LostTribeToken> lostTribes);
    static vector<LostTribeToken> createLostTribeTokens(int numOfTokens);

};

#endif //SMALL_WORLD_LOSTTRIBETOKEN_H
