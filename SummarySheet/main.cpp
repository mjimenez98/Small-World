//
// Created by Miguel Jimenez on 2/7/18.
//

#include "../LostTribeToken/LostTribeToken.h"
#include "../MatchingRaceToken/MatchingRaceToken.h"
#include "../SpecialPowerBadge/SpecialPowerBadge.h"
#include "../VictoryCoin/VictoryCoin.h"

int main() {

    VictoryCoin coins = VictoryCoin::createVictoryCoins(ONES, THREES, FIVES, TENS);

    return 0;
}