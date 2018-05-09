//
// Created by Miguel Jimenez on 2/6/18.
//

#ifndef SMALL_WORLD_MATCHINGRACETOKEN_H
#define SMALL_WORLD_MATCHINGRACETOKEN_H

#include <string>
#include <vector>

using namespace std;

// Number of tokens in the game
const int AMAZONS_TOKENS = 15;
const int DWARVES_TOKENS = 8;
const int ELVES_TOKENS = 11;
const int GHOULS_TOKENS = 10;
const int GIANTS_TOKENS = 11;
const int HALFLINGS_TOKENS = 11;
const int HUMANS_TOKENS = 10;
const int ORCS_TOKENS = 10;
const int RATMEN_TOKENS = 13;
const int SKELETONS_TOKENS = 20;
const int SORCERERS_TOKENS = 18;
const int TRITONS_TOKENS = 11;
const int TROLLS_TOKENS = 10;
const int WIZARDS_TOKENS = 10;

// Starting tokens
const int AMAZONS_START = 6;
const int DWARVES_START = 3;
const int ELVES_START = 6;
const int GHOULS_START = 5;
const int GIANTS_START = 6;
const int HALFLINGS_START = 6;
const int HUMANS_START = 5;
const int ORCS_START = 5;
const int RATMEN_START = 8;
const int SKELETONS_START = 6;
const int SORCERERS_START = 5;
const int TRITONS_START = 6;
const int TROLLS_START = 5;
const int WIZARDS_START = 5;

class MatchingRaceToken {

public:
    // Constructors
    MatchingRaceToken();
    explicit MatchingRaceToken(string newType);
    MatchingRaceToken(string newType, int newNumOfTokens);

    // Getters
    string getType();
    int getNumOfTokens();
    bool isTaken();

    // Setters
    void setNumOfTokens(int newNumOfTokens);
    void setTaken(bool isTaken);

    // Other functions
    static string demoMatchingRaceTokens(vector<MatchingRaceToken>& raceTokens, bool withTokens);
    static vector<MatchingRaceToken>* createMatchingRaceTokens(int numOfAmazons, int numOfDwarves, int numOfElves, int numOfGhouls,
        int numOfGiants, int numOfHalflings, int numOfHumans, int numOfOrcs, int numOfRatmen, int numOfSkeletons, int numOfSorcerers,
        int numOfTritons, int numOfTrolls, int numOfWizards);

private:
    string type;
    int numOfTokens;
    bool taken;

};

#endif //SMALL_WORLD_MATCHINGRACETOKEN_H
