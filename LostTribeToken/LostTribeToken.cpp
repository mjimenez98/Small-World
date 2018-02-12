//
// Created by Miguel Jimenez on 2/6/18.
//

#include "LostTribeToken.h"

LostTribeToken::LostTribeToken() {

}

// Describes how many lost tribe tokens there are
string LostTribeToken::demoLostTribeTokens(vector<LostTribeToken> lostTribes) {

    return "Lost Tribe Tokens:\n- " + to_string(lostTribes.size()) + "\n";

}

// Sets up lost tribe tokens. The stock version of Small World has 18 lost tribe tokens
vector<LostTribeToken> LostTribeToken::createLostTribeTokens(int numOfTokens) {

    vector<LostTribeToken> lostTribes;

    for(int i=0; i<numOfTokens; i++) {
        lostTribes.emplace_back(LostTribeToken());
    }

    return lostTribes;

}