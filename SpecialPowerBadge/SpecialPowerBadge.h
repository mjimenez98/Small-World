//
// Created by Miguel Jimenez on 2/8/18.
//

#ifndef SMALL_WORLD_SPECIALPOWERBADGE_H
#define SMALL_WORLD_SPECIALPOWERBADGE_H

#include <string>
#include <vector>

using namespace std;

// Tokens to give
const int ALCHEMISTTOKENS = 4;
const int BERSERKTOKENS = 4;
const int BIVOUACKINGTOKENS = 5;
const int COMMANDOTOKENS = 4;
const int DIPLOMATTOKENS = 5;
const int DRAGONMASTERTOKENS = 5;
const int FLYINGTOKENS = 5;
const int FORESTTOKENS = 4;
const int FORTIFIEDTOKENS = 3;
const int HEROICTOKENS = 5;
const int HILLTOKENS = 4;
const int MERCHANTTOKENS = 2;
const int MOUNTEDTOKENS = 5;
const int PILLAGINGTOKENS = 5;
const int SEAFARINGTOKENS = 5;
const int SPIRITTOKENS = 5;
const int STOUTTOKENS = 4;
const int SWAMPTOKENS = 4;
const int UNDERWORLDTOKENS = 5;
const int WEALTHYTOKENS = 4;

class SpecialPowerBadge {

public:
    // Constructors
    SpecialPowerBadge();
    SpecialPowerBadge(string newType, int newNumOfCoinsToGive);

    // Getters
    string getType();
    int getNumOfCoinsToGive();

    // Other functions
    void activate();
    void giveCoinsToPlayer();
    static string demoSpecialPowerBadges(vector<SpecialPowerBadge> badges);
    static vector<SpecialPowerBadge> createSpecialPowerBadges(int coinsAlchemist, int coinsBerserk, int coinsBivouack, int coinsCommando,
        int coinsDiplomat, int coinsDragonMaster, int coinsFlying, int coinsForest, int coinsFortified, int coinsHeroic,
        int coinsHill, int coinsMerchant, int coinsMounted, int coinsPillaging, int coinsSeafaring, int coinsSpirit,
        int coinsStout, int coinsSwamp, int coinsUnderworld, int coinsWealthy);

private:
    string type;
    int numOfCoinsToGive;

};

#endif //SMALL_WORLD_SPECIALPOWERBADGE_H
