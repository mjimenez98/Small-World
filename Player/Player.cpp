//
// Created by Miguel Jimenez on 2/4/18.
//

#include "Player.h"

#include <random>   // Default random engine
#include<chrono>
#include <algorithm>

using namespace std;

Player::Player() {

    dice = Dice();
    raceBanner = FantasyRaceBanner();
    summarySheet = SummarySheet();

    coins = vector<VictoryCoin>();
    for(int i=0; i<5; i++)
        coins.emplace_back(VictoryCoin(1));

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

vector<VictoryCoin> Player::getCoins() {

    return coins;

}


// Returns how many coins in value the player has
int Player::getTotalCoinsValue() {

    int sum = 0;

    for(VictoryCoin coin : getCoins())
        sum += coin.getValue();

    return sum;

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

    // To be fixed. Broken because
    //setCoins(coins.getValue()-(race-1));

    raceBanner.setRaceToken(availableBanners[race-1].getRaceToken());
    raceBanner.setPowerBadge(availableBanners[race-1].getPowerBadge());

    //Number of starting tokens = number on race + number on badge
    raceBanner.setNumOfTokens(raceBanner.getRaceToken().getNumOfTokens()+raceBanner.getPowerBadge().getNumOfCoinsToGive());

    cout << "You have picked the badge " << getRaceBanner().getPowerBadge().getType() << " and the token " <<
         getRaceBanner().getRaceToken().getType() << endl << endl;

}



// Allows the player to conquer regions by using their race tokens, on the first turn of the game
void Player::firstConquer(Map*map) {

    //keep track of how many regions the player is picking
        int regionTotal = 0;

            cout << "It is time for you to conquer!\nThe first region you pick must be at the edge of the board or an external sea."
                    "\nThese are your options:"<<endl;


            vector<int> availableRegions;

            for (int i = 0; i < map->getNumOfRegions(); i++) {

                if (map->isExterior(i)) {
                    availableRegions.push_back(i);
                    cout << "Region " + to_string(i) + ", " + map->getRegionType(i)
                         <<", "<<map->getTokens(i)<<" tokens"<<endl;
                }

            }
            cout<<"\nRegions require 2 tokens to conquer, plus 1 for every token they currently have."<<endl;
            cout << endl << endl;

            int regionSelection = -1;
            int tokenSelection = -1;
            cout<<"You have "<<raceBanner.getRaceToken().getNumOfTokens()<<" tokens"<<endl;


                if (raceBanner.getRaceToken().getNumOfTokens() > 0) {

                    // Check for a valid region selection
                    do {


                        cout << "Pick a region" << endl;
                        cin >> regionSelection;
                        cout << "Region " + to_string(regionSelection) + ": ";


                        if (!map->isExterior(regionSelection)) {
                            cout << "Invalid input. Number must belong to one of the options" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                    } while (!map->isExterior(regionSelection));

                    // Check for a valid token selection
                    do {

                        cout << "You have " + to_string(raceBanner.getRaceToken().getNumOfTokens()) + " tokens left"
                             << endl;
                        cout<<"This region has "<<map->getTokens(regionSelection)<<" token(s) on it."<<endl;
                        cout << "How many would you like to place on this region? ";
                        cin >> tokenSelection;

                        if (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens()
                                ||tokenSelection<(map->getTokens(regionSelection)+2)) {
                            cout << "Invalid input. You need 2 tokens plus the number of tokens on the region to conquer." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                    } while (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens()
                                                   ||tokenSelection<(map->getTokens(regionSelection)+2));

                    cout << endl;

                    // Update player's number of tokens
                    raceBanner.setNumOfTokens(raceBanner.getRaceToken().getNumOfTokens() - tokenSelection);

                    // Add region selected to the player
                    regions.emplace_back(regionSelection);

                    // Update number of tokens in that region
                    int tokenAmmount = tokenSelection;
                    //player places tokens, the mountain stays
                    //The lost tribes do not stay if a player conquers
                    if(map->hasMountains(regionSelection))
                        ++tokenAmmount;
                    map->setTokens(regionSelection, tokenAmmount);

                } else {

                    cout << "You have no tokens left" << endl;
                }


            cout<< "Now you may conquer regions adjacent to the ones you own."<<endl;

    {
        //all regions the player can pick
        vector<int> adjRegions;


        cout << "Regions require 2 tokens to conquer, plus 1 for every token they currently have." << endl;
        cout << endl << endl;

        cout << "You have " << raceBanner.getRaceToken().getNumOfTokens() << " tokens" << endl;




        // Player picks regions until they have no more tokens to place
        while (raceBanner.getRaceToken().getNumOfTokens() > 0) {


            if (raceBanner.getRaceToken().getNumOfTokens() > 0) {

                // Check for a valid region selection
                do {
                    cout<<"Here are your options"<<endl;

                    //if previous chosen value is in list of adjacent regions, remove it
                    if((std::find(adjRegions.begin(), adjRegions.end(),regionSelection ) != adjRegions.end()))
                    {
                        adjRegions.erase(std::remove(adjRegions.begin(), adjRegions.end(), regionSelection), adjRegions.end());
                    }

                    //loop through player's regions
                    for (int i = 0; i < regions.size(); i++) {

                        //loop through all regions and check if they are adjacent and not already owned
                        for(int j = 1; j< map->getNumOfRegions()+1;++j)
                            if(map->isConnected(regions[i],j)&&
                                    (!(std::find(regions.begin(), regions.end(),j ) != regions.end()))
                                    &&
                                    (!(std::find(adjRegions.begin(), adjRegions.end(),j ) != adjRegions.end())))
                            {

                                //add adjacent regions to stack
                                adjRegions.push_back(j);

                            }

                    }
                    //display available regions
                    for (int i = 0; i<adjRegions.size();++i)
                    {
                        cout<< "Region " << adjRegions[i] << ", " << map->getRegionType(adjRegions[i])
                             << ", " << map->getTokens(adjRegions[i]) << " tokens" << endl;
                    }

                    while(!(std::find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end())) {


                        cout << "Pick a region" << endl;
                        cin >> regionSelection;



                        //check if selected region is adjacent to an owned one
                        if (!(std::find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end())) {
                            cout << "Invalid input. Number must belong to one of the options" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }


                } while ((!(std::find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end())));

                // Check for a valid token selection
                do {

                    cout << "You have " + to_string(raceBanner.getRaceToken().getNumOfTokens()) + " tokens left"
                         << endl;
                    cout << "This region has " << map->getTokens(regionSelection) << " token(s) on it." << endl;

                    //if player doesnt have enough to conquer, roll a die
                    if(raceBanner.getRaceToken().getNumOfTokens() < (map->getTokens(regionSelection) + 2)) {
                        Dice dice1;
                        int roll = dice1.roll();

                        cout << "You rolled a " << roll << endl;

                        if (raceBanner.getRaceToken().getNumOfTokens() < (map->getTokens(regionSelection) + 2)) {
                            cout << "You did not roll enough to conquer the region" << endl;
                            break;
                        } else
                        {
                            cout << "This was enough to conquer the region" << endl;


                            // Update player's number of tokens
                            raceBanner.setNumOfTokens(0);

                            // Add region selected to the player
                            regions.emplace_back(regionSelection);

                            // Update number of tokens in that region
                            int tokenAmmount = tokenSelection;
                            //player places tokens, the mountain stays
                            //The lost tribes do not stay if a player conquers
                            if (map->hasMountains(regionSelection))
                                ++tokenAmmount;
                            map->setTokens(regionSelection, tokenAmmount);

                        }
                    }
                    do{
                    cout << "How many would you like to place on this region? ";

                    cin >> tokenSelection;

                        if (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens()) {
                            cout
                                    << "Invalid input. You need 2 tokens plus the number of tokens on the region, to conquer."
                                    << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }while(tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens());

                } while (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens());

                cout << endl;

                // Update player's number of tokens
                raceBanner.setNumOfTokens(raceBanner.getRaceToken().getNumOfTokens() - tokenSelection);

                // Add region selected to the player
                regions.emplace_back(regionSelection);

                // Update number of tokens in that region
                int tokenAmmount = tokenSelection;
                //player places tokens, the mountain stays
                //The lost tribes do not stay if a player conquers
                if (map->hasMountains(regionSelection))
                    ++tokenAmmount;
                map->setTokens(regionSelection, tokenAmmount);

            } else {

                cout << "You have no tokens left" << endl;
            }

        }
    }
}

// Awards player 1 coin for every region they possess
void Player::scores() {

    //setCoins((int) regions.size() + totalCoinsValue());
    cout << "Player has been awarded " << to_string(regions.size()) << " coins\n" << endl;

}

string Player::toString() {

    string description = "This player has:\nRegions: ";

    for(int region : regions) {

        description += to_string(region) + " | ";
    }

    description += "\nTokens: " + getRaceBanner().getRaceToken().getType() + ", " +
            to_string(getRaceBanner().getRaceToken().getNumOfTokens()) + "\nBadge: " + getRaceBanner().getPowerBadge().getType() +
            "\n" + "Victory Coins: " + VictoryCoin::demoVictoryCoins(getCoins()) + "\nDice: roll, " + to_string(dice.roll()) +
            "\nSummary Sheet: " + to_string(hasSummarySheet());

    return description;

}