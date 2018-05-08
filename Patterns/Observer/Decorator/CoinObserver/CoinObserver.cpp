//
// Created by Miguel Jimenez on 5/7/18.
//

#include "CoinObserver.h"

void CoinObserver::notifyCoins(int coins)
{
    Decorator::notifyCoins(coins);

    //print player coins
    for(int j =0; j<playerCoins.size();++j)
    {
        cout << "Player " << j+1 << " has " << playerCoins[j] << " coins" << endl;
    }

}
