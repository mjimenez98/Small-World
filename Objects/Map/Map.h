#pragma once


#include "../FantasyRaceBanner/FantasyRaceBanner.h"
#include "../LostTribeToken/LostTribeToken.h"
#include "../GamePiece/GamePiece.h"
#include "../VictoryCoin/VictoryCoin.h"



#include <string>

using namespace std;

class Map
{

public:
	// Constructors
    Map();
    explicit Map(int newNumOfRegions);

	// Getters
	int getNumOfRegions();
	int getTokens(int region);
	int getRegionPlayer(int region);
	char getRegionType(int region);
	string getTokensType(int region);

	// Setters
	void addTokens(int region, int tokens);
	void setCavern(int region, bool state);
	void setExterior(int region, bool state);
	void setInDecline(int region, bool state);
	void setLostTribes(int region, LostTribeToken newToken);
	void setMine(int region, bool state);
	void setMagic(int region, bool state);
	void setRegionPlayer(int region, int player);
	void setRegionType(int region, char type);
	void setTokensType(string type, int region);
	void setTokens(int region, int tokens);
	void setHadGhouls(int region, bool state);

	// Is
	bool isCavern(int region);
	bool isConnected(int region1, int region2);
	bool isExterior(int region);
	bool isMagic(int region);
	bool isMine(int region);
	bool isInDecline(int region);

	// Has
	bool hasFortress(int region);
	bool hasMountains(int region);
	bool hasLostTribes(int region);
	bool hadGhouls(int region);

	// Other functions
	void addEdge(int region1, int region2);

	// Destructor
	~Map();

private:
	struct Region;
	int numOfRegions;
	Region * regions;
	int connections[50][50] = { {0} };

};

Map loadMap(string mapName);
void createGame();