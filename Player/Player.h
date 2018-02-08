//
// Created by Miguel Jimenez on 2/4/18.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H

#include "../LostTribeToken/LostTribeToken.h"
#include "../MatchingRaceToken/MatchingRaceToken.h"
#include "../SpecialPowerBadge/SpecialPowerBadge.h"
#include "../SummarySheet/SummarySheet.h"
#include "../VictoryCoin/VictoryCoin.h"

#include <string>

using namespace std;

class Player {

public:
    Player(string raceChosen, string specialPowerBadgeChosen);
    string toString();

private:
    void picks_race();
    void conquers();
    void scores();
    //Die die
    LostTribeToken tribeTokens[MAXOFLOSTTRIBES];
    MatchingRaceToken raceTokens[MAXOFRACETOKENS];
    //Region regions[n];   n -> number of regions
    SpecialPowerBadge badge(string specialPowerBadgeChosen);
    SummarySheet summarySheet;
    VictoryCoin coins[];

};

#endif //SMALL_WORLD_PLAYER_H
