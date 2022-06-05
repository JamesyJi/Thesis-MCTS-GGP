#pragma once

#include <iostream>
#include <fstream>

#include "game_types.h"

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

    void Log(const std::string& fileName) {
        
        std::ofstream file("results/" + fileName, std::ofstream::trunc);
        
        file << "Player1 Win: " << mPlayer1Wins << "\n";
        file << "Player2 Win: " << mPlayer2Wins << "\n";
        file << "Draws: " << mDraws << "\n";
        file << "Total: " << mTotalGames << "\n";
        
        file.close();
    }
    
private:
    int mPlayer1Wins = 0;
    int mPlayer2Wins = 0;
    int mDraws = 0;
    int mTotalGames = 0;
};

}