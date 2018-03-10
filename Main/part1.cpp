#include "../Map/Map.h"
#include "../Player/Player.h"

using namespace std;

int main()
{
    int players = 0;
    bool loop = true;
    while(loop) {
        cout << "How many people will be playing?" << endl;
        cin >> players;
        if (players < 2 || players>5)
        {
            cout<<"Invalid number of players."<<endl;
        }

        else
            loop = false;
    }

    switch(players)
    {
        case 2: {Map map = loadMap("../textMaps/2Players.txt");
            if( !checkConnect(map))
                return(0);
            Player player1;
            Player player2;
            cout<<"Loaded the 2 player map and created 2 players"<<endl;break;}
        case 3:{ Map map = loadMap("../textMaps/3Players.txt");
            if( !checkConnect(map))
                return(0);
            Player player1;
            Player player2;
            Player player3;
            cout<<"Loaded the 3 player map and created 3 players"<<endl;break;}
        case 4:{ Map map = loadMap("../textMaps/4Players.txt");
            if( !checkConnect(map))
                return(0);
            Player player1;
            Player player2;
            Player player3;
            Player player4;
            cout<<"Loaded the 4 player map and created 4 players"<<endl;break;}
        case 5:{ Map map = loadMap("../textMaps/5Players.txt");
            if( !checkConnect(map))
                return(0);
            Player player1;
            Player player2;
            Player player3;
            Player player4;
            Player player5;
            cout<<"Loaded 5 player map and created 5 players"<<endl;break;}
        default : cout<<"switch error"<<endl;break;

    }
    createGame();
}




