#include "Map.h"
#include <iostream>

using namespace std;

int main()
{
    //test for creating a Map

    /*Map m1(10);
    m1.addEdge(1, 2);
    m1.addEdge(1, 6);
    m1.addEdge(10, 2);
    m1.addEdge(6, 5);

    cout<<m1.isConnected(1, 2)<<endl;
    cout << m1.isConnected(2, 1) << endl;
    cout << m1.isConnected(1, 6) << endl;
    cout << m1.isConnected(10, 2) << endl;
    cout << m1.isConnected(5, 6) << endl;
    cout << m1.isConnected(5, 7) << endl;
    cout << m1.isConnected(1, 8) << endl;

    m1.setRegionPlayer(2, "p1");
    m1.setTokens(4, 8);
    cout << m1.getTokens(4) << endl;
    cout << m1.getRegionPlayer(2) << endl;*/


    //test for loading a map that is the wrong format
    //Map m = loadMap("textMaps/Fail.txt");

    //test for loading ap
    Map m1 = loadMap("../textMaps/5Players.txt");

    cout << "Are regions 7 and 18 connected? " << m1.isConnected(7, 18) << endl;
    cout << "Are regions 35 and 24 connected? " << m1.isConnected(35, 24) << endl;
    cout << "Are regions 44 and 30 connected? " << m1.isConnected(44, 30) << endl;
    cout << "Are regions 3 and 12 connected? " << m1.isConnected(3, 12) << endl;
    cout << "Are regions 16 and 1 connected? " << m1.isConnected(16, 1) << endl;
    cout << "Are regions 21 and 23 connected? " << m1.isConnected(21, 23) << endl;
    cout << "What is region 3's type? " << m1.getRegionType(3) << endl;
    cout << "Does region 9 have magic? " << m1.getMagic(9) << endl;
    cout << "Is region 10 exterior? " << m1.getExterior(10) << endl;

    return 0;
}