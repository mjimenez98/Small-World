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
    FantasyRaceBanner(MatchingRaceToken newRaceToken, SpecialPowerBadge newPowerBadge);

    // Getters
    MatchingRaceToken getRaceToken();
    SpecialPowerBadge getPowerBadge();

    // Setters
    void setRaceToken(MatchingRaceToken newRaceToken);
    void setPowerBadge(SpecialPowerBadge newPowerBadge);
    void setNumOfTokens(int newNumOfTokens);

    // Other functions
    static string demoFantasyRaceBanner(vector<FantasyRaceBanner> raceBanners);
    static vector<FantasyRaceBanner> createFantasyRaceBanners(vector<MatchingRaceToken> raceTokens,
                                                              vector<SpecialPowerBadge> powerBadges);

private:
    MatchingRaceToken raceToken;
    SpecialPowerBadge powerBadge;

};

#endif //SMALL_WORLD_FANTASYRACEBANNER_H
