//
// Created by Jean-Loup on 2018-03-20.
//

#include "Observer.h"
#include <iostream>
#include <iomanip>

//player who's turn it is currently
int Observer::playerNumber;
//total number of player's playing
int Observer::numberOfPlayers;
int Observer::numberOfRegions;
//number of regions owned y each player;
int Observer::regions1;
int Observer::regions2;
int Observer::regions3;
int Observer::regions4;
int Observer::regions5;

//notify Observer and print player's current action
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

//notify and print graph when the Observer when a player's region number changes
void Observer::notifyRegionsOwned(int regionsOwned)
{
    switch(playerNumber)
    {
        case 1: regions1 = regionsOwned;printGraph();break;
        case 2: regions2 = regionsOwned;printGraph();break;
        case 3: regions3 = regionsOwned;printGraph();break;
        case 4: regions4 = regionsOwned;printGraph();break;
        case 5: regions5 = regionsOwned;printGraph();break;
    }
}

//the graph goes in increments of 5%, therefore only values above 5% will show up
void Observer::printGraph()
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
        case 2: for(int j = 20 ; j>0; --j)
            {
               if(percent1>=j*5) { cout<< "|   |\t";}
               else{ cout<< "\t \t";}

                if(percent2>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(unclaimed>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}
                cout<<endl;

            }
            //setprecision used to print decimal even if number is round ex: 0.00 instead of 0
            cout<<setprecision(2)<<fixed<<percent1<<"%\t\t"<<percent2<<"%\t\t"<<unclaimed<<"%\t\t"<<endl;

            cout<<"player1"<<"\t\tplayer2"<<"\t\tunclaimed"<<endl;
            break;
        case 3:
            for(int j = 20 ; j>0; --j)
            {
                if(percent1>=j*5) { cout<< "|   |\t";}
                else{ cout<< "\t \t";}

                if(percent2>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent3>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(unclaimed>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}
                cout<<endl;

            }
            //setprecision used to print decimal even if number is round ex: 0.00 instead of 0
            cout<<setprecision(2)<<fixed<<percent1<<"%\t\t"<<percent2<<"%\t\t"<<percent3<<"%\t\t"<<unclaimed<<"%\t\t"<<endl;

            cout<<"player1"<<"\t\tplayer2"<<"\t\tplayer3"<<"\t\tunclaimed"<<endl;
            break;
        case 4:
            for(int j = 20 ; j>0; --j)
            {
                if(percent1>=j*5) { cout<< "|   |\t";}
                else{ cout<< "\t \t";}

                if(percent2>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent3>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent4>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(unclaimed>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}
                cout<<endl;

            }
            //setprecision used to print decimal even if number is round ex: 0.00 instead of 0
            cout<<setprecision(2)<<fixed<<percent1<<"%\t\t"<<percent2<<"%\t\t"<<percent3<<"%\t\t"<<percent4<<"%\t\t"<<unclaimed<<"%\t\t"<<endl;

            cout<<"player1"<<"\t\tplayer2"<<"\t\tplayer3"<<"\t\tplayer4"<<"\t\tunclaimed"<<endl;
            break;
        case 5: for(int j = 20 ; j>0; --j)
            {
                if(percent1>=j*5) { cout<< "|   |\t";}
                else{ cout<< "\t \t";}

                if(percent2>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent3>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent4>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(percent5>=j*5) { cout<< "\t|   |\t";}
                else{ cout<< "\t \t\t";}

                if(unclaimed>=j*5) { cout<< "\t|   |\t";}
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
