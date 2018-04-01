//
// Created by Jean-Loup on 2018-03-20.
//

#include "Observer.h"
#include <iostream>
#include <iomanip>


//total number of player's playing
int Observer::numberOfPlayers;
//total number of regions
int Observer::numberOfRegions;
//number of regions owned y each player;
int Observer::regions1;
int Observer::regions2;
int Observer::regions3;
int Observer::regions4;
int Observer::regions5;

 vector<string> Observer::playerhands ;
 vector<int> Observer::playerCoins;

//print player's current action
void Observer::notifyAction(string phase)
{
cout<<"\nPlayer "<<playerNumber<<" "<<phase<<endl;
}

//notifies Observer which player's turn it is
void Observer::notifyPlayer(int player)
{
    playerNumber = player;
}

//tell Observer number of players playing ,then  sets number of regions
void Observer::notifyNumberOfPlayers(int players)
{
    numberOfPlayers = players;
    if(players==2) { numberOfRegions = 23;}
    else if(players==3) { numberOfRegions = 30;}
    else if(players==4) { numberOfRegions = 39;}
    else if(players==5) { numberOfRegions = 48;}


}

//notify when the Observer when a player's region number changes
void Observer::notifyRegionsOwned(int regionsOwned)
{
    switch(playerNumber)
    {
        case 1: regions1 = regionsOwned;break;
        case 2: regions2 = regionsOwned;break;
        case 3: regions3 = regionsOwned;break;
        case 4: regions4 = regionsOwned;break;
        case 5: regions5 = regionsOwned;break;
    }
}

void Observer::notifyHand(string s1)
{
    playerhands.push_back(s1);
}

void Observer::notifyCoins(int coins)
{
    playerCoins.push_back(coins);
}


Decorator::Decorator(Observer *tempObs)
{
    obs = tempObs;
}
void Decorator::notifyAction(string string1)
{
    obs->notifyAction(string1);
}

void Decorator::notifyPlayer(int i )
{
    obs->notifyPlayer(i);
}

void Decorator::notifyRegionsOwned(int i)
{
    obs->notifyRegionsOwned(i);

}

void Decorator::notifyNumberOfPlayers(int i)
{
    obs->notifyNumberOfPlayers(i);
}

void Decorator::notifyHand(string s1)
{
    obs->notifyHand(s1);
}

void Decorator::notifyCoins(int i)
{
    obs->notifyCoins(i);
}

//the graph goes in increments of 2%, therefore only values above 2% will show up
void GraphObserver::printGraph()
{
    //percentage of regions owned;
    double percent1 =(((regions1/(double)numberOfRegions))*100);
    double percent2 =((regions2/(double)numberOfRegions)*100);
    double percent3 =((regions3/(double)numberOfRegions)*100);
    double percent4 =((regions4/(double)numberOfRegions)*100);
    double percent5 =((regions5/(double)numberOfRegions)*100);
    double unclaimed =  ((numberOfRegions-regions1-regions2-regions3-regions4-regions5)/(double)numberOfRegions)*100;




    cout<<"\n---------------------------Occupied Regions-------------------------"<<endl;

    switch(numberOfPlayers)
    {
        case 2: for(int j = 50 ; j>0; --j)
            {
               if(percent1>=j*2) { cout<< "|---|\t";}
               else{ cout<< "\t \t";}

                if(percent2>=j*2) { cout<< "\t|---|\t";}
                else{ cout<< "\t \t\t";}

                if(unclaimed>=j*2) { cout<< "\t|---|\t";}
                else{ cout<< "\t \t\t";}
                cout<<endl;

            }
            //setprecision used to print decimal even if number is round ex: 0.00 instead of 0
            cout<<setprecision(2)<<fixed<<percent1<<"%\t\t"<<percent2<<"%\t\t"<<unclaimed<<"%\t\t"<<endl;

            cout<<"player1"<<"\t\tplayer2"<<"\t\tunclaimed"<<endl;
            break;
        case 3:
            for(int j = 50 ; j>0; --j)
            {
                if(percent1>=j*2) { cout<< "|   |\t";}
                else{ cout<< "\t \t";}

                if(percent2>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent3>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(unclaimed>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}
                cout<<endl;

            }
            //setprecision used to print decimal even if number is round ex: 0.00 instead of 0
            cout<<setprecision(2)<<fixed<<percent1<<"%\t\t"<<percent2<<"%\t\t"<<percent3<<"%\t\t"<<unclaimed<<"%\t\t"<<endl;

            cout<<"player1"<<"\t\tplayer2"<<"\t\tplayer3"<<"\t\tunclaimed"<<endl;
            break;
        case 4:
            for(int j = 50 ; j>0; --j)
            {
                if(percent1>=j*2) { cout<< "|   |\t";}
                else{ cout<< "\t \t";}

                if(percent2>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent3>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent4>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(unclaimed>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}
                cout<<endl;

            }
            //setprecision used to print decimal even if number is round ex: 0.00 instead of 0
            cout<<setprecision(2)<<fixed<<percent1<<"%\t\t"<<percent2<<"%\t\t"<<percent3<<"%\t\t"<<percent4<<"%\t\t"<<unclaimed<<"%\t\t"<<endl;

            cout<<"player1"<<"\t\tplayer2"<<"\t\tplayer3"<<"\t\tplayer4"<<"\t\tunclaimed"<<endl;
            break;
        case 5: for(int j = 50 ; j>0; --j)
            {
                if(percent1>=j*2) { cout<< "|   |\t";}
                else{ cout<< "\t \t";}

                if(percent2>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent3>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent4>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent5>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(unclaimed>=j*2) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}
                cout<<endl;

            }
            //setprecision used to print decimal even if number is round ex: 0.00 instead of 0
            cout<<setprecision(2)<<fixed<<percent1<<"%\t\t"<<percent2<<"%\t\t"<<percent3<<"%\t\t"<<percent4<<"%\t\t"
                    <<percent5<<"%\t\t"<<unclaimed<<"%\t\t"<<endl;

            cout<<"player1"<<"\t\tplayer2"<<"\t\tplayer3"<<"\t\tplayer4"<<"\t\tplayer5"<<"\t\tunclaimed"<<endl;
            break;
    }
    cout<<"----------------------------------------------------------------------"<<endl;

}

//notify observer of owned regions and print graph
void GraphObserver::notifyRegionsOwned(int regionsOwned)
{
    Decorator::notifyRegionsOwned(regionsOwned);
    printGraph();
}

void HandObserver::notifyHand(string s1)
{
    Decorator::notifyHand(s1);
    //print player hands
    for(int j =0; j<playerhands.size();++j)
    {
        cout<<"Player "<<j+1<<"'s hand: "<<playerhands[j]<<endl;
    }
}

void CoinObserver::notifyCoins(int coins)
{
    Decorator::notifyCoins(coins);

    //print player coins
    for(int j =0; j<playerCoins.size();++j)
    {
        cout<<"Player "<<j+1<<" has "<<playerCoins[j]<<" coins"<<endl;
    }

}
