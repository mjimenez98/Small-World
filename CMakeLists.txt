cmake_minimum_required(VERSION 3.9)
project(Small-World)

set(CMAKE_CXX_STANDARD 11)

add_executable(Small-World
        Dice/Dice.cpp Dice/Dice.h
        FantasyRaceBanner/FantasyRaceBanner.cpp FantasyRaceBanner/FantasyRaceBanner.h
        GamePiece/GamePiece.cpp GamePiece/GamePiece.h
        GameTurn/GameTurn.cpp GameTurn/GameTurn.h
        LostTribeToken/LostTribeToken.cpp LostTribeToken/LostTribeToken.h
        Map/Map.cpp Map/Map.h Map/
        MatchingRaceToken/MatchingRaceToken.cpp MatchingRaceToken/MatchingRaceToken.h
        Player/Player.h Player/Player.cpp
        SpecialPowerBadge/SpecialPowerBadge.cpp SpecialPowerBadge/SpecialPowerBadge.h
        SummarySheet/SummarySheet.cpp SummarySheet/SummarySheet.h
        VictoryCoin/VictoryCoin.cpp VictoryCoin/VictoryCoin.h
        #Main/part1.cpp
        #Main/part2.cpp
        #Main/part3.cpp
        #Main/part4.cpp
        #Main/part5.cpp
        Main/part6.cpp
        #Main/part7.cpp
        )