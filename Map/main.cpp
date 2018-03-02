#include "Map.h"
#include "../Player/Player.h"
#include "../SummarySheet/SummarySheet.h"
#include "../GamePiece/GamePiece.h"
#include "../LostTribeToken/LostTribeToken.h"
#include <iostream>
#include <string>

using namespace std;
// Prints a description of the Small World deck
void demoGame(vector<VictoryCoin>* coins, vector<MatchingRaceToken>* raceTokens, vector<SpecialPowerBadge>* badges,
              vector<GamePiece>* gamePieces, vector<LostTribeToken>* lostTribes, vector<FantasyRaceBanner>* raceBanners)
{

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

int main()
{
    int players = 0;
    bool loop = true;
    while(loop) {
        cout << "How many people will be playing?" << endl;
        cin >> players;
        if (players < 2 || players>5)
        {
            cout<<"Invalid number of players."<<endl;
        }

        else
            loop = false;
    }

    switch(players)
    {
        case 2: {Map map = loadMap("../textMaps/2Players.txt");
            if( !checkConnect(map))
                return(0);
            Player player1();
            Player player2();
            cout<<"Loaded the 2 player map and created 2 players"<<endl;break;}
        case 3:{ Map map = loadMap("../textMaps/3Players.txt");
            if( !checkConnect(map))
                return(0);
            Player player1();
            Player player2();
            Player player3();
            cout<<"Loaded the 3 player map and created 3 players"<<endl;break;}
        case 4:{ Map map = loadMap("../textMaps/4Players.txt");
            if( !checkConnect(map))
                return(0);
            Player player1();
            Player player2();
            Player player3();
            Player player4();
            cout<<"Loaded the 4 player map and created 4 players"<<endl;break;}
        case 5:{ Map map = loadMap("../textMaps/5Players.txt");
            if( !checkConnect(map))
                return(0);
            Player player1();
            Player player2();
            Player player3();
            Player player4();
            Player player5();
            cout<<"Loaded 5 player map and created 5 players"<<endl;break;}
        default : cout<<"switch error"<<endl;break;


    }
    createGame();
}




