//
// Created by Miguel Jimenez on 2/10/18.
//

#ifndef SMALL_WORLD_FANTASYRACEBANNER_H
#define SMALL_WORLD_FANTASYRACEBANNER_H

#include "../MatchingRaceToken/MatchingRaceToken.h"
#include "../SpecialPowerBadge/SpecialPowerBadge.h"

#include <vector>

using namespace std;

class FantasyRaceBanner {

public:
    // Constructors
    FantasyRaceBanner();
    explicit FantasyRaceBanner(MatchingRaceToken newRaceToken);

    // Getters
    MatchingRaceToken getRaceToken();
    //SpecialPowerBadge getPowerBadge();

    // Other functions
    static string demoFantasyRaceBanner(vector<FantasyRaceBanner> raceBanners);
    static vector<FantasyRaceBanner> createFantasyRaceBanners(vector<MatchingRaceToken> raceTokens);


private:
    MatchingRaceToken raceToken;
    //SpecialPowerBadge powerBadge;


};

#endif //SMALL_WORLD_FANTASYRACEBANNER_H
