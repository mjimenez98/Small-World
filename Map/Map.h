#pragma once
#include <string>

using namespace std;



class Map
{

	struct Region;
	int numOfRegions;
	Region * regions;
	int connections[50][50] = { {0} };


public:
	int getNumOfRegions();
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
	bool getExterior(int);
	void setExterior(int, bool);



	Map(int);

	~Map();
};
Map loadMap(string);
bool checkConnect(Map);


