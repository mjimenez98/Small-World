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

int VictoryCoin::getValue() {

    return value;

}

void VictoryCoin::setValue(int newValue) {

    value = newValue;

}

// Prints a description of all the Victory Coins created
string VictoryCoin::demoVictoryCoins(vector<VictoryCoin>& coins) {

    if(coins.empty()) {
        return "ERROR: no coins";
    }
    else {

        int ones = 0;
        int threes = 0;
        int fives = 0;
        int tens = 0;
        string demo = "Victory Coins:\n";

        for(VictoryCoin coin : coins) {

            switch(coin.getValue()) {

                case 1: ones++; break;
                case 3: threes++; break;
                case 5: fives++; break;
                case 10: tens++; break;
                default: break;

            }

        }

        if(tens > 0)
            demo += "- " + to_string(tens) + " of value 10\n";
        if(fives > 0)
            demo += "- " + to_string(fives) + " of value 5\n";
        if(threes > 0)
            demo += "- " + to_string(threes) + " of value 3\n";
        if(ones > 0)
            demo += "- " + to_string(ones) + " of value 1\n";

        return demo;

    }

}

// Sets up victory coins. The stock version of Small World has 35 1's, 20 3's, 24 5's and 30 10's
vector<VictoryCoin>* VictoryCoin::createVictoryCoins(int numOfOnes, int numOfThrees, int numOfFives, int numOfTens) {

    auto * coins = new vector<VictoryCoin>;

    for(int i=0; i<numOfOnes; i++) {
        (*coins).emplace_back(VictoryCoin(1));
    }

    for(int i=0; i<numOfThrees; i++) {
        (*coins).emplace_back(VictoryCoin(3));
    }

    for(int i=0; i<numOfFives; i++) {
        (*coins).emplace_back(VictoryCoin(5));
    }

    for(int i=0; i<numOfTens; i++) {
        (*coins).emplace_back(VictoryCoin(10));
    }

    return coins;

}