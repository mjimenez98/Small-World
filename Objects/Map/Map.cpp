#include "Map.h"

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

// Subclass: Region in map
struct Map::Region {

    int tokens =0;
    string token_type;
    string player;
    char regionType;
    /* H = hill
     * W = sea
     * S = swamp
     * F = farmland
     * T = forest
     * M = mountain
    */

    bool cavern = false;
    bool mine = false;
    bool magic = false;
    bool exterior = false;

    bool inDecline = false;

    GamePiece* gamePiece = nullptr;
    LostTribeToken* lostTribeToken = nullptr;

};

Map::Map() {

    regions = new Region[0];
    numOfRegions = 0;

}

Map::Map(int newNumOfRegions)
{
    regions = new Region[newNumOfRegions];
    numOfRegions = newNumOfRegions;

}

// Getters
char Map::getRegionType(int region)
{
    return regions[region].regionType;
}

int Map::getTokens(int region)
{
    return regions[region].tokens;
}

string Map::getTokensType(int region)
{
    return regions[region].token_type;
}

string Map::getRegionPlayer(int region)
{
    return regions[region].player;
}

int Map::getNumOfRegions()
{
    return numOfRegions;
}

// Setters
void Map::setCavern(int region, bool state)
{
    regions[region].cavern = state;
}

void Map::setExterior(int region, bool state)
{
    regions[region].exterior = state;
}

void Map::setInDecline(int region, bool state)
{
    regions[region].inDecline = state;
}

void Map::setLostTribes(int region, LostTribeToken newToken)
{
    regions[region].lostTribeToken = &newToken;
}

void Map::setMagic(int region, bool state)
{
    regions[region].magic = state;
}

void Map::setMine(int region, bool state)
{
    regions[region].mine = state;
}

void Map::setRegionPlayer(int region, string player)
{
    regions[region].player = player;
}

void Map::setRegionType(int region, char type)
{
    regions[region].regionType = type;

    if(type == 'M')
        regions[region].gamePiece = new GamePiece("Mountain");
}

void Map::setTokensType(string type, int region)
{
    regions[region].token_type = type;
}

void Map::setTokens(int region, int tokens)
{
    regions[region].tokens = tokens;
}

//add tokens to current amount of tokens
void Map::addTokens(int region, int tokens)
{
    regions[region].tokens += tokens;
}

// Is
bool Map::isCavern(int region)
{
    return regions[region].cavern;
}

bool Map::isConnected(int region1, int region2)
{
    if (connections[region1][region2] == 1)
        return true;

    return false;
}

bool Map::isExterior(int region)
{
    if(region > getNumOfRegions())
        return false;

    return regions[region].exterior;
}

bool Map::isMagic(int region)
{
    return regions[region].magic;
}

bool Map::isMine(int region)
{
    return regions[region].mine;
}

bool Map::isInDecline(int region)
{
    return regions[region].inDecline;
}

// Has
bool Map::hasLostTribes(int region)
{
    if(regions[region].lostTribeToken != nullptr) {
        return true;
    }
    return false;
}

bool Map::hasFortress(int region)
{
    if(regions[region].gamePiece != nullptr && regions[region].gamePiece->getType() == "Fortress") {
        return true;
    }

    return false;
}

bool Map::hasMountains(int region)
{
    if(regions[region].gamePiece != nullptr && regions[region].gamePiece->getType() == "Mountain") {
        return true;
    }

    return false;
}

// Other
void Map::addEdge(int region1, int region2)
{
    connections[region1][region2] = 1;
    connections[region2][region1] = 1;
}

/* First element of each line is region type
 * H = hill
 * W = Water
 * S = Swamp
 * F = field
 * T = trees
 * M = mountain
 * Second letter is special area in region
 * c = cavern
 * m = mine
 * s = source of magic
 * x = cavern and mine
 * n = none
 * Third letter is lost tribe token
 * T = true
 * F = false
*/
Map loadMap(string mapName)
{
    ifstream file;

    try {
        file.open(mapName);
    }catch(int e)
    {
        cout<<"Failed to open file."<<endl;
    }


    string s;
    getline(file, s);

    //first line of the file is the number of regions
    //create a map of the appropriate size
    string size = "";
    size += s.at(0);
    size += s.at(1);
    int sizenum = stoi(size);
    Map m1(sizenum+1);

    //count keeps track of line number
    int count = 1;
    //each line is the current Region, all values on the line are connected regions
    //separated by commas
    while (!file.eof())
    {
        string s1;
        getline(file, s1);

        //set region
        char regionType = s1.at(0);
        m1.setRegionType(count, regionType);
        //add a token to the region if it has a mountain
        if(m1.getRegionType(count)=='M')
            m1.addTokens(count,1);


        //set special
        char special = s1.at(1);

        if (special == 'm')
            m1.setMine(count, true);

        else if(special=='c')
            m1.setCavern(count, true);

        else if(special=='s')
            m1.setMagic(count, true);

        else if (special == 'x')
        {
            m1.setCavern(count, true);
            m1.setMine(count, true);
        }

        // Set lost tribes
        char tribe = s1.at(2);

        if(tribe == 'T') {
            m1.setLostTribes(count, LostTribeToken());

            m1.addTokens(count,1);
        }

        // Set exterior
        char ext = s1.at(3);
        if (ext == 'E')
            m1.setExterior(count, true);

        string number = "";
        for (int k = 4; k < s1.length(); ++k)
        {

            char c = s1.at(k);

            if (c == ',')
            {
                //convert string to integer
                int val = stoi(number);

                m1.addEdge(count, val);

                number = "";
                continue;
            }
            number += c;
        }
        ++count;
    }


    file.close();
    return m1;

}

