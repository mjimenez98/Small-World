//
// Created by Miguel Jimenez on 5/7/18.
//

#include "GraphObserver.h"

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
            cout << setprecision(2) << fixed << percent1 << "%\t\t" << percent2 << "%\t\t" << percent3 << "%\t\t" << percent4 << "%\t\t"
                << percent5 << "%\t\t" << unclaimed << "%\t\t" << endl;

            cout << "player1" << "\t\tplayer2" << "\t\tplayer3" << "\t\tplayer4" << "\t\tplayer5" << "\t\tunclaimed" << endl;
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
