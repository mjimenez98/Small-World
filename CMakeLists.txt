cmake_minimum_required(VERSION 3.9)
project(Small-World)

set(CMAKE_CXX_STANDARD 11)

add_executable(Small-World
        #OBJECTS
        Objects/Dice/Dice.cpp Objects/Dice/Dice.h
        Objects/FantasyRaceBanner/FantasyRaceBanner.cpp Objects/FantasyRaceBanner/FantasyRaceBanner.h
        Objects/GamePiece/GamePiece.cpp Objects/GamePiece/GamePiece.h
        Objects/GameTurn/GameTurn.cpp Objects/GameTurn/GameTurn.h
        Objects/LostTribeToken/LostTribeToken.cpp Objects/LostTribeToken/LostTribeToken.h
        Objects/Map/Map.cpp Objects/Map/Map.h Map/
        Objects/MatchingRaceToken/MatchingRaceToken.cpp Objects/MatchingRaceToken/MatchingRaceToken.h
        Objects/Player/PlayerBehavior.h
        Objects/Player/Player.h Objects/Player/Player.cpp
        Objects/SpecialPowerBadge/SpecialPowerBadge.cpp Objects/SpecialPowerBadge/SpecialPowerBadge.h
        Objects/SummarySheet/SummarySheet.cpp Objects/SummarySheet/SummarySheet.h
        Objects/VictoryCoin/VictoryCoin.cpp Objects/VictoryCoin/VictoryCoin.h
        #MAIN
        #Main/parts1_2.cpp
        Main/part3.cpp
        MainLoop/MainLoop.cpp MainLoop/MainLoop.h
        #PATTERNS
        Patterns/Observer/Observer.cpp Patterns/Observer/Observer.h
        Patterns/Strategy/Aggressive.cpp Patterns/Strategy/Aggressive.h
        Patterns/Strategy/Defensive.cpp Patterns/Strategy/Defensive.h
        Patterns/Strategy/Moderate.cpp Patterns/Strategy/Moderate.h
        Patterns/Strategy/Random.cpp Patterns/Strategy/Random.h
        )