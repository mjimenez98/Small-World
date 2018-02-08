//
// Created by Miguel Jimenez on 2/6/18.
//

#include "GamePiece.h"

GamePiece::GamePiece() {

    type = nullptr;

}

GamePiece::GamePiece(string newType) {

    type = newType;

}

/* Sets up game pieces. The stock version of Small World has: 1 Dragon, 5 Encampments, 6 Fortresses, 2 Heroes, 9 Mountains,
 * 10 Troll Lairs and 2 Holes-in-the-ground */
GamePiece GamePiece::createGamePieces(int numOfDragons, int numOfEncampments, int numOfFortresses, int numOfHeroes,
                                      int numOfMountains, int numOfTrollLairs, int numOfHolesInTheGround) {

    GamePiece gamePieces[numOfDragons+numOfEncampments+numOfFortresses+numOfHeroes+numOfMountains+numOfTrollLairs+
            numOfHolesInTheGround];

    int index = 0;

    for(int i=0; i<numOfDragons; i++) {
        gamePieces[index++] = GamePiece("Dragon");
    }

    for(int i=0; i<numOfEncampments; i++) {
        gamePieces[index++] = GamePiece("Encampment");
    }

    for(int i=0; i<numOfFortresses; i++) {
        gamePieces[index++] = GamePiece("Fortress");
    }

    for(int i=0; i<numOfHeroes; i++) {
        gamePieces[index++] = GamePiece("Hero");
    }

    for(int i=0; i<numOfMountains; i++) {
        gamePieces[index++] = GamePiece("Mountain");
    }

    for(int i=0; i<numOfTrollLairs; i++) {
        gamePieces[index++] = GamePiece("Troll Lair");
    }

    for(int i=0; i<numOfHolesInTheGround; i++) {
        gamePieces[index++] = GamePiece("Hole-in-the-ground");
    }

    return *gamePieces;

}
