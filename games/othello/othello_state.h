#pragma once

#include "pieces.h"

#include "othello_move.h"

namespace Othello
{

class OthelloState
{

public:
    static const int ROWS = 8;
    static const int COLS = 8;
    static const int MAX_PIECES = ROWS * COLS;
    static const int MAX_MOVES = CaptureInfo::MAX_CAPTURES;
    
    OthelloState()
    : mSkippedTurns(0)
    , mNumPlayer1Pieces(2)
    , mNumPlayer2Pieces(2)
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = Common::Piece();

        mPosition[3][3] = Common::Piece(Common::Player::PLAYER1);
        mPosition[4][4] = Common::Piece(Common::Player::PLAYER1);
        mPosition[3][4] = Common::Piece(Common::Player::PLAYER2);
        mPosition[4][3] = Common::Piece(Common::Player::PLAYER2);
    }

    OthelloState(Common::Piece position[ROWS][COLS], int skippedTurns, int numPlayer1Pieces, int numPlayer2Pieces)
    : mSkippedTurns(skippedTurns)
    , mNumPlayer1Pieces(numPlayer1Pieces)
    , mNumPlayer2Pieces(numPlayer2Pieces)
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = position[row][col];
    }

    OthelloState(const Common::Piece position[ROWS][COLS], int skippedTurns, int numPlayer1Pieces, int numPlayer2Pieces)
    : mSkippedTurns(skippedTurns)
    , mNumPlayer1Pieces(numPlayer1Pieces)
    , mNumPlayer2Pieces(numPlayer2Pieces)
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = position[row][col];
    }

    // OthelloState(Common::Piece position[ROWS][COLS])
    // : OthelloState(position)
    // {}

    // OthelloState(const Common::Piece position[ROWS][COLS])
    // : OthelloState(position, 0, 4)
    // {}

    OthelloState(const OthelloState& other)
    : OthelloState(other.mPosition, other.mSkippedTurns, other.mNumPlayer1Pieces, other.mNumPlayer2Pieces)
    {}

    OthelloState& operator=(const OthelloState& other)
    {
        if (this != &other)
        {
            for (int row = 0; row < ROWS; ++row)
                for (int col = 0; col < COLS; ++col)
                    mPosition[row][col] = other.mPosition[row][col];

            mSkippedTurns = other.mSkippedTurns;
            mNumPlayer1Pieces = other.mNumPlayer1Pieces;
            mNumPlayer2Pieces = other.mNumPlayer2Pieces;
        }
        return *this;
    }

    Common::Result EvaluateState(const OthelloMove& lastMove);
    OthelloMove GetRandomLegalMove(Common::Player player) const;
    int GetNumLegalMoves(Common::Player player) const;
    int GetLegalMoves(Common::Player player, OthelloMove legalMoves[MAX_MOVES]) const;
    OthelloState MakeMove(const OthelloMove&) const;
    void SimulateMove(const OthelloMove&);
    void UndoMove(const OthelloMove&);

    friend bool operator==(const OthelloState& lhs, const OthelloState& rhs);
    friend std::ostream& operator<<(std::ostream& os, const OthelloState& state);

    inline void SkipTurn()
    {
        ++mSkippedTurns;
    }

    inline void UnSkipTurn()
    {
        --mSkippedTurns;
    }
    
    inline void ResetSkippedTurns()
    {
        mSkippedTurns = 0;
    }
    
    inline int GetSkippedTurns() const
    {
        return mSkippedTurns;
    }

private:
    Common::Piece mPosition[ROWS][COLS];

    // Increment each time a player skips a turn
    // 2 ==> both players have skipped turns. Determine the winner
    int mSkippedTurns;
    int mNumPlayer1Pieces;
    int mNumPlayer2Pieces;

private:
    inline Common::Result DetermineWinner() const;

    inline bool IsAdjacentToOtherPlayer(Common::Player otherPlayer, int row, int col, Direction *opponentDirection) const;

    inline bool FindUpdateCaptureDirections(Common::Player player, int row, int col, Direction dir, OthelloMove& move) const;

    inline bool IsInBounds(int row, int col) const
    {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }

    inline int FlipCapturedPieces(Common::Player player, int row, int col, const CaptureInfo& captureInfo);

    inline int UnFlipCapturedPieces(Common::Player player, int row, int col, const CaptureInfo& captureInfo);

    inline void IncrementPieces(Common::Player player, int numPieces)
    {
        switch (player)
        {
            case Common::Player::PLAYER1:
                mNumPlayer1Pieces += numPieces;
                break;
            case Common::Player::PLAYER2:
                mNumPlayer2Pieces += numPieces;
                break;
            default:
                throw "Incrementing Pieces for player that is not player 1 or 2";
        }
    }

    inline void DecrementPieces(Common::Player player, int numPieces)
    {
        switch (player)
        {
            case Common::Player::PLAYER1:
                mNumPlayer1Pieces -= numPieces;
                break;
            case Common::Player::PLAYER2:
                mNumPlayer2Pieces -= numPieces;
                break;
            default:
                throw "Decrementing Pieces for player that is not player 1 or 2";
        }
    }
};

}