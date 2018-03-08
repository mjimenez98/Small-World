//
// Created by Miguel Jimenez on 2/6/18.
//

#include "MatchingRaceToken.h"

#include <random>   // Default random engine
#include <chrono>
#include <algorithm>

using namespace std;

MatchingRaceToken::MatchingRaceToken() {

    type = "";
    numOfTokens = -1;
    taken = false;

}

MatchingRaceToken::MatchingRaceToken(string newType, int newNumOfTokens) {

    type = newType;
    numOfTokens = newNumOfTokens;
    taken = false;

}

string MatchingRaceToken::getType() {

    return type;

}

int MatchingRaceToken::getNumOfTokens() {

    return numOfTokens;

}

bool MatchingRaceToken::isTaken() {

    return taken;

}

void MatchingRaceToken::setNumOfTokens(int newNumOfTokens) {

    numOfTokens = newNumOfTokens;

}

void MatchingRaceToken::setTaken(bool isTaken) {

    taken = isTaken;

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
vector<MatchingRaceToken>* MatchingRaceToken::createMatchingRaceTokens(int numOfAmazons, int numOfDwarves, int numOfElves, int numOfGhouls,
                                                              int numOfGiants, int numOfHalflings, int numOfHumans, int numOfOrcs,
                                                              int numOfRatmen, int numOfSkeletons, int numOfSorcerers,
                                                              int numOfTritons, int numOfTrolls, int numOfWizards) {

    auto * raceTokens = new vector<MatchingRaceToken>;

    (*raceTokens).emplace_back(MatchingRaceToken("Amazon", numOfAmazons));
    (*raceTokens).emplace_back(MatchingRaceToken("Dwarf", numOfDwarves));
    (*raceTokens).emplace_back(MatchingRaceToken("Elf", numOfElves));
    (*raceTokens).emplace_back(MatchingRaceToken("Ghoul", numOfGhouls));
    (*raceTokens).emplace_back(MatchingRaceToken("Giant", numOfGiants));
    (*raceTokens).emplace_back(MatchingRaceToken("Halfling", numOfHalflings));
    (*raceTokens).emplace_back(MatchingRaceToken("Human", numOfHumans));
    (*raceTokens).emplace_back(MatchingRaceToken("Orc", numOfOrcs));
    (*raceTokens).emplace_back(MatchingRaceToken("Ratman", numOfRatmen));
    (*raceTokens).emplace_back(MatchingRaceToken("Skeleton", numOfSkeletons));
    (*raceTokens).emplace_back(MatchingRaceToken("Sorcerer", numOfSorcerers));
    (*raceTokens).emplace_back(MatchingRaceToken("Triton", numOfTritons));
    (*raceTokens).emplace_back(MatchingRaceToken("Troll", numOfTrolls));
    (*raceTokens).emplace_back(MatchingRaceToken("Wizard", numOfWizards));

    //Shuffle
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle((*raceTokens).begin(), (*raceTokens).end(), std::default_random_engine(seed));

    return raceTokens;

}
