//
// Created by Miguel Jimenez on 2/4/18.
//

#include "Player.h"
#include "../GameTurn/GameTurn.h"

using namespace std;

Player::Player() {

    dice = Dice();
    raceBanner = FantasyRaceBanner();
    summarySheet = SummarySheet();
    coins = vector<VictoryCoin>();
    map = nullptr;

}

Player::Player(Map& gameMap) {

    dice = Dice();
    raceBanner = FantasyRaceBanner();
    summarySheet = SummarySheet();
    coins = vector<VictoryCoin>();
    (*map) = gameMap;

}

Player::Player(Map& gameMap, GameTurn& gameTurn) {

    dice = Dice();
    raceBanner = FantasyRaceBanner();
    summarySheet = SummarySheet();
    coins = vector<VictoryCoin>();
    (*map) = gameMap;
    (*turn) = gameTurn;

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

vector<VictoryCoin>* Player::getCoins() {

    return &coins;

}

// Returns how many coins in value the player has
int Player::getTotalCoinsValue() {

    int sum = 0;

    for(VictoryCoin coin : *getCoins())
        sum += coin.getValue();

    return sum;

}

int Player::getNonEmptyRegionsConqueredInTurn() {

    return nonEmptyRegionsConqueredInTurn;

}

void Player::setNonEmptyRegionsConqueredInTurn(int newNonEmptyRegionsConqueredInTurn) {

    nonEmptyRegionsConqueredInTurn = newNonEmptyRegionsConqueredInTurn;

}

bool Player::hasSummarySheet() {

    if(getSummarySheet().exists())
        return true;

    return false;

}

// Allows player to pick a race
void Player::picks_race(vector<FantasyRaceBanner>& raceBanners) {

    int race = -1;
    vector<FantasyRaceBanner> availableBanners;

    for(FantasyRaceBanner raceBanner : raceBanners) {

        if(!raceBanner.isTaken())
            availableBanners.push_back(raceBanner);

    }

    availableBanners.resize(6);

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

    // Give coins to player
    for(int i=0; i<availableBanners.size()-race; i++)
        coins.emplace_back(VictoryCoin(1));

    // Set the player's race banner
    raceBanner.setRaceToken(availableBanners[race-1].getRaceToken());
    raceBanner.setPowerBadge(availableBanners[race-1].getPowerBadge());
    raceBanners[race-1].setTaken(true);

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

                    if (raceBanner.getRaceToken().getNumOfTokens() + roll < (map->getTokens(regionSelection))+2) {
                        cout << "You did not roll enough to conquer the region" << endl;
                        return;
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

                        return;

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

void Player::redeploy(Map*map)
{
    char redeploy;

    //ask player if they want to redeploy
    while(redeploy!='y'&& redeploy!='n') {

        cout << "Would you like to re-arrange your tokens?(y/n)" << endl;
        cin >> redeploy;
        tolower(redeploy);//makes input lower case
        if (redeploy != 'y' && redeploy != 'n')//make sure input is valid
        {
            cout << "Invalid input, enter 'y' or 'n'."<<endl;
            continue;
        }
        if(redeploy=='n')
            return;
    }


    cout<<"You may now re-arrange your tokens "<< endl;

    int regionRedeploy;

    //let player choose a region to remove tokens from
    do {
        cout << "Your regions are:" << endl;

        for (int j = 0; j < this->regions.size(); ++j) {
            cout << "Region " << this->regions[j] << endl;
        }

        cout << "Select a region to remove tokens from." << endl;
        cin >> regionRedeploy;

        //check if chosen value is owned by the player
        if (!(std::find(this->regions.begin(), this->regions.end(), regionRedeploy) != this->regions.end()))
        {
            cout<<"You do not own this region"<<endl;
        }
    }while(!(std::find(this->regions.begin(), this->regions.end(), regionRedeploy) != this->regions.end()));

    cout<<"This region has "<<map->getTokens(regionRedeploy)<<" tokens on it"<<endl;

    int tokenNumber;

    //let player choose how many tokens to remove
    do{
        cout<<"How many tokens would you like to remove?"<<endl;
        cin>>tokenNumber;

        if((tokenNumber<0 || tokenNumber >= map->getTokens(regionRedeploy)))
        {
            cout<<"You must leave at least one token on the region"<<endl;
        }

    }while(tokenNumber<0 || tokenNumber>= map->getTokens(regionRedeploy));

    //remove tokens
    map->setTokens(regionRedeploy,map->getTokens(regionRedeploy)-tokenNumber);


    //let player place removed tokens
    do{
        cout<<"You now have "<< tokenNumber<<" tokens to place"<<endl;

        //make sure they ony place tokens on owned regions

        do {
            cout<<"Your regions are:"<<endl;

            for (int j = 0; j < this->regions.size(); ++j) {
                cout << "Region " << this->regions[j] << endl;
            }

            cout << "Which region would you like to place tokens on?" << endl;
            cin >> regionRedeploy;

            if(!(std::find(this->regions.begin(), this->regions.end(), regionRedeploy) != this->regions.end()))
            {
                cout<<"This is not your region"<<endl;
            }

        }while(!(std::find(this->regions.begin(), this->regions.end(), regionRedeploy) != this->regions.end()));

        //number of tokens to place on the region.
        int tokenPlacement;

        do{
            cout<<"You have "<< tokenNumber << " tokens left to place"<<endl;
            cout<<"How many tokens would you like to place?"<<endl;
            cin>>tokenPlacement;

            if(tokenPlacement>tokenNumber)
            {
                cout<<"You do not have this many tokens to place"<<endl;
            }
        }while(tokenPlacement>tokenNumber);

        map->addTokens(regionRedeploy,tokenPlacement);

        tokenNumber -= tokenPlacement;


    }while(tokenNumber>0);


}

void Player::distributeCoins(int toBeAwarded) {

    // NOTE: BROKEN, to be fixed.

    while(toBeAwarded > 0) {

        if(toBeAwarded > 10 && toBeAwarded % 10 < 10) {
            coins.emplace_back(VictoryCoin(10));
            toBeAwarded -= 10;
        }
        else if(toBeAwarded > 5 && toBeAwarded % 5 < 5) {
            coins.emplace_back(VictoryCoin(5));
            toBeAwarded -= 5;
        }
        else if(toBeAwarded > 3 && toBeAwarded % 3 < 3) {
            coins.emplace_back(VictoryCoin(3));
            toBeAwarded -= 3;
        }
        else if(toBeAwarded > 1 && toBeAwarded % 1 < 1) {
            coins.emplace_back(VictoryCoin(1));
            toBeAwarded -= 1;
        }

    }

}

// Returns a vector containing the regions with terrain @param type that are owned by the player
vector<int> Player::getRegionsWithType(char type) {

    vector<int> regionsWithType;

    for(int region : regions) {

        if((*map).getRegionType(region) == type)
            regionsWithType.push_back(region);

    }

    return regionsWithType;

}

// Give Victory Coins to player determined by the Matching Race
int Player::giveRaceCoins() {

    // NOTE: could be done with switch and enum instead of string. Revise for a future release.

    if(raceBanner.getRaceToken().getType() == "Dwarves") {

        int minesWithDwarves = 0;

        // Each mine region occupied by dwarves
        for(int region : regions) {

            if((*map).isMine(region) && (*map).getTokensType(region) == "Dwarves")
                minesWithDwarves++;

        }

        return minesWithDwarves;

    }
    else if(raceBanner.getRaceToken().getType() == "Humans")
        return (int) getRegionsWithType('F').size();    // 1 bonus victory coin for every farmland region
    else if(raceBanner.getRaceToken().getType() == "Orcs")
        return getNonEmptyRegionsConqueredInTurn();     // Each not-empty conquered by orcs in this turn is worth 1 coin
    else if(raceBanner.getRaceToken().getType() == "Wizards") {

        int magicWithWizards = 0;

        // Each Magic Region your Wizards occupy is worth 1 bonus Victory coin
        for(int region : regions) {

            if((*map).isMine(region) && (*map).getTokensType(region) == "Wizards")
                magicWithWizards++;

        }

        return magicWithWizards;

    }
    return 0;
}

// Give Victory Coins to player determined by the Special Power Badge
int Player::giveBadgeCoins() {

    // NOTE: could be done with switch and enum instead of string. Revise for a future release.

    if(raceBanner.getPowerBadge().getType() == "Alchemist")
        return 2;
    else if(raceBanner.getPowerBadge().getType() == "Forest")
        return (int) getRegionsWithType('T').size();     // 1 bonus victory coin for every forest region
    else if(raceBanner.getPowerBadge().getType() == "Fortified") {

        // 1 coin if player has a fortress
        for(int region : regions) {

            if((*map).hasFortress(region))
                return 1;

        }
        return 0;

    }
    else if(raceBanner.getPowerBadge().getType() == "Hill")
        return (int) getRegionsWithType('H').size();     // 1 bonus victory coin for every hill region
    else if(raceBanner.getPowerBadge().getType() == "Merchant")
        return (int) regions.size();                     // 1 for every region
    else if(raceBanner.getPowerBadge().getType() == "Pillaging")
        return getNonEmptyRegionsConqueredInTurn();      // 1 bonus Victory Coin for every non-empty conquered region in this turn
    else if(raceBanner.getPowerBadge().getType() == "Swamp")
        return (int) getRegionsWithType('S').size();     // 1 bonus victory coin for every swamp region
    else if(raceBanner.getPowerBadge().getType() == "Wealthy") {

        // If it is the first turn
        if((*turn).getTurn() == 1)
            return 7;

        return 0;

    }
    return 0;

}

// Awards player 1 coin for every region they possess and a determined amount by their Race and/or Special Power
void Player::scores() {

    int oldScore = getTotalCoinsValue();

    // For every region
    distributeCoins((int) regions.size());

    // Special Power
    distributeCoins(giveBadgeCoins());

    // Race Power
    distributeCoins(giveRaceCoins());

    cout << "Player has been awarded " << to_string(getTotalCoinsValue()-oldScore) << " coins\n" << endl;

}

string Player::toString() {

    string description = "This player has:\nRegions: ";

    for(int region : regions)
        description += to_string(region) + " | ";

    description += "\nTokens: " + getRaceBanner().getRaceToken().getType() + ", " +
            to_string(getRaceBanner().getRaceToken().getNumOfTokens()) + "\nBadge: " + getRaceBanner().getPowerBadge().getType() +
            "\nSummary Sheet: " + to_string(hasSummarySheet()) + "\nScore: " + to_string(getTotalCoinsValue()) +
            "\n" + VictoryCoin::demoVictoryCoins(*getCoins());

    return description;

}