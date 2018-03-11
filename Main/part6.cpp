//
// Created by Miguel Jimenez on 3/7/18.
//

#include "../Player/Player.h"

using namespace std;

int main() {

    Map m1 = loadMap("../textMaps/2Players.txt");
    Map* map = &m1;
    GameTurn* gameTurn = new GameTurn();
    vector<FantasyRaceBanner>* raceBanners = FantasyRaceBanner::createFantasyRaceBanners();

    Player p1 = Player(*map, *gameTurn);

    p1.picks_race(*raceBanners);
    p1.firstConquer(map);
    p1.scores();

    cout << p1.toString();

    gameTurn->setTurn(gameTurn->getTurn()+1);
    delete gameTurn;

    return 0;
};
