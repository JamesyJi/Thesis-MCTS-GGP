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

    ~Piece() {}

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
enum CatchTheLionPieceType
{
    CHICK,
    ELEPHANT,
    GIRAFFE,
    LION,
    HEN,
    NONE
};

static std::ostream& operator<<(std::ostream& os, const CatchTheLionPieceType& pieceType)
{
    switch (pieceType)
    {
    case CatchTheLionPieceType::CHICK: return os << "C";
    case CatchTheLionPieceType::ELEPHANT: return os << "E";
    case CatchTheLionPieceType::GIRAFFE: return os << "G";
    case CatchTheLionPieceType::LION: return os << "L";
    case CatchTheLionPieceType::HEN: return os << "H";
    case CatchTheLionPieceType::NONE: return os << "N";
    }
}

struct CatchTheLionPiece: public Piece
{
    CatchTheLionPiece()
        : Piece()
    {}

    CatchTheLionPiece(
        Player player,
        CatchTheLionPieceType pieceType)
        : Piece(player)
        , pieceType(pieceType)
    {}

    CatchTheLionPieceType pieceType = CatchTheLionPieceType::NONE;

    friend std::ostream& operator<<(std::ostream& os, const CatchTheLionPiece& piece)
    {
        switch (piece.pieceType)
        {
        case CatchTheLionPieceType::CHICK:
            os << "C";
            break;
        case CatchTheLionPieceType::ELEPHANT:
            os << "E";
            break;
        case CatchTheLionPieceType::GIRAFFE:
            os << "G";
            break;
        case CatchTheLionPieceType::LION:
            os << "L";
            break;
        case CatchTheLionPieceType::HEN:
            os << "H";
            break;
        case CatchTheLionPieceType::NONE:
            os << "N";
            break;
        }

        return os;
    }
};

}
