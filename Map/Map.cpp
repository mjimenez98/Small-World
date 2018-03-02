#include "Map.h"

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;


struct Map::Region {

    int tokens;
    string player;
    char regionType=NULL;
    //H=hill
    //W=Water
    //S=Swamp
    //F=field
    //T=trees
    //M=mountain

    bool cavern = false;
    bool mine = false;
    bool magic = false;
    bool exterior = false;
};
//getter and setters

void Map::setExterior(int n, bool b)
{
    regions[n].exterior = b;
}

bool Map::getExterior(int n)
{

    if(n > getNumOfRegions())
        return false;

    return regions[n].exterior;
}

void Map::setCavern(int n, bool b)
{
    regions[n].cavern = b;
}

bool Map::getCavern(int n)
{
    return regions[n].cavern;
}
void Map::setMine(int n, bool b)
{
    regions[n].mine = b;
}

bool Map::getMine(int n)
{
    return regions[n].mine;
}
void Map::setMagic(int n, bool b)
{
    regions[n].magic = b;
}

bool Map::getMagic(int n)
{
    return regions[n].magic;
}
void Map::setRegionType(int n, char c)
{
    regions[n].regionType = c;
}
char Map::getRegionType(int n)
{
    return regions[n].regionType;
}
void Map::setTokens(int n,int tokens)
{
    regions[n].tokens = tokens;
}

int Map::getTokens(int n)
{
    return regions[n].tokens;
}

void Map::setRegionPlayer(int n,string p)
{
    regions[n].player = p;
}

string Map::getRegionPlayer(int n)
{
    return regions[n].player;
}

Map::Map(int s)
{
    regions = new Region[s];
    numOfRegions = s;

};
int Map::getNumOfRegions(){
    return numOfRegions;
}


void Map::addEdge(int n1, int n2)
{
    connections[n1][n2] = 1;
    connections[n2][n1] = 1;

};

bool Map::isConnected(int n1, int n2)
{
    if (connections[n1][n2] == 1)
        return true;

    return false;
}

//First element of each line is region type
//H=hill
//W=Water
//S=Swamp
//F=field
//T=trees
//M=mountain
//second letter is special area in region
//c=cavern
//m=mine
//s=source of magic
//x=cavern and mine
//n = none

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
    Map m1(sizenum+5);

    //count keeps track of line number
    int count = 1;
    //each line is the current Region, all values on the line are connected regions
    //seperated by commas
    while (!file.eof())
    {
        string s1;
        getline(file, s1);

        //set region
        char regionType = s1.at(0);
        m1.setRegionType(count, regionType);

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
        //set exterior
        char ext = s1.at(2);
        if (ext == 'E')
            m1.setExterior(count, true);

        string number = "";
        for (unsigned int k = 3; k < s1.length()-3; ++k)
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
    int size = map.getNumOfRegions();
    // Mark all the vertices as not visited
    int *visited = new int[size];
    *visited ={0};


    for(int j =2; j<=size; ++j) {
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



Map::~Map()
{
}