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
const int AMAZONCOINS = 6;
const int DWARFCOINS = 3;
const int ELFCOINS = 6;
const int GHOULCOINS = 5;
const int GIANTCOINS = 6;
const int HALFLINGCOINS = 6;
const int HUMANCOINS = 5;
const int ORCCOINS = 5;
const int RATMANCOINS = 8;
const int SKELETONCOINS = 6;
const int SORCERERCOINS = 5;
const int TRITONCOINS = 6;
const int TROLLCOINS = 5;
const int WIZARDCOINS = 5;

class MatchingRaceToken {

public:
    // Constructors
    MatchingRaceToken();
    MatchingRaceToken(string newType, int newNumOfTokens, int newNumOfCoinsToGive);

    // Getters
    string getType();
    int getNumOfTokens();
    int getNumOfCoinsToGive();

    // Other functions
    void activate();
    void giveCoinsToPlayer();
    static string demoMatchingRaceTokens(vector<MatchingRaceToken> raceTokens);
    static vector<MatchingRaceToken> createMatchingRaceTokens(int numOfAmazons, int numOfDwarves, int numOfElves, int numOfGhouls,
        int numOfGiants, int numOfHalflings, int numOfHumans, int numOfOrcs, int numOfRatmen, int numOfSkeletons, int numOfSorcerers,
        int numOfTritons, int numOfTrolls, int numOfWizards);

private:
    string type;
    int numOfTokens;
    int numOfCoinsToGive;

};

#endif //SMALL_WORLD_MATCHINGRACETOKEN_H
