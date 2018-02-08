//
// Created by Miguel Jimenez on 2/7/18.
//

#include "../GamePiece/GamePiece.h"
#include "../LostTribeToken/LostTribeToken.h"
#include "../MatchingRaceToken/MatchingRaceToken.h"
#include "../SpecialPowerBadge/SpecialPowerBadge.h"
#include "../VictoryCoin/VictoryCoin.h"

int main() {

    VictoryCoin coins = VictoryCoin::createVictoryCoins(ONES, THREES, FIVES, TENS);

    MatchingRaceToken raceTokens = MatchingRaceToken::createMatchingRaceTokens(AMAZONS, DWARVES, ELVES, GHOULS, GIANTS,
    HALFLINGS, HUMANS, ORCS, RATMEN, SKELETONS, SORCERERS, TRITONS, TROLLS, WIZARDS);

    SpecialPowerBadge badges = SpecialPowerBadge::createSpecialPowerBadges(ALCHEMISTCOINS, BERSERKCOINS, BIVOUACKINGCOINS,
    COMMANDOCOINS, DIPLOMATCOINS, DRAGONMASTERCOINS, FLYINGCOINS, FORESTCOINS, FORTIFIEDCOINS, HEROICCOINS, HILLCOINS,
    MERCHANTCOINS, MOUNTEDCOINS, PILLAGINGCOINS, SEAFARINGCOINS, SPIRITCOINS, STOUTCOINS, SWAMPCOINS, UNDERWORLDCOINS, WEALTHYCOINS);

    GamePiece gamePieces = GamePiece::createGamePieces(DRAGONS, ENCAMPMENTS, FORTRESSES, HEROES, MOUNTAINS, TROLLLAIRS,
    HOLESINTHEGROUND);

    return 0;
}