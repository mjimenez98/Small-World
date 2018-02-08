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

void MatchingRaceToken::activate() {

    //TBD

}

void MatchingRaceToken::giveCoinsToPlayer() {

    //TBD

}

/* Sets up victory coins. The stock version of Small World has: 15 Amazons, 8 Dwarves, 11 Elves, 10 Ghouls, 13 Ratmen,
 * 20 Skeletons, 18 Sorcerers, 11 Tritons, 11 Giants, 11 Halflings, 10 Humans, 10 Orcs, 10 Trolls and 10 Wizards */
MatchingRaceToken MatchingRaceToken::createMatchingRaceTokens(int numOfAmazons, int numOfDwarves, int numOfElves, int numOfGhouls,
                                                              int numOfGiants, int numOfHalflings, int numOfHumans, int numOfOrcs,
                                                              int numOfRatmen, int numOfSkeletons, int numOfSorcerers,
                                                              int numOfTritons, int numOfTrolls, int numOfWizards) {

    MatchingRaceToken raceTokens[numOfAmazons+numOfDwarves+numOfElves+numOfGhouls+numOfGiants+numOfHalflings+numOfHumans+
    numOfOrcs+numOfRatmen+numOfSkeletons+numOfSorcerers+numOfTritons+numOfTrolls+numOfWizards];

    int index = 0;

    raceTokens[index++] = MatchingRaceToken("Amazon", AMAZONS, AMAZONCOINS);
    raceTokens[index++] = MatchingRaceToken("Dwarf", DWARVES, DWARFCOINS);
    raceTokens[index++] = MatchingRaceToken("Elf", ELVES, ELFCOINS);
    raceTokens[index++] = MatchingRaceToken("Ghoul", GHOULS, GHOULCOINS);
    raceTokens[index++] = MatchingRaceToken("Giant", GIANTS, GIANTCOINS);
    raceTokens[index++] = MatchingRaceToken("Halfling", HALFLINGS, HALFLINGCOINS);
    raceTokens[index++] = MatchingRaceToken("Human", HUMANS, HUMANCOINS);
    raceTokens[index++] = MatchingRaceToken("Orc", ORCS, ORCCOINS);
    raceTokens[index++] = MatchingRaceToken("Ratman", RATMEN, RATMANCOINS);
    raceTokens[index++] = MatchingRaceToken("Skeleton", SKELETONS, SKELETONCOINS);
    raceTokens[index++] = MatchingRaceToken("Sorcerer", SORCERERS, SORCERERCOINS);
    raceTokens[index++] = MatchingRaceToken("Triton", TRITONS, TRITONCOINS);
    raceTokens[index++] = MatchingRaceToken("Troll", TROLLS, TROLLCOINS);
    raceTokens[index++] = MatchingRaceToken("Wizard", WIZARDS, WIZARDCOINS);

    return *raceTokens;

}
