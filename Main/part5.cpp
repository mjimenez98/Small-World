//
// Created by Miguel Jimenez on 2/4/18.
//

#include "../Player/Player.h"
#include <iostream>

using namespace std;

int main() {

    Map m1 = loadMap("../textMaps/2Players.txt");
    Map* map = &m1;
    GameTurn* gameTurn = new GameTurn();

    vector<FantasyRaceBanner>* raceBanners = FantasyRaceBanner::createFantasyRaceBanners();

    Player p1 = Player(map);

    p1.picks_race(*raceBanners);
    p1.firstConquer();
    p1.redeploy();
    p1.scores();

    cout << p1.toString();

    gameTurn->setTurn(gameTurn->getTurn()+1);
    delete gameTurn;

    return 0;
};