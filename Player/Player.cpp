//
// Created by Miguel Jimenez on 2/4/18.
//

#include <limits>
#include "Player.h"
#include <random>   // Default random engine
#include<chrono>
#include <algorithm>
#include <iostream>
#include "../GameTurn/GameTurn.h"
#include "../Observer/Observer.h"

using namespace std;

Player::Player() {

    dice = Dice();
    raceBanner = FantasyRaceBanner();
    summarySheet = SummarySheet();
    coins = vector<VictoryCoin>();
    map = nullptr;
    turn = nullptr;

    selectNewRace = false;

}

Player::Player(Map* gameMap) {

    dice = Dice();
    raceBanner = FantasyRaceBanner();
    summarySheet = SummarySheet();
    coins = vector<VictoryCoin>();
    map = gameMap;

    selectNewRace = false;

}

Player::Player(Map& gameMap, GameTurn& gameTurn) {

    dice = Dice();
    raceBanner = FantasyRaceBanner();
    summarySheet = SummarySheet();
    coins = vector<VictoryCoin>();
    map = &gameMap;
    turn = &gameTurn;

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

    //notify observer
    Observer::notifyAction("is picking race");
    int race = -1;
    vector<FantasyRaceBanner> availableBanners;

    // Set all fantasy banners that are not taken by other players
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

// Decline a turn
void Player::decline() {

    //notify observer
    Observer::notifyAction("is going into decline");
    for(int region : regions) {

        // Erase all previous tokens in decline
        if((*map).isInDecline(region)) {

            (*map).setTokens(region, (*map).getTokens(region)-1);
            (*map).setInDecline(region, false);

        }

        // Decrease the number of your declining race's tokens in each region to 1
        if((*map).getTokensType(region) == raceBanner.getRaceToken().getType()) {

            (*map).setTokens(region, 1);
            (*map).setInDecline(region, true);

        }

    }

    cout << endl << "Any previous races in decline have been erased and the number of your declining race's tokens "
            << "in each region has been set to 1." << endl << "A new race will be picked on the next turn." << endl << endl;

    selectNewRace = true;

}

// Helper method that finalizes a conquest by updating a player's and region's properties
void Player::finalizeConquer(int regionSelection, int tokenSelection) {

    // Update player's number of tokens
    raceBanner.setNumOfTokens(raceBanner.getRaceToken().getNumOfTokens() - tokenSelection);

    // Add region selected to the player
    regions.emplace_back(regionSelection);
    //notify Observer of change in number of regions
    Observer::notifyRegionsOwned(regions.size());

    // If the region was non-empty, set the property to +1
    if(map->getTokens(regionSelection) == 1)
        setNonEmptyRegionsConqueredInTurn(getNonEmptyRegionsConqueredInTurn()+1);

    // Update number of tokens in that region
    int tokenAmount = tokenSelection;

    //player places tokens, the mountain stays
    if(map->hasMountains(regionSelection))
        ++tokenAmount;

    //The lost tribes do not stay if a player conquer
    map->setTokens(regionSelection, tokenAmount);


}

void Player::conquer()
{

    //notify observer
    Observer::notifyAction("is conquering");
    int regionSelection;
    int tokenSelection;
    // CONQUER ADJACENT REGIONS

    if (raceBanner.getRaceToken().getNumOfTokens() > 0) {

        //all regions the player can pick
        vector<int> adjRegions;

        cout << "Now you may conquer regions adjacent to the ones you own." << endl;
        cout << "Regions require 2 tokens to conquer, plus 1 for every token they currently have." << endl << endl
             << endl;
        cout << "You have " << raceBanner.getRaceToken().getNumOfTokens() << " tokens" << endl;

        // Player picks regions until they have no more tokens to place
        while (raceBanner.getRaceToken().getNumOfTokens() > 0) {

            if (raceBanner.getRaceToken().getNumOfTokens() > 0) {

                // Check for a valid region selection
                do {
                    cout << "Here are your options" << endl;

                    //if previous chosen value is in list of adjacent regions, remove it
                    if (find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end())
                        adjRegions.erase(remove(adjRegions.begin(), adjRegions.end(), regionSelection),
                                         adjRegions.end());

                    //loop through player's regions
                    for (int i = 0; i < regions.size(); i++) {

                        //loop through all regions and check if they are adjacent and not already owned
                        for (int j = 1; j < map->getNumOfRegions() + 1; ++j) {

                            if (map->isConnected(regions[i], j) &&
                                (!(find(regions.begin(), regions.end(), j) != regions.end())) &&
                                (!(find(adjRegions.begin(), adjRegions.end(), j) != adjRegions.end())))
                                adjRegions.push_back(j); //add adjacent regions to stack

                        }

                    }

                    //display available regions
                    for (int adjRegion : adjRegions) {
                        cout << "Region " << adjRegion << ", " << map->getRegionType(adjRegion)
                             << ", " << map->getTokens(adjRegion) << " tokens" << endl;
                    }

                    while (!(find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end())) {

                        cout << "Pick a region" << endl;
                        cin >> regionSelection;

                        //check if selected region is adjacent to an owned one
                        if (!(find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end())) {

                            cout << "Invalid input. Number must belong to one of the options" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        }
                    }


                } while ((!(find(adjRegions.begin(), adjRegions.end(), regionSelection) != adjRegions.end())));

                // Check for a valid token selection
                do {

                    cout << "You have " + to_string(raceBanner.getRaceToken().getNumOfTokens()) + " tokens left"
                         << endl;
                    cout << "This region has " << map->getTokens(regionSelection) << " token(s) on it." << endl;

                    //if player doesnt have enough to conquer, roll a die
                    if (raceBanner.getRaceToken().getNumOfTokens() < (map->getTokens(regionSelection) + 2)) {

                        int roll = dice.roll();

                        cout
                                << "You do not have enough tokens to conquer this region, so the reinforcement die will be called:"
                                << endl << "You rolled a " << roll << endl;

                        if (raceBanner.getRaceToken().getNumOfTokens() + roll < (map->getTokens(regionSelection)) + 2) {

                            cout << "You did not roll enough to conquer the region" << endl;
                            return;

                        } else {
                            cout << "This was enough to conquer the region" << endl;
                            finalizeConquer(regionSelection, tokenSelection);
                            return;

                        }

                    }

                    do {

                        cout << "How many would you like to place on this region? ";
                        cin >> tokenSelection;

                        if (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens()
                        ||tokenSelection<(map->getTokens(regionSelection)+2)) {

                            cout
                                    << "Invalid input. You need 2 tokens plus the number of tokens on the region, to conquer."
                                    << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        }

                    } while (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens()
                                                   ||tokenSelection<(map->getTokens(regionSelection)+2));

                } while (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens());

                cout << endl;
                finalizeConquer(regionSelection, tokenSelection);

            } else {
                cout << "You have no tokens left" << endl;
            }

        }

    }   // End of if tokens > 0

}

// Allows the player to conquer regions by using their race tokens, on the first turn of the game
void Player::firstConquer() {
    //notify observer
    Observer::notifyAction("is conquering");
    // NOTE: Lost tribes are being checked by region.tokens. LosTribeToken class should be used instead for a future release.

    setNonEmptyRegionsConqueredInTurn(0);
    vector<int> availableRegions;

    int regionSelection = -1;
    int tokenSelection = -1;


    // INTRODUCTION AND DISPLAY OF REGIONS

    cout << "It is time for you to conquer!\n" <<
            "The first region you pick must be at the edge of the board or an external sea." <<
            "\nThese are your options:" << endl;

    // Display exterior regions
    for (int i = 0; i < map->getNumOfRegions(); i++) {

        if (map->isExterior(i)) {
            availableRegions.push_back(i);
            cout << "Region " + to_string(i) + ", " + map->getRegionType(i)
                 <<", "<<map->getTokens(i)<<" tokens"<<endl;
        }

    }
    cout << "\nRegions require 2 tokens to conquer, plus 1 for every token they currently have." << endl << endl << endl;


    // FIRST REGION SELECTION AND TOKEN PLACEMENT

    cout << "You have " << raceBanner.getRaceToken().getNumOfTokens() << " tokens" << endl;

    // If player has tokens available
    if (raceBanner.getRaceToken().getNumOfTokens() > 0) {

        // Check for a valid region selection. For first turn, selection must be a region at the edge or an external sea.
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

            cout << "You have " + to_string(raceBanner.getRaceToken().getNumOfTokens()) + " tokens left" << endl;
            cout << "This region has " << map->getTokens(regionSelection) << " token(s) on it." << endl;
            cout << "How many would you like to place on this region? ";
            cin >> tokenSelection;

            if (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens()
                || tokenSelection<(map->getTokens(regionSelection)+2)) {
                cout << "Invalid input. You need 2 tokens plus the number of tokens on the region to conquer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        } while (tokenSelection < 0 || tokenSelection > raceBanner.getRaceToken().getNumOfTokens()
                 ||tokenSelection<(map->getTokens(regionSelection)+2));

        cout << endl;

        finalizeConquer(regionSelection, tokenSelection);

    } else {
        cout << "You have no tokens left" << endl;
    }

    conquer();


}

void Player::redeploy()
{

    //notify observer
    Observer::notifyAction("is redeploying");
    char redeploy ='x';

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

//return number of tokens player removed
void Player::readyTroops()
{

    //notify observer
    Observer::notifyAction("is readying troops");

    cout<<"You may now remove tokens from your regions, that can be used to conquer."<<endl;
    //'remove' keeps track of wether player wants to select another region to remove tokens from
    char remove;

    //total number of removed tokens
    int availableTokens = 0;
    do {
        //region that tokens will be removed from
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
            if (!(std::find(this->regions.begin(), this->regions.end(), regionRedeploy) != this->regions.end())) {
                cout << "You do not own this region" << endl;
            }
        } while (!(std::find(this->regions.begin(), this->regions.end(), regionRedeploy) != this->regions.end()));

        cout << "This region has " << map->getTokens(regionRedeploy) << " tokens on it" << endl;

        int tokenNumber;

        //let player choose how many tokens to remove
        do {
            cout << "How many tokens would you like to remove?" << endl;
            cin >> tokenNumber;

            if ((tokenNumber < 0 || tokenNumber >= map->getTokens(regionRedeploy))) {
                cout << "You must leave at least one token on the region" << endl;
            }

        } while (tokenNumber < 0 || tokenNumber >= map->getTokens(regionRedeploy));

        //remove tokens
        map->setTokens(regionRedeploy, map->getTokens(regionRedeploy) - tokenNumber);

        availableTokens += tokenNumber;


        while (remove != 'y' && remove != 'n') {

            cout << "Would you like to remove more tokens?(y/n)" << endl;
            cin >> remove;
            tolower(remove);//makes input lower case
            if (remove != 'y' && remove != 'n')//make sure input is valid
            {
                cout << "Invalid input, enter 'y' or 'n'." << endl;
                continue;
            }
            if (remove == 'n') {
                //add removed tokens to player's available tokens
                raceBanner.setNumOfTokens(raceBanner.getRaceToken().getNumOfTokens()+availableTokens);
                return;
            }
        }

    }while(remove=='y');

}

void Player::abandonRegion()
{
    //notify observer
    Observer::notifyAction("is abandoning a region");
    //region that will be abandoned
    int regionAbandon;

    //let player choose a region to abandon
    do {
        cout << "Your regions are:" << endl;

        for (int j = 0; j < this->regions.size(); ++j) {
            cout << "Region " << this->regions[j] << endl;
        }

        cout << "Select a region to abandon" << endl;
        cin >> regionAbandon;

        //check if chosen value is owned by the player
        if (!(std::find(this->regions.begin(), this->regions.end(), regionAbandon) != this->regions.end())) {
            cout << "You do not own this region" << endl;
        }
    } while (!(std::find(this->regions.begin(), this->regions.end(), regionAbandon) != this->regions.end()));

    //tokens player removed from region
    int removedTokens;

    //if region is a mountain, leave 1 token
    if(map->getRegionType(regionAbandon)=='M') {
        //tokens player removed from region
        removedTokens = map->getTokens(regionAbandon)-1;

        map->setTokens(regionAbandon,1);
    }
        //if it isnt a mountain, remove all tokens
    else{
        //tokens player removed from region
        removedTokens = map->getTokens(regionAbandon);

        map->setTokens(regionAbandon,0);
    }

    //remove the region from the player's owned regions
    regions.erase(remove(regions.begin(), regions.end(), regionAbandon),
                     regions.end());
    //notify Observer of change in number of regions
    Observer::notifyRegionsOwned(regions.size());


    //add removed tokens to player's available tokens
    raceBanner.setNumOfTokens(raceBanner.getRaceToken().getNumOfTokens()+removedTokens);

}

// Determines which coin should be given to the player. It will always go for the biggest possible.
void Player::distributeCoins(int toBeAwarded) {

    while(toBeAwarded > 0) {

        if(toBeAwarded >= 10 && toBeAwarded % 10 < 10) {
            coins.emplace_back(VictoryCoin(10));
            toBeAwarded -= 10;
        }
        else if(toBeAwarded >= 5 && toBeAwarded % 5 < 5) {
            coins.emplace_back(VictoryCoin(5));
            toBeAwarded -= 5;
        }
        else if(toBeAwarded >= 3 && toBeAwarded % 3 < 3) {
            coins.emplace_back(VictoryCoin(3));
            toBeAwarded -= 3;
        }
        else if(toBeAwarded > 0 && toBeAwarded % 1 == 0) {
            coins.emplace_back(VictoryCoin(1));
            toBeAwarded -= 1;
        }
        else {
            toBeAwarded = 0;
            cout << "\nERROR at assigning Victory Coins" << endl << endl;
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

// NOTE: TEMP
int Player::giveRaceCoins(string type) {

    // NOTE: could be done with switch and enum instead of string. Revise for a future release.

    if(type == "Dwarves") {

        int minesWithDwarves = 0;

        // Each mine region occupied by dwarves
        for(int region : regions) {

            if((*map).isMine(region) && (*map).getTokensType(region) == "Dwarves")
                minesWithDwarves++;

        }

        return minesWithDwarves;

    }
    else if(type == "Humans")
        return (int) getRegionsWithType('F').size();    // 1 bonus victory coin for every farmland region
    else if(type == "Orcs")
        return getNonEmptyRegionsConqueredInTurn();     // Each not-empty conquered by orcs in this turn is worth 1 coin
    else if(type == "Wizards") {

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

//lets player decide what they want to do on their turn
void Player::playerTurn(vector<FantasyRaceBanner>& raceBanners)
{

    if(selectNewRace) {

        picks_race(raceBanners);

        selectNewRace = false;

    }

    else {

        //keeps looping until player chooses 'end your turn'
        while(true) {
            int choice;
            do {
                cout << "Would you like to \n1:Ready your troops\n2:Conquer\n3:Go into decline\n4:Abandon a region \n5:End your turn" << endl;
                cin>>choice;

                if (choice < 1 || choice > 5)
                    cout << "Invalid input" << endl;

            } while (choice < 1 || choice > 5);

            switch (choice) {
                case 1:
                    readyTroops();
                    break;
                case 2:
                    conquer();
                    break;
                case 3:
                    decline();
                    return;
                case 4:abandonRegion();break;
                default: return;
            }
        }

    }


}

// Awards player 1 coin for every region they possess and a determined amount by their Race and/or Special Power
void Player::scores() {

    int oldScore = getTotalCoinsValue();
    int newCoins = 0;

    // For every region
    newCoins = (int) regions.size();
    distributeCoins(newCoins);
    cout << "Player has been awarded " + to_string(newCoins) + " coin(s) because of the amount of conquered regions" << endl;

    // Special Power
    newCoins = giveBadgeCoins();
    distributeCoins(newCoins);
    cout << "Player has been awarded " + to_string(newCoins) + "  coin(s) because of the " + raceBanner.getPowerBadge().getType()
         << " power badge" << endl;

    // Race Power
    newCoins = giveRaceCoins();
    distributeCoins(newCoins);
    cout << "Player has been awarded " + to_string(newCoins) + " coin(s) because of the " + raceBanner.getRaceToken().getType()
         << " race" << endl;

    // Regions in decline
    newCoins = 0;
    for(int region : regions) {

        if((*map).isInDecline(region))
            newCoins += giveRaceCoins((*map).getTokensType(region));

    }
    distributeCoins(newCoins);
    cout << "Player has been awarded " + to_string(newCoins) + " coin(s) because of races in decline" << endl;

    cout << "Player has been awarded a total of " << to_string(getTotalCoinsValue()-oldScore) << " coin(s)\n" << endl;

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