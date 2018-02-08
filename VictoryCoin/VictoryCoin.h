//
// Created by Miguel Jimenez on 2/6/18.
//

#ifndef SMALL_WORLD_VICTORYCOIN_H
#define SMALL_WORLD_VICTORYCOIN_H

//Quantities
const int ONES = 35;
const int THREES = 20;
const int FIVES = 24;
const int TENS = 30;

class VictoryCoin {

public:
    VictoryCoin();
    explicit VictoryCoin(int newValue);
    void givePlayerCoins();
    static VictoryCoin createVictoryCoins(int numOfOnes, int numOfThrees, int numOfFives, int numOfTens);

private:
    int value;

};

#endif //SMALL_WORLD_VICTORYCOIN_H
