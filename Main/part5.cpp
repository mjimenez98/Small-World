//
// Created by Miguel Jimenez on 3/7/18.
//

#include "../Player/Player.h"

using namespace std;

int main() {

    Map m1 = loadMap("../textMaps/2Players.txt");
    Map* map = &m1;
    vector<FantasyRaceBanner>* raceBanners = FantasyRaceBanner::createFantasyRaceBanners();

    Player p1 = Player();

    p1.picks_race(*raceBanners);
    p1.firstConquer(map);
    p1.scores();

    cout << p1.toString();

    return 0;
};
