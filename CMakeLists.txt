cmake_minimum_required(VERSION 3.9)
project(Small-World)

set(CMAKE_CXX_STANDARD 11)

add_executable(Small-World
        Dice/Dice.cpp Dice/Dice.h #Dice/main.cpp
        FantasyRaceBanner/FantasyRaceBanner.cpp FantasyRaceBanner/FantasyRaceBanner.h
        GamePiece/GamePiece.cpp GamePiece/GamePiece.h
        LostTribeToken/LostTribeToken.cpp LostTribeToken/LostTribeToken.h
        Map/Map.cpp Map/Map.h Map/ Map/main.cpp
        MatchingRaceToken/MatchingRaceToken.cpp MatchingRaceToken/MatchingRaceToken.h
        Player/Player.h Player/Player.cpp #Player/main.cpp
        SpecialPowerBadge/SpecialPowerBadge.cpp SpecialPowerBadge/SpecialPowerBadge.h
        SummarySheet/SummarySheet.cpp SummarySheet/SummarySheet.h #SummarySheet/main.cpp
        VictoryCoin/VictoryCoin.cpp VictoryCoin/VictoryCoin.h)