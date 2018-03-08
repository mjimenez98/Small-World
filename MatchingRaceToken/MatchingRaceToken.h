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
const int AMAZON_COINS = 6;
const int DWARF_COINS = 3;
const int ELF_COINS = 6;
const int GHOUL_COINS = 5;
const int GIANT_COINS = 6;
const int HALFLING_COINS = 6;
const int HUMAN_COINS = 5;
const int ORC_COINS = 5;
const int RATMAN_COINS = 8;
const int SKELETON_COINS = 6;
const int SORCERER_COINS = 5;
const int TRITON_COINS = 6;
const int TROLL_COINS = 5;
const int WIZARD_COINS = 5;

class MatchingRaceToken {

public:
    // Constructors
    MatchingRaceToken();
    MatchingRaceToken(string newType, int newNumOfTokens);

    // Getters
    string getType();
    int getNumOfTokens();
    bool isTaken();

    // Setters
    void setNumOfTokens(int newNumOfTokens);
    void setTaken(bool isTaken);

    // Other functions
    void activate();
    void giveCoinsToPlayer();
    static string demoMatchingRaceTokens(vector<MatchingRaceToken> raceTokens, bool withTokens);
    static vector<MatchingRaceToken>* createMatchingRaceTokens(int numOfAmazons, int numOfDwarves, int numOfElves, int numOfGhouls,
        int numOfGiants, int numOfHalflings, int numOfHumans, int numOfOrcs, int numOfRatmen, int numOfSkeletons, int numOfSorcerers,
        int numOfTritons, int numOfTrolls, int numOfWizards);

private:
    string type;
    int numOfTokens;
    bool taken;

};

#endif //SMALL_WORLD_MATCHINGRACETOKEN_H
