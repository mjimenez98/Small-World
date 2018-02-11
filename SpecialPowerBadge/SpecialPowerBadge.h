//
// Created by Miguel Jimenez on 2/8/18.
//

#ifndef SMALL_WORLD_SPECIALPOWERBADGE_H
#define SMALL_WORLD_SPECIALPOWERBADGE_H

#include <string>
#include <vector>

using namespace std;

// Coins to give
const int ALCHEMISTCOINS = 4;
const int BERSERKCOINS = 4;
const int BIVOUACKINGCOINS = 5;
const int COMMANDOCOINS = 4;
const int DIPLOMATCOINS = 5;
const int DRAGONMASTERCOINS = 5;
const int FLYINGCOINS = 5;
const int FORESTCOINS = 4;
const int FORTIFIEDCOINS = 3;
const int HEROICCOINS = 5;
const int HILLCOINS = 4;
const int MERCHANTCOINS = 2;
const int MOUNTEDCOINS = 5;
const int PILLAGINGCOINS = 5;
const int SEAFARINGCOINS = 5;
const int SPIRITCOINS = 5;
const int STOUTCOINS = 4;
const int SWAMPCOINS = 4;
const int UNDERWORLDCOINS = 5;
const int WEALTHYCOINS = 4;

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
