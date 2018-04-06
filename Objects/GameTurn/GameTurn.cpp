//
// Created by Miguel Jimenez on 2/28/18.
//

#include "GameTurn.h"

GameTurn::GameTurn() {

    turn = 1;

}

int GameTurn::getTurn() {

    return turn;

}

void GameTurn::setTurn(int newTurn) {

    turn = newTurn;

}

string GameTurn::toString() {

    return "Turn: " + to_string(getTurn());

}