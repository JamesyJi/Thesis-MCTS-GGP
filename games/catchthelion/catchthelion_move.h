#pragma once

#include <iostream>

namespace CatchTheLion
{

struct Step
{
    int row;
    int col;
};

const int NUM_ELEPHANT_DIRECTIONS = 4;
const Step ElephantDirections[NUM_ELEPHANT_DIRECTIONS] = 
{
    {-1, -1},
    {-1, 1},
    {1, 1},
    {1, -1}
};

const int NUM_GIRAFFE_DIRECTIONS = 4;
const Step GiraffeDirections[NUM_GIRAFFE_DIRECTIONS] =
{
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

const int NUM_LION_DIRECTIONS = 8;
const Step LionDirections[NUM_LION_DIRECTIONS] =
{
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1}
};

const int NUM_HEN_DIRECTIONS = 6;
// Cannot move diagonally backwards (NW and NE)
const Step HenDirectionsPlayer1[NUM_HEN_DIRECTIONS] =
{
    {-1, 0},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1}
};

// Cannot move diagonally backwards (SW and SE)
const Step HenDirectionsPlayer2[NUM_HEN_DIRECTIONS] =
{
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 0},
    {0, -1}
};


enum class MoveType
{
    MOVE,
    DROP
};

static std::ostream& operator<<(std::ostream& os, MoveType move)
{
    switch (move)
    {
        case MoveType::MOVE: return os << "MOVE";
        case MoveType::DROP: return os << "DROP";
    }
}

struct CatchTheLionMove
{
    CatchTheLionMove()
    {}

    // MOVE CAPTURE
    CatchTheLionMove(
        Common::Player player,
        Common::CatchTheLionPieceType pieceType,
        int prevRow,
        int prevCol,
        int row,
        int col,
        Common::CatchTheLionPieceType capturedPieceType
    ) : player(player)
    , pieceType(pieceType)
    , moveType(MoveType::MOVE)
    , prevRow(prevRow)
    , prevCol(prevCol)
    , row(row)
    , col(col)
    , capturedPieceType(capturedPieceType)
    {}

    // MOVE NO CAPTURE
    CatchTheLionMove(
        Common::Player player,
        Common::CatchTheLionPieceType pieceType,
        int prevRow,
        int prevCol,
        int row,
        int col
    ) : CatchTheLionMove(player, pieceType, prevRow, prevCol, row, col, Common::CatchTheLionPieceType::NONE)
    {}

    // DROP
    CatchTheLionMove(
        Common::Player player,
        Common::CatchTheLionPieceType pieceType,
        int row,
        int col
    ) : player(player)
    , pieceType(pieceType)
    , moveType(MoveType::DROP)
    , prevRow(-1)
    , prevCol(-1)
    , row(row)
    , col(col)
    , capturedPieceType(Common::CatchTheLionPieceType::NONE)
    {}

    Common::Player player = Common::Player::NONE;
    Common::CatchTheLionPieceType pieceType;
    MoveType moveType;
    int prevRow;
    int prevCol;
    int row;
    int col;

    // NONE if no capture
    Common::CatchTheLionPieceType capturedPieceType;

    friend bool operator==(const CatchTheLionMove& lhs, const CatchTheLionMove& rhs)
    {
        return lhs.player == rhs.player &&
            lhs.pieceType == rhs.pieceType &&
            lhs.moveType == rhs.moveType &&
            lhs.row == rhs.row &&
            lhs.col == rhs.col &&
            lhs.prevRow == rhs.prevRow &&
            lhs.prevCol == rhs.prevCol &&
            lhs.capturedPieceType == rhs.capturedPieceType;        
    }

    friend bool operator!=(const CatchTheLionMove& lhs, const CatchTheLionMove& rhs)
    {
        return !(lhs == rhs);
    }

    friend std::ostream& operator<<(std::ostream& os, const CatchTheLionMove& move)
    {
        if (move.player == Common::Player::NONE)
        {
            os << "NONE";
            return os;
        }

        // if (move.moveType == MoveType::DROP)
        // {
        //     os << move.player << " ";
        //     os << move.pieceType << " ";
        //     os << move.moveType << " ";
        //     os << move.row << " ";
        //     os << move.col << " ";
        // }

        os << move.player << " ";
        os << move.pieceType << " ";
        os << move.moveType << " ";
        os << move.prevRow << " ";
        os << move.prevCol << " ";
        os << move.row << " ";
        os << move.col << " ";
        os << move.capturedPieceType;
        
        return os;
    }
};

}