//
// Created by Miguel Jimenez on 2/4/18.
//

#include "Player.h"
#include <iostream>

using namespace std;

int main() {

    Player p1 = Player();

    p1.picks_race();

    cout << p1.toString();

    return 0;
};