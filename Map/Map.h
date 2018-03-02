#pragma once

#include "../LostTribeToken/LostTribeToken.h"
#include "../GamePiece/GamePiece.h"

#include <string>

using namespace std;

class Map
{

public:
	// Constructors
	Map(int newNumOfRegions);

	// Getters
	int getNumOfRegions();
	int getTokens(int region);
	string getRegionPlayer(int region);
	char getRegionType(int region);

	// Setters
	void setCavern(int region, bool state);
	void setExterior(int region, bool state);
	void setLostTribes(int region, LostTribeToken newToken);
	void setMine(int region, bool state);
	void setMagic(int region, bool state);
	void setRegionPlayer(int region, string player);
	void setRegionType(int region, char type);
	void setTokens(int, int);

	// Is
	bool isCavern(int region);
	bool isConnected(int region1, int region2);
	bool isExterior(int region);
	bool isMagic(int region);
	bool isMine(int region);

	// Has
	bool hasMountains(int region);
	bool hasLostTribes(int region);

	// Other functions
	void addEdge(int region1, int region2);

	// Deconstructors
	~Map();

private:
	struct Region;
	int numOfRegions;
	Region * regions;
	int connections[50][50] = { {0} };

};

Map loadMap(string mapName);