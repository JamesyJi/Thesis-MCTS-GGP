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

private:
    int mTurn = 1;
    Common::Player mPlayerTurn = Common::Player::PLAYER1;
};

}