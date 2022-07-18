#pragma once

namespace CatchTheLion
{

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
        CTLPieceType piece,
        int prevRow,
        int prevCol,
        int row,
        int col,
        CTLPieceType capturedPiece
    ) : player(player)
    , piece(piece)
    , moveType(MoveType::MOVE)
    , prevRow(prevRow)
    , prevCol(prevCol)
    , row(row)
    , col(col)
    , capturedPiece(capturedPiece)
    {}

    // DROP
    CTLMove(
        Common::Player player,
        CTLPieceType piece,
        int row,
        int col,
    ) : player(player)
    , pieceType(piece)
    , moveType(MoveType::DROP)
    , prevRow(-1)
    , prevCol(-1)
    , row(row)
    , col(col)
    {}

    Common::Player player;
    CTLPieceType piece;
    MoveType moveType;
    int prevRow;
    int prevCol;
    int row;
    int col;

    // NONE if no capture
    CTLPieceType capturedPiece = CTLPieceType::NONE;
};

}