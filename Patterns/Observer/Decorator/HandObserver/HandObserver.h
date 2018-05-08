//
// Created by Miguel Jimenez on 5/7/18.
//

#ifndef SMALL_WORLD_HANDOBSERVER_H
#define SMALL_WORLD_HANDOBSERVER_H

#include "../Decorator.h"

//displays player hands
class HandObserver: public Decorator {

public:
    explicit HandObserver(Observer*w): Decorator(w){}
    void notifyHand(string) override;

};

#endif //SMALL_WORLD_HANDOBSERVER_H
