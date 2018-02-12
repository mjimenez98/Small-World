//
// Created by Miguel Jimenez on 2/8/18.
//

#include "SpecialPowerBadge.h"

SpecialPowerBadge::SpecialPowerBadge() {

    type = nullptr;
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

void SpecialPowerBadge::activate() {

    //TBD

}

void SpecialPowerBadge::giveCoinsToPlayer() {

    //TBD

}

// Prints a description of all the Power Badges created
string SpecialPowerBadge::demoSpecialPowerBadges(vector<SpecialPowerBadge> badges) {

    if(badges.empty()) {
        return "ERROR";
    }
    else {
        string demo = "Special Power Badges:";

        for(SpecialPowerBadge badge : badges) {
            demo += "\n- " + badge.getType();
        }

        demo += "\n";

        return demo;

    }

}

/* Sets up victory coins. The stock version of Small World has Alchemist, Berserk, Bivouack, Commando, Diplomat, Dragon Master,
 * Flying, Forest, Fortified, Heroic, Hill, Merchant, Mounted, Pillaging, Seafaring, Spirit, Stout, Swamp, Underworld and
 * Swamp */
vector<SpecialPowerBadge> SpecialPowerBadge::createSpecialPowerBadges(int coinsAlchemist, int coinsBerserk, int coinsBivouack,
                                                              int coinsCommando, int coinsDiplomat,
                                                              int coinsDragonMaster, int coinsFlying, int coinsForest,
                                                              int coinsFortified, int coinsHeroic, int coinsHill,
                                                              int coinsMerchant, int coinsMounted, int coinsPillaging,
                                                              int coinsSeafaring, int coinsSpirit, int coinsStout,
                                                              int coinsSwamp, int coinsUnderworld, int coinsWealthy) {

    vector<SpecialPowerBadge> badges;

    badges.emplace_back(SpecialPowerBadge("Alchemist", coinsAlchemist));
    badges.emplace_back(SpecialPowerBadge("Berserk", coinsBerserk));
    badges.emplace_back(SpecialPowerBadge("Bivouack", coinsBivouack));
    badges.emplace_back(SpecialPowerBadge("Commando", coinsCommando));
    badges.emplace_back(SpecialPowerBadge("Diplomat", coinsDiplomat));
    badges.emplace_back(SpecialPowerBadge("Dragon Master", coinsDragonMaster));
    badges.emplace_back(SpecialPowerBadge("Flying", coinsFlying));
    badges.emplace_back(SpecialPowerBadge("Forest", coinsForest));
    badges.emplace_back(SpecialPowerBadge("Fortified", coinsFortified));
    badges.emplace_back(SpecialPowerBadge("Heroic", coinsHeroic));
    badges.emplace_back(SpecialPowerBadge("Hill", coinsHill));
    badges.emplace_back(SpecialPowerBadge("Merchant", coinsMerchant));
    badges.emplace_back(SpecialPowerBadge("Mounted", coinsMounted));
    badges.emplace_back(SpecialPowerBadge("Pillaging", coinsPillaging));
    badges.emplace_back(SpecialPowerBadge("Seafaring", coinsSeafaring));
    badges.emplace_back(SpecialPowerBadge("Spirit", coinsSpirit));
    badges.emplace_back(SpecialPowerBadge("Stout", coinsStout));
    badges.emplace_back(SpecialPowerBadge("Swamp", coinsSwamp));
    badges.emplace_back(SpecialPowerBadge("Underworld", coinsUnderworld));
    badges.emplace_back(SpecialPowerBadge("Wealthy", coinsWealthy));

    return badges;

}