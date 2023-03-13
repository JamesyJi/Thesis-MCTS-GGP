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
    : mPlayer1RemainingPieces(STARTING_PIECES)
    , mPlayer2RemainingPieces(STARTING_PIECES)
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

    BreakthroughState(
        const Common::Piece position[ROWS][COLS],
        int player1RemainingPieces,
        int player2RemainingPieces
    ) 
    : mPlayer1RemainingPieces(player1RemainingPieces)
    , mPlayer2RemainingPieces(player2RemainingPieces)
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = position[row][col];
    }

    BreakthroughState(const Common::Piece position[ROWS][COLS])
    : BreakthroughState(position, STARTING_PIECES, STARTING_PIECES)
    {}

    BreakthroughState(const BreakthroughState& other)
    : BreakthroughState(other.mPosition, other.mPlayer1RemainingPieces, other.mPlayer2RemainingPieces)
    {}

    Common::Result EvaluateState(const BreakthroughMove& lastMove);    
    BreakthroughMove GetRandomLegalMove(Common::Player player) const;
    int GetNumLegalMoves(Common::Player player) const;
    int GetLegalMoves(Common::Player player, BreakthroughMove moves[MAX_MOVES]) const;
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

    inline bool IsInBounds(int row, int col) const
    {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }

private:
    Common::Piece mPosition[ROWS][COLS];

    int mPlayer1RemainingPieces;
    int mPlayer2RemainingPieces;
};

}
