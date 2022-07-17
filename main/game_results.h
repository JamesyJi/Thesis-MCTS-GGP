#pragma once

#include <iostream>
#include <fstream>
#include <map>

#include "game_types.h"
#include "game_state.h"

namespace Main
{

class GameResults
{
public:
    GameResults(){};
    
    ~GameResults(){};

    void UpdateResult(Common::Result result)
    {
        if (result == Common::Result::DRAW) {
            mDraws++;
        } else if (result == Common::Result::PLAYER1_WIN) {
            mPlayer1Wins++;
        } else if (result == Common::Result::PLAYER2_WIN) {
            mPlayer2Wins++;
        }

        mTotalGames++;
    }

    // Called after update result
    void Accumulate(Games::GameState& gameState)
    {
        std::cout << "accumulating\n";
        int (*terminals)[13] = gameState.GetTerminals();
        for (int turn = 1; turn < gameState.GetTurn(); ++turn)
        {
            for (int depth = 1; depth <= 12; ++depth)
            {
                mTerminals[turn][depth] = terminals[turn][depth];
            }
        }

        int *simulations = gameState.GetSimulations();

        mAvgSimsP1 = (mAvgSimsP1 * (mTotalGames - 1) + simulations[1]) / mTotalGames;
        mAvgSimsP2 = (mAvgSimsP2 * (mTotalGames - 1) + simulations[2]) / mTotalGames;

        std::cout << "finished accumulating mAvgSimsP1 and P2 are " << mAvgSimsP1 << " " << mAvgSimsP2 << "\n";
    }

    void Log(const std::string& fileName) 
    {
        
        std::ofstream file(fileName, std::ofstream::trunc);
        
        file << "Player1 Win: " << mPlayer1Wins << "\n";
        file << "Player2 Win: " << mPlayer2Wins << "\n";
        file << "Draws: " << mDraws << "\n";
        file << "Total: " << mTotalGames << "\n";
        file << "AvgSimulationsPlayer1: " << mAvgSimsP1 << "\n";
        file << "AvgSimulationsPlayer2: " << mAvgSimsP2 << "\n";
        file.close();
    }

    void LogTerminals(const std::string& fileName)
    {
        std::ofstream file(fileName, std::ofstream::trunc);
        file << "TURN,1,2,3,4,5,6,7,8,9,10,11,12,\n";
        for (auto& it : mTerminals)
        {
            file << it.first << ",";
            for (auto& it2 : it.second)
            {
                file << it2.second << ",";
            }
            file << "\n";
        }

        file.close();
    }

private:
    int mPlayer1Wins = 0;
    int mPlayer2Wins = 0;
    int mDraws = 0;
    int mTotalGames = 0;

    // Number of terminal games turn : {depth : count }
    std::map<int, std::map<int, int>> mTerminals = {};
    
    // Average number of simulations for 1st move respectively
    double mAvgSimsP1 = 0;
    double mAvgSimsP2 = 0;
};

}