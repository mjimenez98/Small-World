cmake_minimum_required(VERSION 3.9)
project(Small-World)

set(CMAKE_CXX_STANDARD 11)

add_executable(Small-World
        GamePiece/GamePiece.cpp GamePiece/GamePiece.h
        LostTribeToken/LostTribeToken.cpp LostTribeToken/LostTribeToken.h
        MatchingRaceToken/MatchingRaceToken.cpp MatchingRaceToken/MatchingRaceToken.h
        Player/Player.h Player/Player.cpp #Player/main.cpp
        SummarySheet/SummarySheet.cpp SummarySheet/SummarySheet.h SummarySheet/main.cpp
        VictoryCoin/VictoryCoin.cpp VictoryCoin/VictoryCoin.h SpecialPowerBadge/SpecialPowerBadge.cpp SpecialPowerBadge/SpecialPowerBadge.h)