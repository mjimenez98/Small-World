//
// Created by Miguel Jimenez on 5/7/18.
//

#include "HandObserver.h"

void HandObserver::notifyHand(string s1)
{
    Decorator::notifyHand(s1);

    //print player hands
    for(int j =0; j<playerhands.size();++j)
    {
        cout << "Player " << j+1 << "'s hand: " << playerhands[j] << endl;
    }

}
