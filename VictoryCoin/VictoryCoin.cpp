//
// Created by Miguel Jimenez on 2/6/18.
//

#include "VictoryCoin.h"

VictoryCoin::VictoryCoin() {

    value = -1;

}

VictoryCoin::VictoryCoin(int newValue) {

    value = newValue;

}

void VictoryCoin::givePlayerCoins() {

    //TBD

}

//Sets up victory coins. The stock version of Small World has 35 1's, 20 3's, 24 5's and 30 10's
VictoryCoin VictoryCoin::createVictoryCoins(int numOfOnes, int numOfThrees, int numOfFives, int numOfTens) {

    VictoryCoin coins[numOfOnes+numOfThrees+numOfFives+numOfTens];

    int index = 0;

    for(int i=0; i<numOfOnes; i++) {
        coins[index++] = VictoryCoin(1);
    }

    for(int i=0; i<numOfThrees; i++) {
        coins[index++] = VictoryCoin(3);
    }

    for(int i=0; i<numOfFives; i++) {
        coins[index++] = VictoryCoin(5);
    }

    for(int i=0; i<numOfTens; i++) {
        coins[index++] = VictoryCoin(10);
    }

    return *coins;

}