//
// Created by Miguel Jimenez on 3/30/18.
//

#include "Moderate.h"
#include <chrono>
#include <algorithm>
void Moderate::conquer() {

    //notify observer
    this->getObserver()->notifyAction("is conquering");

    int regionSelection = -1;
    int tokenSelection = -1;

    // CONQUER ADJACENT REGIONS

    if (raceBanner.getRaceToken().getNumOfTokens() > 0) {

        //all regions the player can pick
        vector<int> adjRegions;

        srand(time(NULL));

        cout << "Your opponent will conquer regions adjacent to the ones they own." << endl;
        cout << "Regions require 2 tokens to conquer, plus 1 for every token they currently have." << endl << endl << endl;
        cout << "Player has " << raceBanner.getRaceToken().getNumOfTokens() << " tokens" << endl;

        // Player picks regions until they have no more tokens to place
        while (raceBanner.getRaceToken().getNumOfTokens() > 0) {

            if (raceBanner.getRaceToken().getNumOfTokens() > 0) {

                // Check for a valid region selection
                do {

                    cout << "Here are your opponent's options:" << endl;

                    //if previous chosen value is in list of adjacent regions, remove it
                    if (find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end())
                        adjRegions.erase(remove(adjRegions.begin(), adjRegions.end(), regionSelection),
                                         adjRegions.end());

                    //loop through player's regions
                    for (int i = 0; i < regions.size(); i++) {

                        //loop through all regions and check if they are adjacent and not already owned
                        for (int j = 1; j < map->getNumOfRegions() + 1; ++j) {

                            if (map->isConnected(regions[i], j) &&
                                (!(find(regions.begin(), regions.end(), j) != regions.end())) &&
                                (!(find(adjRegions.begin(), adjRegions.end(), j) != adjRegions.end())))
                                adjRegions.push_back(j); //add adjacent regions to stack

                        }

                    }

                    //display available regions
                    for (int adjRegion : adjRegions) {

                        cout << "Region " << adjRegion << ", " << map->getRegionType(adjRegion) << ", "
                             << map->getTokens(adjRegion) << " tokens" << endl;

                    }

                    // Between 1 and the largest available region number
                    uniform_int_distribution<int> distributionRegion(1, *adjRegions.end());

                    // Randomly generate a number until it is one of the adjacent region options
                    do {

                        regionSelection = 1 + rand() % adjRegions[adjRegions.size()-1];

                    } while (!(find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end()));


                } while ((!(find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end())));

                // Check for a valid token selection
                do {

                    cout << "Player has " << to_string(raceBanner.getRaceToken().getNumOfTokens()) << " tokens left" << endl;
                    cout << "You opponent has chosen region " << to_string(regionSelection) << endl;
                    cout << "This region has " << map->getTokens(regionSelection) << " token(s) on it" << endl;

                    //if player doesnt have enough to conquer, roll a die
                    if (raceBanner.getRaceToken().getNumOfTokens() < (map->getTokens(regionSelection) + 2)) {

                        int roll = dice.roll();

                        cout << "Your opponent does not have enough tokens to conquer this region, so the reinforcement "
                                "die will be called:" << endl << "Player rolled a " << roll << endl;

                        if (raceBanner.getRaceToken().getNumOfTokens() + roll < (map->getTokens(regionSelection)) + 2) {

                            cout << "Player did not roll enough to conquer the region" << endl;
                            return;

                        } else {

                            cout << "This was enough to conquer the region" << endl;
                            finalizeConquer(regionSelection, tokenSelection);
                            return;

                        }

                    }

                    // Minimum of tokens to be placed by rules of the game and the player's behavior
                    tokenSelection = map->getTokens(regionSelection)+2;

                    // If the number of tokens to be place exceeds the tokens the player has, subtract 1 from the tokens to be placed
                    while (tokenSelection > raceBanner.getRaceToken().getNumOfTokens()) {
                        --tokenSelection;
                    }

                    cout << "Player has decided to place " << to_string(tokenSelection) << " tokens on region "
                         << to_string(tokenSelection) << endl << endl;

                } while (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens());

                cout << endl;
                finalizeConquer(regionSelection, tokenSelection);

            } else {
                cout << "Player has no tokens left" << endl;
            }

        }

    }   // End of if tokens > 0

    gameTurn++;

}