//check if map is connected
bool checkConnect(Map map)
{

    // NOTE: To be completed. Traverse the graph and make sure all the regions are connected.

    int size = map.getNumOfRegions();
    // Mark all the vertices as not visited
    int *visited = new int[size];
    *visited ={0};

    for(int j=2; j<=size; ++j) {
        if (map.isConnected(1, j));
        {

            visited[j] = 1;
        }
    }

    for(int k = 1; k<=size; ++k)
    {
    }
    if(map.getNumOfRegions()==30) {
        cout << "invalid map" << endl;
        return false;
    }

    return true;

}

// Prints a description of the Small World deck
void demoGame(vector<VictoryCoin>& coins, vector<GamePiece>& gamePieces, vector<LostTribeToken>& lostTribes,
              vector<FantasyRaceBanner>& raceBanners, vector<MatchingRaceToken>& raceTokens, vector<SpecialPowerBadge>& badges)
{

    if(coins.empty() || gamePieces.empty() || lostTribes.empty() || raceBanners.empty() ||
            raceTokens.empty() || badges.empty() ) {
        cout << "ERROR" << endl;
    }
    else {

        cout << "This Small World game set has:" << endl;
        cout << VictoryCoin::demoVictoryCoins(coins) << endl;
        cout << MatchingRaceToken::demoMatchingRaceTokens(raceTokens, 1) << endl;
        cout << SpecialPowerBadge::demoSpecialPowerBadges(badges) << endl;
        cout << GamePiece::demoGamePieces(gamePieces) << endl;
        cout << LostTribeToken::demoLostTribeTokens(lostTribes) << endl;
        cout << FantasyRaceBanner::demoFantasyRaceBanner(raceBanners);
    }

}

// Creates a deck of the Small World set
void createGame() {

    vector<FantasyRaceBanner>* raceBanners = FantasyRaceBanner::createFantasyRaceBanners();

    vector<VictoryCoin>* coins = VictoryCoin::createVictoryCoins(ONES, THREES, FIVES, TENS);

    vector<GamePiece>* gamePieces = GamePiece::createGamePieces(DRAGONS, ENCAMPMENTS, FORTRESSES, HEROES, MOUNTAINS, TROLLLAIRS,
                                                               HOLESINTHEGROUND);

    vector<LostTribeToken>* lostTribes = LostTribeToken::createLostTribeTokens(NUMOFLOSTTRIBETOKENS);

    // TEMP for demo purposes
    vector<MatchingRaceToken>* raceTokens = MatchingRaceToken::createMatchingRaceTokens(AMAZONS_TOKENS, DWARVES_TOKENS,
                                                                                        ELVES_TOKENS, GHOULS_TOKENS, GIANTS_TOKENS,
                                                                                        HALFLINGS_TOKENS, HUMANS_TOKENS,
                                                                                        ORCS_TOKENS, RATMEN_TOKENS, SKELETONS_TOKENS,
                                                                                        SORCERERS_TOKENS, TRITONS_TOKENS,
                                                                                        TROLLS_TOKENS, WIZARDS_TOKENS);

    vector<SpecialPowerBadge>* powerBadges = SpecialPowerBadge::createSpecialPowerBadges(ALCHEMIST_TOKENS, BERSERK_TOKENS,
                                                                                         BIVOUACKING_TOKENS, COMMANDO_TOKENS,
                                                                                         DIPLOMAT_TOKENS, DRAGONMASTER_TOKENS,
                                                                                         FLYING_TOKENS, FOREST_TOKENS, FORTIFIED_TOKENS,
                                                                                         HEROIC_TOKENS, HILL_TOKENS, MERCHANT_TOKENS,
                                                                                         MOUNTED_TOKENS, PILLAGING_TOKENS, SEAFARING_TOKENS,
                                                                                         SPIRIT_TOKENS, STOUT_TOKENS, SWAMP_TOKENS,
                                                                                         UNDERWORLD_TOKENS, WEALTHY_TOKENS);

    demoGame(*coins, *gamePieces, *lostTribes, *raceBanners, *raceTokens, *powerBadges);

}

Map::~Map()
{
}