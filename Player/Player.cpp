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
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

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

    cout << "You have picked the race " << getRaceBanner().getRaceToken().getType() << " and the badge " <<
         getRaceBanner().getPowerBadge().getType() << endl << endl;

}

void Player::conquers() {

    // TBD

}

// Awards player 1 coin for every region they possess
void Player::scores() {

    setCoins((int) regions.size());
    cout << "Player has been awarded " << to_string(regions.size()) << " coins" << endl;

}

string Player::toString() {

    return "This player has:\nRegions:\nTokens: " + getRaceBanner().getRaceToken().getType() + ", " +
            to_string(getRaceBanner().getRaceToken().getNumOfTokens()) + "\nBadge: " + getRaceBanner().getPowerBadge().getType() +
            "\n" + "Victory Coins: " + to_string(totalCoinsValue()) + "\nDice: roll, " + to_string(dice.roll()) +
            "\nSummary Sheet: " + to_string(hasSummarySheet());

}