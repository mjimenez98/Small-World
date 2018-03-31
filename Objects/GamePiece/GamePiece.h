//
// Created by Miguel Jimenez on 2/6/18.
//

#ifndef SMALL_WORLD_GAMEPIECES_H
#define SMALL_WORLD_GAMEPIECES_H

#include <string>
#include <vector>

using namespace std;

// Number of pieces
const int DRAGONS = 1;
const int ENCAMPMENTS = 5;
const int FORTRESSES = 6;
const int HEROES = 2;
const int MOUNTAINS = 9;
const int TROLLLAIRS = 10;
const int HOLESINTHEGROUND = 2;

class GamePiece {

public:
    // Constructors
    GamePiece();
    explicit GamePiece(string newType);

    // Getters
    string getType();

    // Other functions
    static string demoGamePieces(vector<GamePiece>& gamePieces);
    static vector<GamePiece>* createGamePieces(int numOfDragons, int numOfEncampments, int numOfFortresses, int numOfHeroes,
                                      int numOfMountains, int numOfTrollLairs, int numOfHolesInTheGround);

private:
    string type;

};

#endif //SMALL_WORLD_GAMEPIECES_H
