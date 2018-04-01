//
// Created by Jean-Loup on 2018-03-20.
//


#ifndef SMALL_WORLD_OBSERVER_H
#define SMALL_WORLD_OBSERVER_H

#include <string>
#include <initguid.h>
#include <vector>


using namespace std;

class ObserverInterface
{
public:
    virtual void notifyAction(std::string)=0;
    virtual void notifyPlayer(int)=0;
    virtual void notifyRegionsOwned(int)=0;
    virtual void notifyNumberOfPlayers(int)=0;
    virtual void notifyHand(string)=0;
    virtual void notifyCoins(int)=0;


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

    static vector<string> playerhands;
    static vector<int> playerCoins;
};


//concrete basic Observer
class Observer: public ObserverInterface {
public:
     void notifyAction(std::string) override;
     void notifyPlayer(int) override;
     void notifyRegionsOwned(int) override;
     void notifyNumberOfPlayers(int) override;
     void notifyHand(string) override ;
     void notifyCoins(int) override ;


    //Current player
    int playerNumber;
    static int numberOfPlayers;
    static int numberOfRegions;

    //number of regions owned by each player
    static int regions1;
    static int regions2;
    static int regions3;
    static int regions4;
    static int regions5;

    //string vector with contents of all player's hands
    static vector<string> playerhands;
    static vector<int> playerCoins;

};

class Decorator : public Observer
{
public:
    Decorator(Observer * tempObs);

    void notifyAction(std::string) override ;
    void notifyPlayer(int) override;
    void notifyRegionsOwned(int) override;
    void notifyNumberOfPlayers(int) override;
    void notifyHand(string) override ;
    void notifyCoins(int) override ;


protected:
    Observer * obs;
};
// observer displays percentage of owned regions
class GraphObserver: public Decorator{

public:
    GraphObserver(Observer*w): Decorator(w){}
    void printGraph();
    void notifyRegionsOwned(int) override ;

};
//displays player hands
class HandObserver: public Decorator{

public:
    HandObserver(Observer*w): Decorator(w){}
    void notifyHand(string) override ;

};

class CoinObserver: public Decorator{

public:
    CoinObserver(Observer*w): Decorator(w){}
    void notifyCoins(int) override ;

};



#endif //SMALL_WORLD_OBSERVER_H
