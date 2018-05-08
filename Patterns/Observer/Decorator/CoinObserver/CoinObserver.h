//
// Created by Miguel Jimenez on 5/7/18.
//

#ifndef SMALL_WORLD_COINOBSERVER_H
#define SMALL_WORLD_COINOBSERVER_H

#include "../Decorator.h"

class CoinObserver: public Decorator {

public:
    explicit CoinObserver(Observer*w): Decorator(w){}
    void notifyCoins(int) override;

};

#endif //SMALL_WORLD_COINOBSERVER_H
