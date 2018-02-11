//
// Created by Miguel Jimenez on 2/6/18.
//

#include "MatchingRaceToken.h"

using namespace std;

MatchingRaceToken::MatchingRaceToken() {

    type = nullptr;
    numOfTokens = -1;
    numOfCoinsToGive = -1;

}

MatchingRaceToken::MatchingRaceToken(string newType, int newNumOfTokens, int newNumOfCoinsToGive) {

    type = newType;
    numOfTokens = newNumOfTokens;
    numOfCoinsToGive = newNumOfCoinsToGive;

}

string MatchingRaceToken::getType() {

    return type;

}

int MatchingRaceToken::getNumOfTokens() {

    return numOfTokens;

}

int MatchingRaceToken::getNumOfCoinsToGive() {

    return numOfCoinsToGive;

}

void MatchingRaceToken::activate() {

    //TBD

}

void MatchingRaceToken::giveCoinsToPlayer() {

    //TBD

}

// Prints a description of all the Matching Race Tokens created
string MatchingRaceToken::demoMatchingRaceTokens(vector<MatchingRaceToken> raceTokens) {

    if(raceTokens.empty()) {
        return "ERROR";
    }
    else {
        string demo = "Matching Race Tokens:";

        for(MatchingRaceToken raceToken : raceTokens) {
            demo += "\n- " + to_string(raceToken.getNumOfTokens()) + " " + raceToken.getType();
        }

        demo += "\n";

        return demo;
    }

}

/* Sets up race tokens. The stock version of Small World has: 15 Amazons, 8 Dwarves, 11 Elves, 10 Ghouls, 13 Ratmen,
 * 20 Skeletons, 18 Sorcerers, 11 Tritons, 11 Giants, 11 Halflings, 10 Humans, 10 Orcs, 10 Trolls and 10 Wizards */
vector<MatchingRaceToken> MatchingRaceToken::createMatchingRaceTokens(int numOfAmazons, int numOfDwarves, int numOfElves, int numOfGhouls,
                                                              int numOfGiants, int numOfHalflings, int numOfHumans, int numOfOrcs,
                                                              int numOfRatmen, int numOfSkeletons, int numOfSorcerers,
                                                              int numOfTritons, int numOfTrolls, int numOfWizards) {

    vector<MatchingRaceToken> raceTokens;

    raceTokens.emplace_back(MatchingRaceToken("Amazon", numOfAmazons, AMAZONCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Dwarf", numOfDwarves, DWARFCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Elf", numOfElves, ELFCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Ghoul", numOfGhouls, GHOULCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Giant", numOfGiants, GIANTCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Halfling", numOfHalflings, HALFLINGCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Human", numOfHumans, HUMANCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Orc", numOfOrcs, ORCCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Ratman", numOfRatmen, RATMANCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Skeleton", numOfSkeletons, SKELETONCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Sorcerer", numOfSorcerers, SORCERERCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Triton", numOfTritons, TRITONCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Troll", numOfTrolls, TROLLCOINS));
    raceTokens.emplace_back(MatchingRaceToken("Wizard", numOfWizards, WIZARDCOINS));

    return raceTokens;

}
