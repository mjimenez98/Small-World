//
// Created by Miguel Jimenez on 2/8/18.
//

#ifndef SMALL_WORLD_SPECIALPOWERBADGE_H
#define SMALL_WORLD_SPECIALPOWERBADGE_H

#include <string>
#include <vector>

using namespace std;

// Tokens to give
const int ALCHEMIST_TOKENS = 4;
const int BERSERK_TOKENS = 4;
const int BIVOUACKING_TOKENS = 5;
const int COMMANDO_TOKENS = 4;
const int DIPLOMAT_TOKENS = 5;
const int DRAGONMASTER_TOKENS = 5;
const int FLYING_TOKENS = 5;
const int FOREST_TOKENS = 4;
const int FORTIFIED_TOKENS = 3;
const int HEROIC_TOKENS = 5;
const int HILL_TOKENS = 4;
const int MERCHANT_TOKENS = 2;
const int MOUNTED_TOKENS = 5;
const int PILLAGING_TOKENS = 5;
const int SEAFARING_TOKENS = 5;
const int SPIRIT_TOKENS = 5;
const int STOUT_TOKENS = 4;
const int SWAMP_TOKENS = 4;
const int UNDERWORLD_TOKENS = 5;
const int WEALTHY_TOKENS = 4;

class SpecialPowerBadge {

public:
    // Constructors
    SpecialPowerBadge();
    SpecialPowerBadge(string newType, int newNumOfCoinsToGive);

    // Getters
    string getType();
    int getNumOfCoinsToGive();
    bool isTaken();

    // Setters
    void setTaken(bool isTaken);

    // Other functions
    void activate();
    void giveCoinsToPlayer();
    static string demoSpecialPowerBadges(vector<SpecialPowerBadge> badges);
    static vector<SpecialPowerBadge>* createSpecialPowerBadges(int coinsAlchemist, int coinsBerserk, int coinsBivouack, int coinsCommando,
        int coinsDiplomat, int coinsDragonMaster, int coinsFlying, int coinsForest, int coinsFortified, int coinsHeroic,
        int coinsHill, int coinsMerchant, int coinsMounted, int coinsPillaging, int coinsSeafaring, int coinsSpirit,
        int coinsStout, int coinsSwamp, int coinsUnderworld, int coinsWealthy);

private:
    string type;
    int numOfCoinsToGive;
    bool taken;

};

#endif //SMALL_WORLD_SPECIALPOWERBADGE_H
