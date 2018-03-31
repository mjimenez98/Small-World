//
// Created by Miguel Jimenez on 3/7/18.
//

#include "../Objects/Player/Player.h"
#include"../MainLoop/MainLoop.h"
#include "../Patterns/Observer/Observer.h"

using namespace std;

int main() {

    vector<FantasyRaceBanner>* raceBanners = FantasyRaceBanner::createFantasyRaceBanners();

    int numOfPlayers = 0;
    bool loop = true;

    while(loop) {
        cout << "How many people will be playing?" << endl;
        cin >> numOfPlayers;
        if (numOfPlayers < 2 || numOfPlayers > 5)
            cout << "Invalid number of players." << endl;
        else
            loop = false;
    }

    //notify Observer of number of players
    Observer::notifyNumberOfPlayers(numOfPlayers);

    switch(numOfPlayers)
    {
        case 2:
        {
            Map m1 = loadMap("../textMaps/2Players.txt");
            Map* map = &m1;
            if (!checkConnect(m1))
                return (0);
            Player p1 = Player(map);
            Player p2 = Player(map);
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
            Map m1 = loadMap("../textMaps/3Players.txt");
            Map* map = &m1;
            if(!checkConnect(m1))
                return(0);
            Player p1 = Player(map);
            Player p2 = Player(map);
            Player p3 = Player(map);
            cout << "Loaded the 3 player map and created 3 players" << endl << endl;
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
            Observer::notifyPlayer(3);
            p3.picks_race(*raceBanners);
            p3.firstConquer();
            p3.redeploy();
            p3.scores();
            MainLoop play(&p1,&p2,&p3);
            play.playGame(*raceBanners);
            break;
        }
        case 4:
        {
            Map m1 = loadMap("../textMaps/4Players.txt");
            Map* map = &m1;
            if(!checkConnect(m1))
                return(0);
            Player p1 = Player(map);
            Player p2 = Player(map);
            Player p3 = Player(map);
            Player p4 = Player(map);
            cout << "Loaded the 4 player map and created 4 players" << endl << endl;
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
            Observer::notifyPlayer(3);
            p3.picks_race(*raceBanners);
            p3.firstConquer();
            p3.redeploy();
            p3.scores();
            Observer::notifyPlayer(4);
            p4.picks_race(*raceBanners);
            p4.firstConquer();
            p4.redeploy();
            p4.scores();
            MainLoop play(&p1,&p2,&p3,&p4);
            play.playGame(*raceBanners);
            break;
        }
        case 5:
        {
            Map m1 = loadMap("../textMaps/5Players.txt");
            Map* map = &m1;
            if(!checkConnect(m1))
                return(0);
            Player p1 = Player(map);
            Player p2 = Player(map);
            Player p3 = Player(map);
            Player p4 = Player(map);
            Player p5 = Player(map);
            cout << "Loaded 5 player map and created 5 players" << endl << endl;
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
            Observer::notifyPlayer(3);
            p3.picks_race(*raceBanners);
            p3.firstConquer();
            p3.redeploy();
            p3.scores();
            Observer::notifyPlayer(4);
            p4.picks_race(*raceBanners);
            p4.firstConquer();
            p4.redeploy();
            p4.scores();
            Observer::notifyPlayer(5);
            p5.picks_race(*raceBanners);
            p5.firstConquer();
            p5.redeploy();
            p5.scores();
            MainLoop play(&p1,&p2,&p3,&p4,&p5);
            play.playGame(*raceBanners);
            break;
        }
        default: cout << "switch error" << endl; break;

    }





    return 0;
};
