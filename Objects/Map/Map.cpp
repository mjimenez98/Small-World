#include "Map.h"

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

// Subclass: Region in map
struct Map::Region {

    int tokens = 0;
    string token_type;
    int  player = 0;
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
    bool hadGhouls = false;

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

int Map::getRegionPlayer(int region)
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

void Map::setRegionPlayer(int region, int p1)
{
    regions[region].player = p1;
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

void Map::setHadGhouls(int region, bool state) {

    regions[region].hadGhouls = state;

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

bool Map::hadGhouls(int region) {

    if(regions[region].hadGhouls == true) {
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

Map loadMap(string mapName) {

    /*
     * MAP FORMAT:
     *
     * Line 1: Number of regions
     *
     * Lines 2 - end:
     *      First character: region type
     *          H = hill
     *          W = Water
     *          S = Swamp
     *          F = field
     *          T = trees
     *          M = mountain
     *      Second character: special area in region
     *          c = cavern
     *          m = mine
     *          s = source of magic
     *          x = cavern and mine
     *          n = none
     *      Third character: presence of tribe tokens
     *          T = true
     *          F = false
     *      Fourth character: exterior or interior
     *          E = exterior
     *          I = interior
     *      Subsequent numbers: Adjacent regions
     *
     */

    ifstream file;

    try {
        file.open(mapName);
    }
    catch(...) {
        cerr << "ERROR: Failed to open file" << endl;
    }

    string line;
    getline(file, line);

    // Get number of regions
    string size;
    size += line.at(0);
    size += line.at(1);

    Map map(stoi(size)+1);

    int region = 1;

    while (!file.eof()) {

        getline(file, line);

        // Set region type
        char regionType = line.at(0);
        map.setRegionType(region, regionType);

        // Add a token to the region if it has a mountain
        if(map.getRegionType(region)=='M')
            map.addTokens(region,1);


        // Set special
        char special = line.at(1);

        if (special == 'm')
            map.setMine(region, true);

        else if(special=='c')
            map.setCavern(region, true);

        else if(special=='s')
            map.setMagic(region, true);

        else if (special == 'x')
        {
            map.setCavern(region, true);
            map.setMine(region, true);
        }


        // Set lost tribes
        char tribe = line.at(2);

        if(tribe == 'T') {
            map.setLostTribes(region, LostTribeToken());

            map.addTokens(region,1);
        }


        // Set exterior
        char ext = line.at(3);

        if (ext == 'E')
            map.setExterior(region, true);


        string number;
        for (int k = 4; k < line.length(); ++k) {

            char c = line.at((unsigned long) k);

            // If there is an adjacent region, add edge
            if (c == ',') {

                int val = stoi(number);

                map.addEdge(region, val);
                number = "";

                continue;

            }
            number += c;
        }
        ++region;

    }   // End of while

    file.close();
    return map;

}

// Creates a deck of the Small World set
void createGame() {

    vector<FantasyRaceBanner>* raceBanners = FantasyRaceBanner::createFantasyRaceBanners();

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


}

Map::~Map() {



}