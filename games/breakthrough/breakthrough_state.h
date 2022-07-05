#pragma once

#include "pieces.h"
#include "breakthrough_move.h"

namespace Breakthrough
{

class BreakthroughState
{

public:
    static const int ROWS = 6;
    static const int COLS = 6;
    static const int STARTING_PIECES = 12;
    static const int MAX_MOVES = STARTING_PIECES * 3;

    BreakthroughState()
    {
        // PLAYER 1
        for (int row = 0; row < 2; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = Common::Piece(Common::Player::PLAYER1);
        
        for (int row = 2; row < ROWS - 2; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = Common::Piece();

        // PLAYER 2
        for (int row = ROWS - 2; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = Common::Piece(Common::Player::PLAYER2);
        }

    BreakthroughState(const Common::Piece position[ROWS][COLS])
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = position[row][col];
    }

    BreakthroughState(const BreakthroughState& other)
    : BreakthroughState(other.mPosition)
    {
        mPlayer1RemainingPieces = other.mPlayer1RemainingPieces;
        mPlayer2RemainingPieces = other.mPlayer2RemainingPieces;
    }

    Common::Result EvaluateState(const BreakthroughMove& move);
    int GetLegalMoves(Common::Player player, BreakthroughMove[MAX_MOVES]) const;
    BreakthroughState MakeMove(const BreakthroughMove&) const;
    void SimulateMove(const BreakthroughMove&);
    void UndoMove(const BreakthroughMove&);

    friend bool operator==(const BreakthroughState& lhs, const BreakthroughState& rhs);
    friend std::ostream& operator<<(std::ostream& os, const BreakthroughState& state);

    void DecrementPlayer1RemainingPieces()
    {
        --mPlayer1RemainingPieces;
    }

    void DecrementPlayer2RemainingPieces()
    {
        --mPlayer2RemainingPieces;
    }

    bool IsInBounds(int row, int col) const
    {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }

private:
    Common::Piece mPosition[ROWS][COLS];

    int mPlayer1RemainingPieces = STARTING_PIECES;
    int mPlayer2RemainingPieces = STARTING_PIECES;
};

}
