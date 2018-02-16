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

	
	//test for loading a map
	Map m1 = loadMap("textMaps/5Players.txt");

	cout << m1.isConnected(7, 18) << endl;
	cout << m1.isConnected(35, 24) << endl;
	cout << m1.isConnected(44, 30) << endl;
	cout << m1.isConnected(3, 12) << endl;
	cout << m1.isConnected(16, 15) << endl;
	cout << m1.isConnected(21, 23) << endl;
	cout << m1.getRegionType(3) << endl;
	cout << m1.getMagic(9) << endl;

	
	system("pause");
	return 0;
}