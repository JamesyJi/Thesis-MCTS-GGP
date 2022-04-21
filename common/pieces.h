#ifndef COMMON_PIECES_H_
#define COMMON_PIECES_H_

#include <game_types.h>

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


#endif