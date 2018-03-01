#pragma once
#include <string>

using namespace std;

class Map
{

public:
	// Constructors
	Map(int);

	// Deconstructors
	~Map();

	// Getters
	int getNumOfRegions();
	int getTokens(int);
	string getRegionPlayer(int);
	char getRegionType(int);

	// Setters
	void setCavern(int, bool);
	void setExterior(int, bool);
	void setMine(int, bool);
	void setMagic(int, bool);
	void setRegionPlayer(int, string);
	void setRegionType(int, char);
	void setTokens(int,int);

	// Is
	bool isCavern(int);
	bool isExterior(int);
	bool isMagic(int);
	bool isMine(int);
	bool isConnected(int, int);

	// Other functions
	void addEdge(int,int);

private:
	struct Region;
	int numOfRegions;
	Region * regions;
	int connections[50][50] = { {0} };

};

Map loadMap(string);
