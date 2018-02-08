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

void SpecialPowerBadge::activate() {

    //TBD

}

void SpecialPowerBadge::giveCoinsToPlayer() {

    //TBD

}

SpecialPowerBadge SpecialPowerBadge::createSpecialPowerBadges(int coinsAlchemist, int coinsBerserk, int coinsBivouack,
                                                              int coinsCommando, int coinsDiplomat,
                                                              int coinsDragonMaster, int coinsFlying, int coinsForest,
                                                              int coinsFortified, int coinsHeroic, int coinsHill,
                                                              int coinsMerchant, int coinsMounted, int coinsPillaging,
                                                              int coinsSeafaring, int coinsSpirit, int coinsStout,
                                                              int coinsSwamp, int coinsUnderworld, int coinsWealthy) {

    SpecialPowerBadge badges[coinsAlchemist+coinsBerserk+coinsBivouack+coinsCommando+coinsDiplomat+coinsDragonMaster+
            coinsFlying+coinsForest+coinsFortified+coinsHeroic+coinsHill+coinsMerchant+coinsMounted+coinsPillaging+
            coinsSeafaring+coinsSpirit+coinsStout+coinsSwamp+coinsUnderworld+coinsWealthy];

    int index = 0;

    badges[index++] = SpecialPowerBadge("Alchemist", coinsAlchemist);
    badges[index++] = SpecialPowerBadge("Berserk", coinsBerserk);
    badges[index++] = SpecialPowerBadge("Bivouack", coinsBivouack);
    badges[index++] = SpecialPowerBadge("Commando", coinsCommando);
    badges[index++] = SpecialPowerBadge("Diplomat", coinsDiplomat);
    badges[index++] = SpecialPowerBadge("Dragon Master", coinsDragonMaster);
    badges[index++] = SpecialPowerBadge("Flying", coinsFlying);
    badges[index++] = SpecialPowerBadge("Forest", coinsForest);
    badges[index++] = SpecialPowerBadge("Fortified", coinsFortified);
    badges[index++] = SpecialPowerBadge("Heroic", coinsHeroic);
    badges[index++] = SpecialPowerBadge("Hill", coinsHill);
    badges[index++] = SpecialPowerBadge("Merchant", coinsMerchant);
    badges[index++] = SpecialPowerBadge("Mounted", coinsMounted);
    badges[index++] = SpecialPowerBadge("Pillaging", coinsPillaging);
    badges[index++] = SpecialPowerBadge("Seafaring", coinsSeafaring);
    badges[index++] = SpecialPowerBadge("Spirit", coinsSpirit);
    badges[index++] = SpecialPowerBadge("Stout", coinsStout);
    badges[index++] = SpecialPowerBadge("Swamp", coinsSwamp);
    badges[index++] = SpecialPowerBadge("Underworld", coinsUnderworld);
    badges[index++] = SpecialPowerBadge("Wealthy", coinsWealthy);

    return *badges;

}