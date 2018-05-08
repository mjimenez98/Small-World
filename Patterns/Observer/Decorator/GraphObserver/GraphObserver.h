//
// Created by Miguel Jimenez on 5/7/18.
//

#ifndef SMALL_WORLD_GRAPHOBSERVER_H
#define SMALL_WORLD_GRAPHOBSERVER_H

#include "../Decorator.h"

#include <iomanip>

// observer displays percentage of owned regions
class GraphObserver: public Decorator {

public:
    explicit GraphObserver(Observer*w): Decorator(w){}
    void printGraph();
    void notifyRegionsOwned(int) override;

};

#endif //SMALL_WORLD_GRAPHOBSERVER_H
