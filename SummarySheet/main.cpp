//
// Created by Miguel Jimenez on 2/7/18.
//

#include "../FantasyRaceBanner/FantasyRaceBanner.h"
#include "../GamePiece/GamePiece.h"
#include "../LostTribeToken/LostTribeToken.h"
#include "../VictoryCoin/VictoryCoin.h"

#include <iostream>

// Prints a description of the Small World deck
void demoGame(vector<VictoryCoin>* coins, vector<MatchingRaceToken>* raceTokens, vector<SpecialPowerBadge>* badges,
              vector<GamePiece>* gamePieces, vector<LostTribeToken>* lostTribes, vector<FantasyRaceBanner>* raceBanners) {

    if((*coins).empty() || (*raceTokens).empty() || (*badges).empty() || (*gamePieces).empty() || (*lostTribes).empty() ||
            (*raceBanners).empty()) {
        cout << "ERROR" << endl;
    }
    else {
        cout << "This Small World game set has:\n" << endl;
        cout << VictoryCoin::demoVictoryCoins(*coins) << endl;
        cout << MatchingRaceToken::demoMatchingRaceTokens(*raceTokens, 1) << endl;
        cout << SpecialPowerBadge::demoSpecialPowerBadges(*badges) << endl;
        cout << GamePiece::demoGamePieces(*gamePieces) << endl;
        cout << LostTribeToken::demoLostTribeTokens(*lostTribes) << endl;
        cout << FantasyRaceBanner::demoFantasyRaceBanner(*raceBanners);
    }

}

// Creates a deck of the Small World set
void createGame() {

    vector<VictoryCoin> coins = VictoryCoin::createVictoryCoins(ONES, THREES, FIVES, TENS);

    vector<MatchingRaceToken> raceTokens = MatchingRaceToken::createMatchingRaceTokens(AMAZONS, DWARVES, ELVES, GHOULS, GIANTS,
                                                                                       HALFLINGS, HUMANS, ORCS, RATMEN, SKELETONS, SORCERERS, TRITONS, TROLLS, WIZARDS);

    vector<SpecialPowerBadge> badges = SpecialPowerBadge::createSpecialPowerBadges(ALCHEMISTTOKENS, BERSERKTOKENS, BIVOUACKINGTOKENS,
                                                                                   COMMANDOTOKENS, DIPLOMATTOKENS, DRAGONMASTERTOKENS,
                                                                                   FLYINGTOKENS, FORESTTOKENS, FORTIFIEDTOKENS,
                                                                                   HEROICTOKENS, HILLTOKENS, MERCHANTTOKENS,
                                                                                   MOUNTEDTOKENS, PILLAGINGTOKENS, SEAFARINGTOKENS,
                                                                                   SPIRITTOKENS, STOUTTOKENS, SWAMPTOKENS,
                                                                                   UNDERWORLDTOKENS, WEALTHYTOKENS);

    vector<GamePiece> gamePieces = GamePiece::createGamePieces(DRAGONS, ENCAMPMENTS, FORTRESSES, HEROES, MOUNTAINS, TROLLLAIRS,
                                                               HOLESINTHEGROUND);

    vector<LostTribeToken> lostTribes = LostTribeToken::createLostTribeTokens(NUMOFLOSTTRIBETOKENS);

    vector<FantasyRaceBanner> raceBanners = FantasyRaceBanner::createFantasyRaceBanners(raceTokens, badges);

    demoGame(&coins, &raceTokens, &badges, &gamePieces, &lostTribes, &raceBanners);

}

int main() {

    createGame();

    return 0;
}