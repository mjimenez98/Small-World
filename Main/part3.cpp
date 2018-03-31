//
// Created by Miguel Jimenez on 3/30/18.
//

#include "../Objects/Player/Player.h"
#include"../MainLoop/MainLoop.h"
#include "../Patterns/Observer/Observer.h"
#include "../Patterns/Strategy/Aggressive.h"
#include "../Patterns/Strategy/Defensive.h"
#include "../Patterns/Strategy/Moderate.h"
#include "../Patterns/Strategy/Random.h"

using namespace std;

int main() {

    vector<FantasyRaceBanner>* raceBanners = FantasyRaceBanner::createFantasyRaceBanners();

    int opponentType = 0;
    bool loop = true;

    while(loop) {
        cout << "Choose your opponent:" << endl
             << "1. Aggressive" << endl
             << "2. Defensive" << endl
             << "3. Moderate" << endl
             << "4. Random" << endl;
        cin >> opponentType;
        if (opponentType < 1 || opponentType > 4)
            cout << "Invalid input." << endl;
        else
            loop = false;
    }

    Map m1 = loadMap("../textMaps/2Players.txt");
    Map* map = &m1;
    if (!checkConnect(m1))
        return (0);

    Player p1 = Player(map);

    switch(opponentType)
    {
        case 1:
        {
            Aggressive p2 = Aggressive(map);
            cout << "Loaded the 2 player map and created 2 players" << endl << endl;

            Observer::notifyPlayer(1);
            p1.picks_race(*raceBanners);
            p1.firstConquer();
            p1.redeploy();
            p1.scores();

            Observer::notifyPlayer(2);
            p2.picks_race(*raceBanners);
            p2.firstConquer();
            p2.redeploy();
            p2.scores();

            MainLoop play(&p1,&p2);
            play.playGame(*raceBanners);
            break;
        }
        case 2:
        {
            Defensive p2 = Defensive(map);
            cout << "Loaded the 2 player map and created 2 players" << endl << endl;

            Observer::notifyPlayer(1);
            p1.picks_race(*raceBanners);
            p1.firstConquer();
            p1.redeploy();
            p1.scores();

            Observer::notifyPlayer(2);
            p2.picks_race(*raceBanners);
            p2.firstConquer();
            p2.redeploy();
            p2.scores();

            MainLoop play(&p1,&p2);
            play.playGame(*raceBanners);
            break;
        }
        case 3:
        {
            Moderate p2 = Moderate(map);
            cout << "Loaded the 2 player map and created 2 players" << endl << endl;

            Observer::notifyPlayer(1);
            p1.picks_race(*raceBanners);
            p1.firstConquer();
            p1.redeploy();
            p1.scores();

            Observer::notifyPlayer(2);
            p2.picks_race(*raceBanners);
            p2.firstConquer();
            p2.redeploy();
            p2.scores();

            MainLoop play(&p1,&p2);
            play.playGame(*raceBanners);
            break;
        }
        case 4:
        {
            Random p2 = Random(map);
            cout << "Loaded the 2 player map and created 2 players" << endl << endl;

            Observer::notifyPlayer(1);
            p1.picks_race(*raceBanners);
            p1.firstConquer();
            p1.redeploy();
            p1.scores();

            Observer::notifyPlayer(2);
            p2.picks_race(*raceBanners);
            p2.firstConquer();
            p2.redeploy();
            p2.scores();

            MainLoop play(&p1,&p2);
            play.playGame(*raceBanners);
            break;
        }
        default: cout << "switch error" << endl; break;

    }

    return 0;
};
