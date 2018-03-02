//
// Created by Miguel Jimenez on 2/10/18.
//

#include "FantasyRaceBanner.h"

FantasyRaceBanner::FantasyRaceBanner() {

    raceToken = MatchingRaceToken();

}

FantasyRaceBanner::FantasyRaceBanner(MatchingRaceToken newRaceToken) {

    raceToken = newRaceToken;
    powerBadge = SpecialPowerBadge();

}

FantasyRaceBanner::FantasyRaceBanner(MatchingRaceToken newRaceToken, SpecialPowerBadge newPowerBadge) {

    raceToken = newRaceToken;
    powerBadge = newPowerBadge;

}

MatchingRaceToken FantasyRaceBanner::getRaceToken() {

    return raceToken;

}

SpecialPowerBadge FantasyRaceBanner::getPowerBadge() {

    return powerBadge;

}

void FantasyRaceBanner::setRaceToken(MatchingRaceToken newRaceToken) {

    raceToken = newRaceToken;

}

void FantasyRaceBanner::setPowerBadge(SpecialPowerBadge newPowerBadge) {

    powerBadge = newPowerBadge;

}

void FantasyRaceBanner::setNumOfTokens(int newNumOfTokens) {

    raceToken.setNumOfTokens(newNumOfTokens);

}

// Prints a description of all the Fantasy Race Banners
string FantasyRaceBanner::demoFantasyRaceBanner(vector<FantasyRaceBanner> raceBanners) {

    int index = 1;

    if(raceBanners.empty()) {
        return "ERROR";
    }
    else {
        string demo = "Fantasy Race Banners:";

        for(FantasyRaceBanner raceBanner : raceBanners) {
            demo += "\n" + to_string(index++) + ". Power Badge: " +  raceBanner.getPowerBadge().getType() + " (" +
                    to_string(raceBanner.getPowerBadge().getNumOfCoinsToGive())+ "), Race Token: " +
                    raceBanner.getRaceToken().getType() + " (" + to_string(raceBanner.getRaceToken().getNumOfTokens())
                    + ")";
        }

        demo += "\n";

        return demo;


    }

}

// Creates all the Fantasy Race Banners with their respective Race Tokens and Power Badge chosen by the player
vector<FantasyRaceBanner> FantasyRaceBanner::createFantasyRaceBanners(vector<MatchingRaceToken> raceTokens,
                                                                      vector<SpecialPowerBadge> powerBadges) {

    vector<FantasyRaceBanner> raceBanners;

    for(int i=0; i<raceTokens.size(); i++) {
        raceBanners.emplace_back(FantasyRaceBanner(raceTokens[i], powerBadges[i]));
    }

    return raceBanners;

}
