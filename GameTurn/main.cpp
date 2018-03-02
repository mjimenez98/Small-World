//
// Created by Miguel Jimenez on 3/1/18.
//

#include "GameTurn.h"
#include "../Player/Player.h"
#include "../VictoryCoin/VictoryCoin.h"

using namespace std;

int main() {

    Map map = loadMap("../textMaps/2Players.txt");

    auto *gameTurn = new GameTurn();
    auto *player1 = new Player();

    cout << "///  PART 1  ///" << endl;
    cout << gameTurn->toString() << endl;
    gameTurn->setTurn(gameTurn->getTurn()+1);
    cout << endl;

    cout << "///  PARTS 2 and 3  ///" << endl;
    (*player1).picks_race();

    cout << "///  PART 4  ///" << endl;
    cout << "Regions with Lost Tribes:" << endl;
    for(int i=0; i<map.getNumOfRegions(); i++) {

        if(map.hasLostTribes(i)) {
            cout << to_string(i) << endl;
        }

    }
    cout << endl;

    cout << "///  PART 5  ///" << endl;
    cout << "Regions with Mountains:" << endl;
    for(int i=0; i<map.getNumOfRegions(); i++) {

        if(map.hasMountains(i)) {
            cout << to_string(i) << endl;
        }

    }
    cout << endl;

    // When each player is created, 5 coins of value 1 are automatically given. See Player().
    cout << "///  PART 6  ///" << endl;
    cout << VictoryCoin::demoVictoryCoins(player1->getCoins());

    return 0;

}