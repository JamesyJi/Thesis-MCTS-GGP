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

// Pieces in catch the lion
// Do not change order for the first 3 pieces. 
// They are used for the player drops
enum class CTLPieceType
{
    CHICK,
    ELEPHANT,
    GIRAFFE,
    LION,
    HEN,
    NONE
};

struct CTLPiece : public Piece
{
    CTLPiece()
    : Piece()
    {}

    CTLPiece(
        Player player,
        CTLPieceType pieceType)
    : Piece(player)
    , pieceType(pieceType)
    {}
    
    CTLPieceType pieceType = CTLPieceType::NONE;
};

}
