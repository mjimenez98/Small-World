//
// Created by Miguel Jimenez on 2/6/18.
//

#include "MatchingRaceToken.h"

using namespace std;

MatchingRaceToken::MatchingRaceToken() {

    type = "";
    numOfTokens = -1;
    numOfStartingTroops = -1;

}

MatchingRaceToken::MatchingRaceToken(string newType, int newNumOfTokens, int newNumOfCoinsToGive) {

    type = newType;
    numOfTokens = newNumOfTokens;
    numOfStartingTroops = newNumOfCoinsToGive;

}

string MatchingRaceToken::getType() {

    return type;

}

int MatchingRaceToken::getNumOfTokens() {

    return numOfTokens;

}

int MatchingRaceToken::getNumOfStartingTroops() {

    return numOfStartingTroops;

}

void MatchingRaceToken::activate() {

    //TBD

}

void MatchingRaceToken::giveCoinsToPlayer() {

    //TBD

}

/* Prints a description of all the Matching Race Tokens created.
 *      raceTokens: vector to be described
 *      withTokens: whether the number of tokens should be returned or not */
string MatchingRaceToken::demoMatchingRaceTokens(vector<MatchingRaceToken> raceTokens, bool withTokens) {

    if(raceTokens.empty()) {
        return "ERROR";
    }
    else {

        int index = 1;
        string demo = "Matching Race Tokens:";

        if(withTokens) {

            for(MatchingRaceToken raceToken : raceTokens) {
                demo += "\n" + to_string(index) + ". " + to_string(raceToken.getNumOfTokens()) + " " + raceToken.getType();
                index++;
            }

        }
        else {

            for(MatchingRaceToken raceToken : raceTokens) {
                demo += "\n " + to_string(index++) + ". " + raceToken.getType();
            }

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

    raceTokens.emplace_back(MatchingRaceToken("Amazon", numOfAmazons, AMAZONSTART));
    raceTokens.emplace_back(MatchingRaceToken("Dwarf", numOfDwarves, DWARFSTART));
    raceTokens.emplace_back(MatchingRaceToken("Elf", numOfElves, ELFSTART));
    raceTokens.emplace_back(MatchingRaceToken("Ghoul", numOfGhouls, GHOULSTART));
    raceTokens.emplace_back(MatchingRaceToken("Giant", numOfGiants, GIANTSTART));
    raceTokens.emplace_back(MatchingRaceToken("Halfling", numOfHalflings, HALFLINGSTART));
    raceTokens.emplace_back(MatchingRaceToken("Human", numOfHumans, HUMANSTART));
    raceTokens.emplace_back(MatchingRaceToken("Orc", numOfOrcs, ORCSTART));
    raceTokens.emplace_back(MatchingRaceToken("Ratman", numOfRatmen, RATMANSTART));
    raceTokens.emplace_back(MatchingRaceToken("Skeleton", numOfSkeletons, SKELETONSTART));
    raceTokens.emplace_back(MatchingRaceToken("Sorcerer", numOfSorcerers, SORCERERSTART));
    raceTokens.emplace_back(MatchingRaceToken("Triton", numOfTritons, TRITONSTART));
    raceTokens.emplace_back(MatchingRaceToken("Troll", numOfTrolls, TROLLSTART));
    raceTokens.emplace_back(MatchingRaceToken("Wizard", numOfWizards, WIZARDSTART));

    return raceTokens;

}
