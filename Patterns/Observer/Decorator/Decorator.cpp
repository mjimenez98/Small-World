//
// Created by Miguel Jimenez on 5/7/18.
//

#include "Decorator.h"

Decorator::Decorator(Observer *tempObs) {

    obs = tempObs;

}

void Decorator::notifyAction(string action) {

    obs->notifyAction(action);

}

void Decorator::notifyPlayer(int playerNum) {

    obs->notifyPlayer(playerNum);

}

void Decorator::notifyRegionsOwned(int regionsOwned) {

    obs->notifyRegionsOwned(regionsOwned);

}

void Decorator::notifyNumberOfPlayers(int numberOfPlayers) {

    obs->notifyNumberOfPlayers(numberOfPlayers);

}

void Decorator::notifyHand(string hand) {

    obs->notifyHand(hand);

}

void Decorator::notifyCoins(int coins) {

    obs->notifyCoins(coins);

}