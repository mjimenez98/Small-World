//
// Created by Miguel Jimenez on 2/7/18.
//

#include "../GamePiece/GamePiece.h"
#include "../LostTribeToken/LostTribeToken.h"
#include "../MatchingRaceToken/MatchingRaceToken.h"
#include "../SpecialPowerBadge/SpecialPowerBadge.h"
#include "../VictoryCoin/VictoryCoin.h"

#include <iostream>

int main() {

    vector<VictoryCoin> coins = VictoryCoin::createVictoryCoins(ONES, THREES, FIVES, TENS);

    vector<MatchingRaceToken> raceTokens = MatchingRaceToken::createMatchingRaceTokens(AMAZONS, DWARVES, ELVES, GHOULS, GIANTS,
    HALFLINGS, HUMANS, ORCS, RATMEN, SKELETONS, SORCERERS, TRITONS, TROLLS, WIZARDS);

    vector<SpecialPowerBadge> badges = SpecialPowerBadge::createSpecialPowerBadges(ALCHEMISTCOINS, BERSERKCOINS, BIVOUACKINGCOINS,
                                                                                   COMMANDOCOINS, DIPLOMATCOINS, DRAGONMASTERCOINS,
                                                                                   FLYINGCOINS, FORESTCOINS, FORTIFIEDCOINS, HEROICCOINS, HILLCOINS,
                                                                                   MERCHANTCOINS, MOUNTEDCOINS, PILLAGINGCOINS, SEAFARINGCOINS,
                                                                                   SPIRITCOINS, STOUTCOINS, SWAMPCOINS, UNDERWORLDCOINS, WEALTHYCOINS);

    cout << "This Small World game set has:\n";
    cout << VictoryCoin::demoVictoryCoins(coins) << endl;
    cout << MatchingRaceToken::demoMatchingRaceTokens(raceTokens) << endl;
    cout << SpecialPowerBadge::demoSpecialPowerBadges(badges);

   /*
    GamePiece gamePieces = GamePiece::createGamePieces(DRAGONS, ENCAMPMENTS, FORTRESSES, HEROES, MOUNTAINS, TROLLLAIRS,
    HOLESINTHEGROUND);
*/

    return 0;
}