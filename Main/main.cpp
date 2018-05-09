//
// Created by Miguel Jimenez on 3/30/18.
//

#include "../Objects/Player/Player.h"
#include"../MainLoop/MainLoop.h"
#include "../Patterns/Observer/Observer/Observer.h"
#include "../Patterns/Strategy/Aggressive.h"
#include "../Patterns/Strategy/Defensive.h"
#include "../Patterns/Strategy/Moderate.h"
#include "../Patterns/Strategy/Random.h"

using namespace std;

int main() {

    bool loop = true;
    int input = -1;

    Observer obs;
    Map map;

    vector<FantasyRaceBanner>* raceBanners = FantasyRaceBanner::createFantasyRaceBanners();

    // MAIN MENU

    cout << "WELCOME TO SMALL WORLD!" << endl << endl << endl;

    while(loop) {
        cout << "Select mode:" << endl;
        cout << "1. Solo" << endl;
        cout << "2. Multiplayer" << endl;
        cin >> input;
        if (input < 1 || input > 2)
            cout << "Invalid input." << endl << endl;
        else
            loop = false;
    }
    loop = true;
    cout << endl << endl;


    // PlAYER SELECTION

    // If solo
    if(input == 1) {

        while(loop) {
            cout << "Select oponent:" << endl;
            cout << "1. Aggressive" << endl;
            cout << "2. Defensive" << endl;
            cout << "3. Moderate" << endl;
            cout << "4. Random" << endl;
            cin >> input;
            if (input < 1 || input > 4)
                cout << "Invalid input." << endl << endl;
            else
                loop = false;
        }
        loop = true;
        cout << endl << endl;

        // Notify Observer of number of players
        obs.notifyNumberOfPlayers(input);

        cout << "Let the Small World conquest begin!" << endl;

        // Load map and create Player 1
        map = loadMap("../textMaps/2Players.txt");
        Player p1 = Player(&map);

        // Create proper opponent and load map
        switch(input) {

            case 1: {
                Aggressive p2 = Aggressive(&map);

                MainLoop play(&p1, &p2, *raceBanners);
                play.playGame(*raceBanners);
                break;
            }
            case 2: {
                Defensive p2 = Defensive(&map);

                MainLoop play(&p1, &p2, *raceBanners);
                play.playGame(*raceBanners);
                break;
            }
            case 3: {
                Moderate p2 = Moderate(&map);

                MainLoop play(&p1, &p2, *raceBanners);
                play.playGame(*raceBanners);
                break;
            }
            case 4: {
                Random p2 = Random(&map);

                MainLoop play(&p1, &p2, *raceBanners);
                play.playGame(*raceBanners);
                break;
            }
            default: {
                cerr << "ERROR: Opponent not found" << endl;
                break;
            }

        }

    }
    // If multiplayer
    else {

        while(loop) {
            cout << "Type in the number of players (2-5):" << endl;
            cin >> input;
            if (input < 2 || input > 5)
                cout << "Invalid input." << endl << endl;
            else
                loop = false;
        }
        loop = true;
        cout << endl << endl;

        // Notify Observer of number of players
        obs.notifyNumberOfPlayers(input);

        cout << "Let the Small World conquest begin!" << endl;

        // Create proper number of players and according map
        switch(input) {

            case 2: {
                map = loadMap("../textMaps/2Players.txt");

                Player p1 = Player(&map);
                Player p2 = Player(&map);

                MainLoop play(&p1, &p2, *raceBanners);
                play.playGame(*raceBanners);
                break;
            }
            case 3: {
                map = loadMap("../textMaps/3Players.txt");

                Player p1 = Player(&map);
                Player p2 = Player(&map);
                Player p3 = Player(&map);

                MainLoop play(&p1, &p2, &p3, *raceBanners);
                play.playGame(*raceBanners);
                break;
            }
            case 4: {
                map = loadMap("../textMaps/4Players.txt");

                Player p1 = Player(&map);
                Player p2 = Player(&map);
                Player p3 = Player(&map);
                Player p4 = Player(&map);

                MainLoop play(&p1, &p2, &p3, &p4, *raceBanners);
                play.playGame(*raceBanners);
                break;
            }
            case 5: {
                map = loadMap("../textMaps/5Players.txt");

                Player p1 = Player(&map);
                Player p2 = Player(&map);
                Player p3 = Player(&map);
                Player p4 = Player(&map);
                Player p5 = Player(&map);

                MainLoop play(&p1, &p2, &p3, &p4, &p5, *raceBanners);
                play.playGame(*raceBanners);
                break;
            }
            default: {
                cerr << "ERROR: Players could not be created" << endl;
                break;
            }

        }

    }

};