void Moderate::picks_race(vector<FantasyRaceBanner> &raceBanners) {

    //notify observer
    this->getObserver()->notifyAction("is picking race");

    int race = -1;
    vector<FantasyRaceBanner> availableBanners;

    // Set all fantasy banners that are not taken by other players
    for(FantasyRaceBanner raceBanner : raceBanners) {

        if(!raceBanner.isTaken())
            availableBanners.push_back(raceBanner);

    }

    availableBanners.resize(6);

    // Initialize random seed between 1 and the largest available region number
    default_random_engine generator;
    uniform_int_distribution<int> distributionBanner(1, (int) availableBanners.size());

    cout << "Your opponent will pick a race from the following list" << endl;
    cout << FantasyRaceBanner::demoFantasyRaceBanner(availableBanners) << endl;

    // Choose race
    do {

        race = distributionBanner(generator);

    } while(race < 1 || race > availableBanners.size());

    // Give coins to player
    for(int i=0; i<availableBanners.size()-race; i++)
        coins.emplace_back(VictoryCoin(1));

    // Set the player's race banner
    raceBanner.setRaceToken(availableBanners[race-1].getRaceToken());
    raceBanner.setPowerBadge(availableBanners[race-1].getPowerBadge());
    raceBanners[race-1].setTaken(true);

    //Number of starting tokens = number on race + number on badge
    raceBanner.setNumOfTokens(raceBanner.getRaceToken().getNumOfTokens()+raceBanner.getPowerBadge().getNumOfCoinsToGive());

    cout << "Player has chosen the badge " << getRaceBanner().getPowerBadge().getType() << " and the token " <<
         getRaceBanner().getRaceToken().getType() << endl << endl;

}

void Moderate::firstConquer() {

    gameTurn = 1;

    //notify observer
    this->getObserver()->notifyAction("is conquering");

    // NOTE: Lost tribes are being checked by region.tokens. LosTribeToken class should be used instead for a future release.
    setNonEmptyRegionsConqueredInTurn(0);

    vector<int> availableRegions;

    int regionSelection = -1;
    int tokenSelection = -1;


    // INTRODUCTION AND DISPLAY OF REGIONS

    cout << "It is time for your opponent to conquer!\n"
         << "The first region picked must be at the edge of the board or an external sea."
         << "\nThese are their options:" << endl;

    // Display exterior regions
    for (int i = 0; i < map->getNumOfRegions(); i++) {

        if (map->isExterior(i)) {

            availableRegions.push_back(i);

            cout << "Region " + to_string(i) + ", " + map->getRegionType(i)
                 << ", " << map->getTokens(i) << " tokens" << endl;

        }

    }
    cout << "\nRegions require 2 tokens to conquer, plus 1 for every token they currently have." << endl << endl << endl;


    // FIRST REGION SELECTION AND TOKEN PLACEMENT

    // Initialize random seed
    srand(time(NULL));

    cout << "Your opponent has " << raceBanner.getRaceToken().getNumOfTokens() << " tokens" << endl;

    // If player has tokens available
    if (raceBanner.getRaceToken().getNumOfTokens() > 0) {

        // Check for a valid region selection. For first turn, selection must be a region at the edge or an external sea.
        do {

            regionSelection = 1 + rand() % availableRegions[availableRegions.size()-1];

        } while (find(availableRegions.begin(), availableRegions.end(), regionSelection) == availableRegions.end());

        cout << "You opponent has chosen region " << to_string(regionSelection) << endl;
        cout << "This player has " + to_string(raceBanner.getRaceToken().getNumOfTokens()) + " tokens left" << endl;
        cout << "This region has " << map->getTokens(regionSelection) << " token(s) on it" << endl;

        // Minimum of tokens to be placed by rules of the game and the player's behavior
        tokenSelection = map->getTokens(regionSelection)+2;

        // If the number of tokens to be place exceeds the tokens the player has, subtract 1 from the tokens to be placed
        while (tokenSelection > raceBanner.getRaceToken().getNumOfTokens()) {
            --tokenSelection;
        }

        cout << "Player has decided to place " << to_string(tokenSelection) << " tokens on region " << to_string(tokenSelection)
             << endl << endl;

        finalizeConquer(regionSelection, tokenSelection);

    } else {
        cout << "Player has no tokens left" << endl;
    }

    conquer();

}

void Moderate::redeploy() {

    //notify observer
    this->getObserver()->notifyAction("is redeploying");

    cout << "Player has decided not to redeploy" << endl;

}

void Moderate::playerTurn(vector<FantasyRaceBanner>& raceBanners) {

    ++gameTurn;

    if(selectNewRace) {

        picks_race(raceBanners);

        selectNewRace = false;

        firstConquer();

    }
    else if (gameTurn % 3 == 0) {

        decline();

    }
    else{
        cout << "Your opponent has decided to keep their regions intact and, in consequence, skip the turn" << endl;
    }

}