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

void VictoryCoin::givePlayerCoins() {

    // TBD

}

// Helper method to print and demonstrate different Victory Coins and their values
string printCoins(vector<VictoryCoin> coins, vector<int> positions) {

    string demo;
    int previous = 0;

    for(int position : positions) {
        demo += "\n- " + to_string(position-previous) + " of value " + to_string(coins[position-1].getValue());
        previous = position;
    }
    demo += "\n";

    return demo;

}

// Prints a description of all the Victory Coins created
string VictoryCoin::demoVictoryCoins(vector<VictoryCoin> coins) {

    if(coins.empty()) {
        return "ERROR";
    }
    else {
        vector<int> positions;

        for(int i=1; i<coins.size(); i++) {

            if(coins[i].getValue() != coins[i-1].getValue()) {
                positions.push_back(i);
            }

        }
        positions.push_back((int) coins.size());

        return "Victory Coins:" + printCoins(coins, positions);
    }

}

// Sets up victory coins. The stock version of Small World has 35 1's, 20 3's, 24 5's and 30 10's
vector<VictoryCoin> VictoryCoin::createVictoryCoins(int numOfOnes, int numOfThrees, int numOfFives, int numOfTens) {

    vector<VictoryCoin> coins;

    for(int i=0; i<numOfOnes; i++) {
        coins.emplace_back(VictoryCoin(1));
    }

    for(int i=0; i<numOfThrees; i++) {
        coins.emplace_back(VictoryCoin(3));
    }

    for(int i=0; i<numOfFives; i++) {
        coins.emplace_back(VictoryCoin(5));
    }

    for(int i=0; i<numOfTens; i++) {
        coins.emplace_back(VictoryCoin(10));
    }

    return coins;

}