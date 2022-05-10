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

    Player player;
};

}
