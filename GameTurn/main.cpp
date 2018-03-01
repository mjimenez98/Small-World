//
// Created by Miguel Jimenez on 3/1/18.
//

#include "GameTurn.h"
#include "../Player/Player.h"

using namespace std;

void runDemo(GameTurn* gameTurn, Player player1) {

    player1.picks_race();

    cout << gameTurn->toString() << endl;
    gameTurn->setTurn(gameTurn->getTurn()+1);

}

int main() {

    GameTurn *gameTurn;
    *gameTurn = GameTurn();

    Player player1;

    // Demo
    runDemo(gameTurn, player1);

    return 0;
    
}