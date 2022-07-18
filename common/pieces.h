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
enum class CTLPieceType
{
    NONE,
    CHICK,
    ELEPHANT,
    GIRAFFE,
    HEN,
    LION
};

struct CTLPiece : public Piece
{
    CTLPiece()
    : Piece()
    {}

    CTLPiece(
        Player player
        CTLPiece pieceType)
    : Piece(player)
    , pieceType(pieceType)
    {}
    
    CTLPieceType pieceType;
};

}
