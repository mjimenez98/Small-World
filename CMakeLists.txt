cmake_minimum_required(VERSION 3.9)
project(Small-World)

set(CMAKE_CXX_STANDARD 11)

add_executable(Small-World
        Player/main.cpp Player/Player.h Player/Player.cpp
        MatchingRaceToken/MatchingRaceToken.cpp MatchingRaceToken/MatchingRaceToken.h
        SpecialPowerBadge/SpecialPowerBadge.cpp SpecialPowerBadge/SpecialPowerBadge.h
        VictoryCoin/VictoryCoin.cpp VictoryCoin/VictoryCoin.h
        LostTribeToken/LostTribeToken.cpp LostTribeToken/LostTribeToken.h
        SummarySheet/SummarySheet.cpp SummarySheet/SummarySheet.h GamePiece/GamePiece.cpp GamePiece/GamePiece.h SummarySheet/main.cpp)