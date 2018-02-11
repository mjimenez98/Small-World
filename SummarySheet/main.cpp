//
// Created by Miguel Jimenez on 2/7/18.
//

#include "../GamePiece/GamePiece.h"
#include "../LostTribeToken/LostTribeToken.h"
#include "../MatchingRaceToken/MatchingRaceToken.h"
#include "../SpecialPowerBadge/SpecialPowerBadge.h"
#include "../VictoryCoin/VictoryCoin.h"

#include <iostream>

void demoGame(vector<VictoryCoin> coins, vector<MatchingRaceToken> raceTokens, vector<SpecialPowerBadge> badges,
              vector<GamePiece> gamePieces) {

    if(coins.empty() || raceTokens.empty() || badges.empty() || gamePieces.empty()) {
        cout << "ERROR" << endl;
    }
    else {
        cout << "This Small World game set has:\n";
        cout << VictoryCoin::demoVictoryCoins(coins) << endl;
        cout << MatchingRaceToken::demoMatchingRaceTokens(raceTokens) << endl;
        cout << SpecialPowerBadge::demoSpecialPowerBadges(badges) << endl;
        cout << GamePiece::demoGamePieces(gamePieces);
    }

}

void createGame() {

    vector<VictoryCoin> coins = VictoryCoin::createVictoryCoins(ONES, THREES, FIVES, TENS);

    vector<MatchingRaceToken> raceTokens = MatchingRaceToken::createMatchingRaceTokens(AMAZONS, DWARVES, ELVES, GHOULS, GIANTS,
                                                                                       HALFLINGS, HUMANS, ORCS, RATMEN, SKELETONS, SORCERERS, TRITONS, TROLLS, WIZARDS);

    vector<SpecialPowerBadge> badges = SpecialPowerBadge::createSpecialPowerBadges(ALCHEMISTCOINS, BERSERKCOINS, BIVOUACKINGCOINS,
                                                                                   COMMANDOCOINS, DIPLOMATCOINS, DRAGONMASTERCOINS,
                                                                                   FLYINGCOINS, FORESTCOINS, FORTIFIEDCOINS, HEROICCOINS, HILLCOINS,
                                                                                   MERCHANTCOINS, MOUNTEDCOINS, PILLAGINGCOINS, SEAFARINGCOINS,
                                                                                   SPIRITCOINS, STOUTCOINS, SWAMPCOINS, UNDERWORLDCOINS, WEALTHYCOINS);

    vector<GamePiece> gamePieces = GamePiece::createGamePieces(DRAGONS, ENCAMPMENTS, FORTRESSES, HEROES, MOUNTAINS, TROLLLAIRS,
                                                               HOLESINTHEGROUND);

    demoGame(coins, raceTokens, badges, gamePieces);

}

int main() {

    createGame();

    return 0;
}