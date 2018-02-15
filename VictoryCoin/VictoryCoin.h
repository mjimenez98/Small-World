//
// Created by Miguel Jimenez on 2/6/18.
//

#ifndef SMALL_WORLD_VICTORYCOIN_H
#define SMALL_WORLD_VICTORYCOIN_H

#include <string>
#include <vector>

using namespace std;

// Quantities
const int ONES = 35;
const int THREES = 20;
const int FIVES = 24;
const int TENS = 30;

class VictoryCoin {

public:
    // Constructors
    VictoryCoin();
    explicit VictoryCoin(int newValue);

    // Getters
    int getValue();

    // Setters
    void setValue(int newValue);

    // Other functions
    void givePlayerCoins();
    static string demoVictoryCoins(vector<VictoryCoin> coins);
    static vector<VictoryCoin> createVictoryCoins(int numOfOnes, int numOfThrees, int numOfFives, int numOfTens);

private:
    int value;

};

#endif //SMALL_WORLD_VICTORYCOIN_H
