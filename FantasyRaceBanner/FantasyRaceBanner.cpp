//
// Created by Miguel Jimenez on 2/10/18.
//

#include "FantasyRaceBanner.h"

FantasyRaceBanner::FantasyRaceBanner() {

    raceToken = MatchingRaceToken();

}

FantasyRaceBanner::FantasyRaceBanner(MatchingRaceToken newRaceToken) {

    raceToken = newRaceToken;

}

MatchingRaceToken FantasyRaceBanner::getRaceToken() {

    return raceToken;

}

// Prints a description of all the Fantasy Race Banners
string FantasyRaceBanner::demoFantasyRaceBanner(vector<FantasyRaceBanner> raceBanners) {

    if(raceBanners.empty()) {
        return "ERROR";
    }
    else {
        string demo = "Fantasy Race Banners:";

        for(FantasyRaceBanner raceBanner : raceBanners) {
            demo += "\n- Matching Race Token: " + raceBanner.getRaceToken().getType() + ", Power Badge: TBD";
        }

        demo += "\n";

        return demo;

    }

}

// Creates all the Fantasy Race Banners with their respective Race Tokens and Power Badge chosen by the player
vector<FantasyRaceBanner> FantasyRaceBanner::createFantasyRaceBanners(vector<MatchingRaceToken> raceTokens) {

    vector<FantasyRaceBanner> raceBanners;

    for(MatchingRaceToken raceToken : raceTokens) {
        raceBanners.emplace_back(FantasyRaceBanner(raceToken));
    }

    return raceBanners;

}
