#pragma once

#include "pieces.h"

#include "catchthelion_move.h"

#include <vector>

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
        // mPosition[0][0] = Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::LION);
        // mPosition[0][1] = Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::ELEPHANT);
        // mPosition[0][2] = Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::CHICK);
        
        // mPosition[1][0] = Common::CatchTheLionPiece();
        // mPosition[1][1] = Common::CatchTheLionPiece(Common::Player::PLAYER1, Common::CatchTheLionPieceType::CHICK);
        // mPosition[1][2] = Common::CatchTheLionPiece();

        // mPosition[2][0] = Common::CatchTheLionPiece();
        // mPosition[2][1] = Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::ELEPHANT);
        // mPosition[2][2] = Common::CatchTheLionPiece(Common::Player::PLAYER2, Common::CatchTheLionPieceType::LION);

        // mPosition[3][0] = Common::CatchTheLionPiece();
        // mPosition[3][1] = Common::CatchTheLionPiece();
        // mPosition[3][2] = Common::CatchTheLionPiece();
        
        // mPlayer2Drops[2] = 2;
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

    CatchTheLionState(const Common::CatchTheLionPiece position[ROWS][COLS])
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = position[row][col];
    }

    CatchTheLionState(
        const Common::CatchTheLionPiece position[ROWS][COLS], 
        std::vector<CatchTheLionMove>& moveHistory
    ) : mMoveHistory(moveHistory)
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = position[row][col];
    }

    CatchTheLionState(
        const Common::CatchTheLionPiece position[ROWS][COLS],
        std::initializer_list<int> player1Drops,
        std::initializer_list<int> player2Drops
    ) : CatchTheLionState(position)
    {
        std::copy(player1Drops.begin(), player1Drops.end(), mPlayer1Drops);
        std::copy(player2Drops.begin(), player2Drops.end(), mPlayer2Drops);
    }

    CatchTheLionState(
        const Common::CatchTheLionPiece position[ROWS][COLS],
        std::initializer_list<int> player1Drops,
        std::initializer_list<int> player2Drops,
        std::vector<CatchTheLionMove>& moveHistory
    ) : CatchTheLionState(position, moveHistory)
    {
        std::copy(player1Drops.begin(), player1Drops.end(), mPlayer1Drops);
        std::copy(player2Drops.begin(), player2Drops.end(), mPlayer2Drops);
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

    // NOTE: Tracking the history of all moves is inefficient but I see no way
    // around it as we need to be able to UndoMoves whilst retaining the correct
    // game history.
    std::vector<CatchTheLionMove> mMoveHistory;

private:
    inline bool IsInBounds(int row, int col) const
    {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }
    inline void IncrDrop(Common::Player player, Common::CatchTheLionPieceType pieceType)
    {
        switch (pieceType)
        {
            case Common::CatchTheLionPieceType::LION:
                return;
            case Common::CatchTheLionPieceType::HEN:
                pieceType = Common::CatchTheLionPieceType::CHICK;
                break;
            case Common::CatchTheLionPieceType::NONE:
                return;
            default:
                break;
        }

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
        switch (pieceType)
        {
            case Common::CatchTheLionPieceType::LION:
                return;
            case Common::CatchTheLionPieceType::HEN:
                pieceType = Common::CatchTheLionPieceType::CHICK;
                break;
            case Common::CatchTheLionPieceType::NONE:
                return;
            default:
                break;
        }

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
    inline bool DrawByRepetition() const
    {
        if (mMoveHistory.size() < 12) return false;

        // The moves must have been:
        // A B C D A B C D A B C D
        // where A and C were made one player and B and D were made by another player

        int const& size = mMoveHistory.size();
        
        return mMoveHistory[size - 1] == mMoveHistory[size - 5] && mMoveHistory[size - 5] == mMoveHistory[size - 9] && // Compare D
            mMoveHistory[size - 2] == mMoveHistory[size - 6] && mMoveHistory[size - 6] == mMoveHistory[size - 10] && // Compare C
            mMoveHistory[size - 3] == mMoveHistory[size - 7] && mMoveHistory[size - 7] == mMoveHistory[size - 11] && // Compare B
            mMoveHistory[size - 4] == mMoveHistory[size - 8] && mMoveHistory[size - 8] == mMoveHistory[size - 12]; // Compare A
    }

    inline int AddChickLegalMoves(Common::Player player, int endRow, int row, int col, int forwardStep, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddElephantLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddGiraffeLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddLionLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddHenLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const;
    inline int AddLegalMoveForPiece(Common::Player player, Common::CatchTheLionPieceType pieceType, int row, int col, int destRow, int destCol, int found, CatchTheLionMove legalMoves[MAX_MOVES]) const;
    inline int AddLegalDrops(Common::Player player, int const (&drops)[3], int row, int col, int found, CatchTheLionMove legalMoves[MAX_MOVES]) const;
    inline bool HasMoveToSquare(Common::Player player, int row, int col) const;
};

}