//
// Created by Miguel Jimenez on 2/6/18.
//

#ifndef SMALL_WORLD_MATCHINGRACETOKEN_H
#define SMALL_WORLD_MATCHINGRACETOKEN_H

#include <string>
#include <vector>

using namespace std;

// Quantity
const int AMAZONS = 15;
const int DWARVES = 8;
const int ELVES = 11;
const int GHOULS = 10;
const int GIANTS = 11;
const int HALFLINGS = 11;
const int HUMANS = 10;
const int ORCS = 10;
const int RATMEN = 13;
const int SKELETONS = 20;
const int SORCERERS = 18;
const int TRITONS = 11;
const int TROLLS = 10;
const int WIZARDS = 10;

// Coins to give
const int AMAZONSTART = 6;
const int DWARFSTART = 3;
const int ELFSTART = 6;
const int GHOULSTART = 5;
const int GIANTSTART = 6;
const int HALFLINGSTART = 6;
const int HUMANSTART = 5;
const int ORCSTART = 5;
const int RATMANSTART = 8;
const int SKELETONSTART = 6;
const int SORCERERSTART = 5;
const int TRITONSTART = 6;
const int TROLLSTART = 5;
const int WIZARDSTART = 5;

class MatchingRaceToken {

public:
    // Constructors
    MatchingRaceToken();
    MatchingRaceToken(string newType, int newNumOfTokens, int newNumOfStartingTroops);

    // Getters
    string getType();
    int getNumOfTokens();
    int getNumOfStartingTroops();

    // Other functions
    void activate();
    void giveCoinsToPlayer();
    static string demoMatchingRaceTokens(vector<MatchingRaceToken> raceTokens, bool withTokens);
    static vector<MatchingRaceToken> createMatchingRaceTokens(int numOfAmazons, int numOfDwarves, int numOfElves, int numOfGhouls,
        int numOfGiants, int numOfHalflings, int numOfHumans, int numOfOrcs, int numOfRatmen, int numOfSkeletons, int numOfSorcerers,
        int numOfTritons, int numOfTrolls, int numOfWizards);

private:
    string type;
    int numOfTokens;
    int numOfStartingTroops;

};

#endif //SMALL_WORLD_MATCHINGRACETOKEN_H
