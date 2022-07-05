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
        std::cout << "finished accumulating\n";
    }

    void Log(const std::string& fileName) 
    {
        
        std::ofstream file("results/" + fileName, std::ofstream::trunc);
        
        file << "Player1 Win: " << mPlayer1Wins << "\n";
        file << "Player2 Win: " << mPlayer2Wins << "\n";
        file << "Draws: " << mDraws << "\n";
        file << "Total: " << mTotalGames << "\n";
        file.close();
    }

    void LogTerminals(const std::string& fileName)
    {
        std::ofstream file("stats/" + fileName, std::ofstream::trunc);
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
};

}