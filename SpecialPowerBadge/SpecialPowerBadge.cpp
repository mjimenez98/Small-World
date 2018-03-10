//
// Created by Miguel Jimenez on 2/8/18.
//

#include "SpecialPowerBadge.h"

#include <random>   // Default random engine
#include <chrono>
#include <algorithm>

SpecialPowerBadge::SpecialPowerBadge() {

    type = "";
    numOfCoinsToGive = -1;

}

SpecialPowerBadge::SpecialPowerBadge(string newType, int newNumOfCoinsToGive) {

    type = newType;
    numOfCoinsToGive = newNumOfCoinsToGive;

}

string SpecialPowerBadge::getType() {

    return type;

}

int SpecialPowerBadge::getNumOfCoinsToGive() {

    return numOfCoinsToGive;

}

bool SpecialPowerBadge::isTaken() {

    return taken;

}

void SpecialPowerBadge::setTaken(bool isTaken) {

    taken = isTaken;

}

void SpecialPowerBadge::activate() {

    //TBD

}

// Prints a description of all the Power Badges created
string SpecialPowerBadge::demoSpecialPowerBadges(vector<SpecialPowerBadge>& badges) {

    if(badges.empty()) {
        return "ERROR";
    }
    else {

        int index = 1;
        string demo = "Special Power Badges:";

        for(SpecialPowerBadge badge : badges) {
            demo += "\n" + to_string(index++) + ". " + badge.getType();
        }

        demo += "\n";
        return demo;

    }

}

/* Sets up victory coins. The stock version of Small World has Alchemist, Berserk, Bivouack, Commando, Diplomat, Dragon Master,
 * Flying, Forest, Fortified, Heroic, Hill, Merchant, Mounted, Pillaging, Seafaring, Spirit, Stout, Swamp, Underworld and
 * Swamp */
vector<SpecialPowerBadge>* SpecialPowerBadge::createSpecialPowerBadges(int coinsAlchemist, int coinsBerserk, int coinsBivouack,
                                                              int coinsCommando, int coinsDiplomat,
                                                              int coinsDragonMaster, int coinsFlying, int coinsForest,
                                                              int coinsFortified, int coinsHeroic, int coinsHill,
                                                              int coinsMerchant, int coinsMounted, int coinsPillaging,
                                                              int coinsSeafaring, int coinsSpirit, int coinsStout,
                                                              int coinsSwamp, int coinsUnderworld, int coinsWealthy) {

    auto * badges = new vector<SpecialPowerBadge>;

    (*badges).emplace_back(SpecialPowerBadge("Alchemist", coinsAlchemist));
    (*badges).emplace_back(SpecialPowerBadge("Berserk", coinsBerserk));
    (*badges).emplace_back(SpecialPowerBadge("Bivouack", coinsBivouack));
    (*badges).emplace_back(SpecialPowerBadge("Commando", coinsCommando));
    (*badges).emplace_back(SpecialPowerBadge("Diplomat", coinsDiplomat));
    (*badges).emplace_back(SpecialPowerBadge("Dragon Master", coinsDragonMaster));
    (*badges).emplace_back(SpecialPowerBadge("Flying", coinsFlying));
    (*badges).emplace_back(SpecialPowerBadge("Forest", coinsForest));
    (*badges).emplace_back(SpecialPowerBadge("Fortified", coinsFortified));
    (*badges).emplace_back(SpecialPowerBadge("Heroic", coinsHeroic));
    (*badges).emplace_back(SpecialPowerBadge("Hill", coinsHill));
    (*badges).emplace_back(SpecialPowerBadge("Merchant", coinsMerchant));
    (*badges).emplace_back(SpecialPowerBadge("Mounted", coinsMounted));
    (*badges).emplace_back(SpecialPowerBadge("Pillaging", coinsPillaging));
    (*badges).emplace_back(SpecialPowerBadge("Seafaring", coinsSeafaring));
    (*badges).emplace_back(SpecialPowerBadge("Spirit", coinsSpirit));
    (*badges).emplace_back(SpecialPowerBadge("Stout", coinsStout));
    (*badges).emplace_back(SpecialPowerBadge("Swamp", coinsSwamp));
    (*badges).emplace_back(SpecialPowerBadge("Underworld", coinsUnderworld));
    (*badges).emplace_back(SpecialPowerBadge("Wealthy", coinsWealthy));

    //Shuffle
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle((*badges).begin(), (*badges).end(), std::default_random_engine(seed));

    return badges;

}