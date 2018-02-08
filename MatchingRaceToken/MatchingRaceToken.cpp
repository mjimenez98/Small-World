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

/* Sets up race tokens. The stock version of Small World has: 15 Amazons, 8 Dwarves, 11 Elves, 10 Ghouls, 13 Ratmen,
 * 20 Skeletons, 18 Sorcerers, 11 Tritons, 11 Giants, 11 Halflings, 10 Humans, 10 Orcs, 10 Trolls and 10 Wizards */
MatchingRaceToken MatchingRaceToken::createMatchingRaceTokens(int numOfAmazons, int numOfDwarves, int numOfElves, int numOfGhouls,
                                                              int numOfGiants, int numOfHalflings, int numOfHumans, int numOfOrcs,
                                                              int numOfRatmen, int numOfSkeletons, int numOfSorcerers,
                                                              int numOfTritons, int numOfTrolls, int numOfWizards) {

    MatchingRaceToken raceTokens[numOfAmazons+numOfDwarves+numOfElves+numOfGhouls+numOfGiants+numOfHalflings+numOfHumans+
    numOfOrcs+numOfRatmen+numOfSkeletons+numOfSorcerers+numOfTritons+numOfTrolls+numOfWizards];

    int index = 0;

    raceTokens[index++] = MatchingRaceToken("Amazon", numOfAmazons, AMAZONCOINS);
    raceTokens[index++] = MatchingRaceToken("Dwarf", numOfDwarves, DWARFCOINS);
    raceTokens[index++] = MatchingRaceToken("Elf", numOfElves, ELFCOINS);
    raceTokens[index++] = MatchingRaceToken("Ghoul", numOfGhouls, GHOULCOINS);
    raceTokens[index++] = MatchingRaceToken("Giant", numOfGiants, GIANTCOINS);
    raceTokens[index++] = MatchingRaceToken("Halfling", numOfHalflings, HALFLINGCOINS);
    raceTokens[index++] = MatchingRaceToken("Human", numOfHumans, HUMANCOINS);
    raceTokens[index++] = MatchingRaceToken("Orc", numOfOrcs, ORCCOINS);
    raceTokens[index++] = MatchingRaceToken("Ratman", numOfRatmen, RATMANCOINS);
    raceTokens[index++] = MatchingRaceToken("Skeleton", numOfSkeletons, SKELETONCOINS);
    raceTokens[index++] = MatchingRaceToken("Sorcerer", numOfSorcerers, SORCERERCOINS);
    raceTokens[index++] = MatchingRaceToken("Triton", numOfTritons, TRITONCOINS);
    raceTokens[index++] = MatchingRaceToken("Troll", numOfTrolls, TROLLCOINS);
    raceTokens[index++] = MatchingRaceToken("Wizard", numOfWizards, WIZARDCOINS);

    return *raceTokens;

}
