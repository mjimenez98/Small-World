#pragma once

#include "../Player/Player.h"

#include <string>

using namespace std;

class Map
{
	
	struct Region;
	int spaces;
	Region * regions;
	int connections[50][50] = { {0} };
	

public:
	void addEdge(int,int);
	bool isConnected(int, int);
	void setTokens(int,int);
	void setRegionPlayer(int, string);
	string getRegionPlayer(int);
	int getTokens(int);
	void setRegionType(int, char);
	char getRegionType(int);
	void setCavern(int, bool);
	bool getCavern(int);
	void setMine(int, bool);
	bool getMine(int);
	void setMagic(int, bool);
	bool getMagic(int);


	Map(int);
	 
	~Map();
};

Map loadMap(string);

