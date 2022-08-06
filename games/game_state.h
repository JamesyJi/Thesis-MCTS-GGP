#pragma once

#include "game_types.h"

namespace Games
{

class GameState
{
public:
    GameState(){};

    ~GameState(){};

    void NextTurn()
    {
        ++mTurn;
        mPlayerTurn = Common::GetOtherPlayer(mPlayerTurn);
    }

    int GetTurn() const
    {
        return mTurn;
    }

    Common::Player GetPlayerTurn() const
    {
        return mPlayerTurn;
    }

    int (*(GetTerminals)())[11]
    {
        return mTerminals;
    }

    void FoundTerminal(int depth)
    {
        mTerminals[mTurn][depth]++;
    }

    inline void RunningSimulation()
    {
        ++mSimulations[mTurn];
    }

    int *GetSimulations()
    {
        return mSimulations;
    }


private:
    int mTurn = 1;
    Common::Player mPlayerTurn = Common::Player::PLAYER1;

    // Terminal Logging mTerminal[4][8] = number of terminal results detected 8 moves on turn 4
    int mTerminals[300][11] = {0};

    // Simulation count logging mSimulations[4] = number of simulations on turn 4
    int mSimulations[300] = {0};
};

}