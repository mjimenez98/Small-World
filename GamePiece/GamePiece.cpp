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

string GamePiece::getType() {

    return type;

}

// Helper method to print and demonstrate different Game Pieces
string printGamePieces(vector<GamePiece> gamePieces, vector<int> positions) {

    string demo;
    int previous = 0;

    for(int position : positions) {
        demo += "\n- " + to_string(position-previous) + " " + gamePieces[position-1].getType();
        previous = position;
    }
    demo += "\n";

    return demo;

}

// Prints a description of all the Game Pieces created
string GamePiece::demoGamePieces(vector<GamePiece> gamePieces) {

    if(gamePieces.empty()) {
        return "ERROR";
    }
    else {
        vector<int> positions;

        for(int i=1; i<gamePieces.size(); i++) {

            if(gamePieces[i].getType().compare(gamePieces[i-1].getType()) != 0) {
                positions.push_back(i);
            }

        }
        positions.push_back((int) gamePieces.size());

        return "Game Pieces:" + printGamePieces(gamePieces, positions);
    }

}

/* Sets up game pieces. The stock version of Small World has: 1 Dragon, 5 Encampments, 6 Fortresses, 2 Heroes, 9 Mountains,
 * 10 Troll Lairs and 2 Holes-in-the-ground */
vector<GamePiece> GamePiece::createGamePieces(int numOfDragons, int numOfEncampments, int numOfFortresses, int numOfHeroes,
                                      int numOfMountains, int numOfTrollLairs, int numOfHolesInTheGround) {

    vector<GamePiece> gamePieces;

    for(int i=0; i<numOfDragons; i++) {
        gamePieces.emplace_back(GamePiece("Dragon"));
    }

    for(int i=0; i<numOfEncampments; i++) {
        gamePieces.emplace_back(GamePiece("Encampment"));
    }

    for(int i=0; i<numOfFortresses; i++) {
        gamePieces.emplace_back(GamePiece("Fortress"));
    }

    for(int i=0; i<numOfHeroes; i++) {
        gamePieces.emplace_back(GamePiece("Hero"));
    }

    for(int i=0; i<numOfMountains; i++) {
        gamePieces.emplace_back(GamePiece("Mountain"));
    }

    for(int i=0; i<numOfTrollLairs; i++) {
        gamePieces.emplace_back(GamePiece("Troll Lair"));
    }

    for(int i=0; i<numOfHolesInTheGround; i++) {
        gamePieces.emplace_back(GamePiece("Hole-in-the-ground"));
    }

    return gamePieces;

}
