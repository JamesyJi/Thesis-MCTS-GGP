#pragma once

#include "game_types.h"

namespace Common
{

// A generic game piece
struct Piece
{
    Piece()
    : player(Player::NONE)
    {}
    
    Piece(Player player)
    : player(player)
    {}

    ~Piece(){}

    friend bool operator==(const Piece& lhs, const Piece& rhs)
    {
        return lhs.player == rhs.player;
    }

    friend bool operator!=(const Piece& lhs, const Piece& rhs)
    {
        return lhs.player != rhs.player;
    }

    Player player;
};

}
