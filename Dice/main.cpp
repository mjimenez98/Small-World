//
// Created by Miguel Jimenez on 2/13/18.
//

#include "Dice.h"

int main()
{

    // This main creates a dice, rolls it several times and displays a percentage of the numbers rolled

    Dice d1;
    //cout<< "You rolled a: "<<d1.roll(3)<<"\n "<<endl;

    for (int k = 0; k < 1000; ++k)
        d1.roll();

    d1.displayPercentages();
}
