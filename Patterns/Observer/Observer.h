//
// Created by Jean-Loup on 2018-03-20.
//


#ifndef SMALL_WORLD_OBSERVER_H
#define SMALL_WORLD_OBSERVER_H

#include <string>

using namespace std;


class Observer {
public:
    static void notifyAction(std::string);
    static void notifyPlayer(int);
    static void notifyRegionsOwned(int);
    static void notifyNumberOfPlayers(int);
    static void printGraph();

    //Current player
    static int playerNumber;
    static int numberOfPlayers;
    static int numberOfRegions;
    //number of regions owned by each player

    static int regions1;
    static int regions2;
    static int regions3;
    static int regions4;
    static int regions5;


};


#endif //SMALL_WORLD_OBSERVER_H
