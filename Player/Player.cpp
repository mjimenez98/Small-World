//
// Created by Miguel Jimenez on 2/4/18.
//

#include "Player.h"

#include <random>   // Default random engine

using namespace std;

Player::Player() {

    dice = Dice();
    raceBanner = FantasyRaceBanner();
    summarySheet = SummarySheet();
    coins = VictoryCoin(5);

    //coins = vector<VictoryCoin>();
    /*
    for(int i=0; i<5; i++)
        coins.emplace_back(VictoryCoin(1));
    */

}

Dice Player::getDice() {

    return dice;

}

FantasyRaceBanner Player::getRaceBanner() {

    return raceBanner;

}

SummarySheet Player::getSummarySheet() {

    return summarySheet;

}

/*
vector<VictoryCoin> Player::getCoins() {

    return coins;

}


// Returns how many coins in value the player has
int Player::totalCoinsValue() {

    int sum = 0;

    for(VictoryCoin coin : getCoins())
        sum += coin.getValue();

    return sum;

}
*/

int Player::totalCoinsValue() {

    return coins.getValue();

}

void Player::setCoins(int newValue) {

    coins.setValue(newValue);

}

bool Player::hasSummarySheet() {

    if(getSummarySheet().exists())
        return true;

    return false;

}

// Allows player to pick a race
void Player::picks_race() {

    int race = -1;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();     // For shuffling fantasy banners

    vector<MatchingRaceToken> availableTokens = MatchingRaceToken::createMatchingRaceTokens(AMAZONSTART, DWARFSTART,
         ELFSTART, GHOULSTART, GIANTSTART, HALFLINGSTART, HUMANSTART, ORCSTART, RATMANSTART, SKELETONSTART,
         SORCERERSTART, TRITONSTART, TROLLSTART, WIZARDSTART);

    vector<SpecialPowerBadge> availableBadges = SpecialPowerBadge::createSpecialPowerBadges(ALCHEMISTTOKENS, BERSERKTOKENS,
            BIVOUACKINGTOKENS, COMMANDOTOKENS, DIPLOMATTOKENS, DRAGONMASTERTOKENS, FLYINGTOKENS, FORESTTOKENS, FORTIFIEDTOKENS,
            HEROICTOKENS, HILLTOKENS, MERCHANTTOKENS, MOUNTEDTOKENS, PILLAGINGTOKENS, SEAFARINGTOKENS, SPIRITTOKENS, STOUTTOKENS,
            SWAMPTOKENS, UNDERWORLDTOKENS, WEALTHYTOKENS);

    // Game rules only allow the player to pick from 6 options
    shuffle(availableTokens.begin(), availableTokens.end(), std::default_random_engine(seed));
    shuffle(availableBadges.begin(), availableBadges.end(), std::default_random_engine(seed));

    availableTokens.resize(6);
    availableBadges.resize(6);

    vector<FantasyRaceBanner> availableBanners = FantasyRaceBanner::createFantasyRaceBanners(availableTokens, availableBadges);

    cout << "Pick a race by writing in the number you prefer" << endl;
    cout << FantasyRaceBanner::demoFantasyRaceBanner(availableBanners) << endl;

    do {

        cout << "Race: ";
        cin >> race;

        if(race < 1 || race > availableBanners.size()) {
            cout << "Invalid input. Number must belong to one of the options." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

    } while(race < 1 || race > availableBanners.size());

    setCoins(coins.getValue()-(race-1));

    raceBanner.setRaceToken(availableBanners[race-1].getRaceToken());
    raceBanner.setPowerBadge(availableBanners[race-1].getPowerBadge());

    //Number of starting tokens = number on race + number on badge
    raceBanner.setNumOfTokens(raceBanner.getRaceToken().getNumOfTokens()+raceBanner.getPowerBadge().getNumOfCoinsToGive());

    cout << "You have picked the badge " << getRaceBanner().getPowerBadge().getType() << " and the token " <<
         getRaceBanner().getRaceToken().getType() << endl << endl;

}

// Allows the player to conquer regions by using their race tokens
void Player::conquers() {

    cout << "It is time for you to conquer!\nSince it is your first turn, you can pick any region adjacent to the edge of "
            "the board or to an exterior sea.\nThese are your options:";


    Map map = loadMap("../textMaps/2Players.txt");

    vector<int> availableRegions;

    for(int i=0; i < map.getNumOfRegions(); i++) {

        if(map.isExterior(i)) {
            availableRegions.push_back(i);
            cout << "\nRegion " + to_string(i) + ", " + map.getRegionType(i);
        }

    }

    cout << endl << endl;

    int regionSelection = -1;
    int tokenSelection = -1;
    cout << "Pick 3 regions" << endl;

    // Tentatively, allow the player to pick 3 regions. This will not be on the final version of this function.
    for(int i=0; i<3; i++) {

        if(raceBanner.getRaceToken().getNumOfTokens() > 0) {

            // Check for a valid region selection
            do {

                cout << "Region " + to_string(i+1) + ": ";
                cin >> regionSelection;

                if(!map.isExterior(regionSelection)) {
                    cout << "Invalid input. Number must belong to one of the options" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }

            } while(!map.isExterior(regionSelection));

            // Check for a valid token selection
            do {

                cout << "You have " + to_string(raceBanner.getRaceToken().getNumOfTokens()) + " tokens left" << endl;
                cout << "How many would you like to place on this region? ";
                cin >> tokenSelection;

                if(tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens()) {
                    cout << "Invalid input. Number must belong to one of the options" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }

            } while(tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens());

            cout << endl;

            // Update player's number of tokens
            raceBanner.setNumOfTokens(raceBanner.getRaceToken().getNumOfTokens()-tokenSelection);

            // Add region selected to the player
            regions.emplace_back(regionSelection);

            // Update number of tokens in that region
            map.setTokens(regionSelection, tokenSelection);

        }
        else {

            cout << "You have no tokens left" << endl;
        }

    }

}

// Awards player 1 coin for every region they possess
void Player::scores() {

    setCoins((int) regions.size() + totalCoinsValue());
    cout << "Player has been awarded " << to_string(regions.size()) << " coins\n" << endl;

}

string Player::toString() {

    string player = "This player has:\nRegions: ";

    for(int region : regions) {

        player += to_string(region) + " | ";
    }

    player += "\nTokens: " + getRaceBanner().getRaceToken().getType() + ", " +
            to_string(getRaceBanner().getRaceToken().getNumOfTokens()) + "\nBadge: " + getRaceBanner().getPowerBadge().getType() +
            "\n" + "Victory Coins: " + to_string(totalCoinsValue()) + "\nDice: roll, " + to_string(dice.roll()) +
            "\nSummary Sheet: " + to_string(hasSummarySheet());

    return player;

}