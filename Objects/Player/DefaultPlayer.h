//
// Created by Miguel Jimenez on 3/30/18.
//

#ifndef SMALL_WORLD_DEFAULTPLAYER_H
#define SMALL_WORLD_DEFAULTPLAYER_H

#include "../FantasyRaceBanner/FantasyRaceBanner.h"

class DefaultPlayer {

public:
    virtual void picks_race(vector<FantasyRaceBanner>& availableBanners) = 0;
    virtual void conquer() = 0;
    virtual void scores() = 0;

};


#endif //SMALL_WORLD_DEFAULTPLAYER_H
