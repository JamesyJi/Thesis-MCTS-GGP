#pragma once

#include "pieces.h"

#include "catchthelion_move.h"

namespace CatchTheLion
{

class CatchTheLionState
{

public:
    static const int ROWS = 4;
    static const int COLS = 3;
    static const int MAX_MOVES = 100;
    static const int MAX_DROPS = 8;

    CatchTheLionState()
    {
        mPosition[0][0] = CTLPiece(Common::Player::PLAYER1, CTLPieceType::GIRAFFE);
        mPosition[0][1] = CTLPiece(Common::Player::PLAYER1, CTLPieceType::LION);
        mPosition[0][2] = CTLPiece(Common::Player::PLAYER1, CTLPieceType::ELEPHANT);
        mPosition[1][1] = CTLPiece(Common::Player::PLAYER1, CTLPieceType::CHICK);

        mPosition[1][0] = CTLPiece();
        mPosition[1][2] = CTLPiece();
        mPosition[2][0] = CTLPiece();
        mPosition[2][2] = CTLPiece();

        mPosition[3][0] = CTLPiece(Common::Player::PLAYER2, CTLPieceType::ELEPHANT);
        mPosition[3][1] = CTLPiece(Common::Player::PLAYER2, CTLPieceType::LION);
        mPosition[3][2] = CTLPiece(Common::Player::PLAYER2, CTLPieceType::GIRAFFE);
        mPosition[2][1] = CTLPiece(Common::Player::PLAYER2, CTLPieceType::CHICK);
    }

    Common::Result EvaluateState(const CatchTheLionMove& lastMove);
    CatchTheLionMove GetRandomLegalMove(Common::Player player) const;
    int GetLegalMoves(Common::Player player, CatchTheLionMove legalMoves[MAX_MOVES]) const;
    CatchTheLionState MakeMove(const CatchTheLionMove&) const;
    void SimulateMove(const CatchTheLionMove&);
    void UndoMove(const CatchTheLionMove&);

private:
    Common::Piece mPosition[ROWS][COLS];

    Common::Piece mPlayer1Drops[3] = {0};
    Common::Piece mPlayer2Drops[3] = {0};
private:
    inline bool IsInBounds(int row, int col) const
    {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }

    inline int AddChickLegalMoves(Common::Player player, int destRow, int row, int col) const;
    inline int AddElephantLegalMoves(Common::Player player, int row, int col) const;
    inline int AddGiraffeLegalMoves(Common::Player player, int row, int col) const;
    inline int AddLionLegalMoves(Common::Player player, int row, int col) const;
    inline int AddHenLegalMoves(Common::Player player, int row, int col) const;
};

}