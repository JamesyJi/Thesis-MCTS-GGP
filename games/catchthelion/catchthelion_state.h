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
        mPosition[0][0] = Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::GIRAFFE);
        mPosition[0][1] = Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::LION);
        mPosition[0][2] = Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::ELEPHANT);
        mPosition[1][1] = Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::CHICK);

        mPosition[1][0] = Common::CatchTheLionPiece();
        mPosition[1][2] = Common::CatchTheLionPiece();
        mPosition[2][0] = Common::CatchTheLionPiece();
        mPosition[2][2] = Common::CatchTheLionPiece();

        mPosition[3][0] = Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::ELEPHANT);
        mPosition[3][1] = Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::LION);
        mPosition[3][2] = Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::GIRAFFE);
        mPosition[2][1] = Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::CHICK);
    }

    Common::Result EvaluateState(const CatchTheLionMove& lastMove) const;
    CatchTheLionMove GetRandomLegalMove(Common::Player player) const;
    int GetLegalMoves(Common::Player player, CatchTheLionMove legalMoves[MAX_MOVES]) const;
    CatchTheLionState MakeMove(const CatchTheLionMove&) const;
    void SimulateMove(const CatchTheLionMove&);
    void UndoMove(const CatchTheLionMove&);

    friend bool operator==(const CatchTheLionState& lhs, const CatchTheLionState& rhs);
    friend std::ostream& operator<<(std::ostream& os, const CatchTheLionState& state);

private:
    Common::CatchTheLionPiece mPosition[ROWS][COLS];

    int mPlayer1Drops[3] = {0};
    int mPlayer2Drops[3] = {0};
private:
    inline bool IsInBounds(int row, int col) const
    {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }
    inline void IncrDrop(Common::Player player, Common::CatchTheLionPieceType pieceType)
    {
        if (pieceType == Common::CatchTheLionPieceType::HEN) pieceType = Common::CatchTheLionPieceType::CHICK;
        switch (player)
        {
        case Common::Player::PLAYER1:
            ++mPlayer1Drops[pieceType];
            return;
        case Common::Player::PLAYER2:
            ++mPlayer2Drops[pieceType];
            return;
        default:
            throw std::runtime_error("Cannot IncrDrop with no player");
        }
    }
    inline void DecrDrop(Common::Player player, Common::CatchTheLionPieceType pieceType)
    {
        if (pieceType == Common::CatchTheLionPieceType::HEN) pieceType = Common::CatchTheLionPieceType::CHICK;
        switch (player)
        {
        case Common::Player::PLAYER1:
            --mPlayer1Drops[pieceType];
            return;
        case Common::Player::PLAYER2:
            --mPlayer2Drops[pieceType];
            return;
        default:
            throw std::runtime_error("Cannot DecrDrop with no player");
        }
    }

    inline int AddChickLegalMoves(Common::Player player, int destRow, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddElephantLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddGiraffeLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddLionLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddHenLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddLegalDrops(Common::Player player, int const (&drops)[3], int row, int col, int found, CatchTheLionMove legalMoves[MAX_MOVES]) const;
};

}