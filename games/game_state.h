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

    const int GetTurn() const
    {
        return mTurn;
    }

    const Common::Player GetPlayerTurn() const
    {
        return mPlayerTurn;
    }

    int (*(GetTerminals)())[13]
    {
        return mTerminals;
    }

    void FoundTerminal(int depth)
    {
        mTerminals[mTurn][depth]++;
    }


private:
    int mTurn = 1;
    Common::Result mResult;
    Common::Player mPlayerTurn = Common::Player::PLAYER1;

    // Terminal Logging mTerminal[4][8] = number of terminal results detected 8 moves on turn 4
    int mTerminals[200][13] = {};
};

}