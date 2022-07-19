#pragma once

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
    {1, 1}
    {1, -1},
};

const int NUM_GIRAFFE_DIRECTIONS = 4;
const Step GiraffeDirections[NUM_GIRAFFE_DIRECTIONS] =
{
    {-1, 0},
    {0, 1},
    {1, 0},
    {-1, 0}
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

struct CTLMove
{
    // MOVE
    CTLMove(
        Common::Player player,
        CTLPieceType pieceType,
        int prevRow,
        int prevCol,
        int row,
        int col,
        CTLPieceType capturedPieceType
    ) : player(player)
    , piece(pieceType)
    , moveType(MoveType::MOVE)
    , prevRow(prevRow)
    , prevCol(prevCol)
    , row(row)
    , col(col)
    , capturedPiece(capturedPieceType)
    {}

    // DROP
    CTLMove(
        Common::Player player,
        CTLPieceType pieceType,
        int row,
        int col,
    ) : player(player)
    , pieceType(pieceType)
    , moveType(MoveType::DROP)
    , prevRow(-1)
    , prevCol(-1)
    , row(row)
    , col(col)
    {}

    Common::Player player;
    CTLPieceType pieceType;
    MoveType moveType;
    int prevRow;
    int prevCol;
    int row;
    int col;

    // NONE if no capture
    CTLPieceType capturedPieceType = CTLPieceType::NONE;
};

}