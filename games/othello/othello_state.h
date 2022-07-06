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
    static const int MAX_MOVES = ROWS * COLS;
    
    OthelloState()
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = Common::Piece();

        mPosition[3][3] = Common::Piece(Common::Player::PLAYER1);
        mPosition[4][4] = Common::Piece(Common::Player::PLAYER1);
        mPosition[3][4] = Common::Piece(Common::Player::PLAYER2);
        mPosition[4][3] = Common::Piece(Common::Player::PLAYER2);
    }

    Common::Result EvaluateState(const OthelloMove& lastMove);
    int GetLegalMoves(Common::Player player, OthelloMove[MAX_MOVES]) const;
    OthelloState MakeMove(const OthelloMove&) const;
    void SimulateMove(const OthelloMove&);
    void UndoMove(const OthelloMove&);

    friend bool operator==(const OthelloState& lhs, const OthelloState& rhs);
    friend std::ostream& operator<<(std::ostream& os, const OthelloState& state);

private:
    Common::Piece mPosition[ROWS][COLS];

    // Increment each time a player skips a turn
    // 2 ==> both players have skipped turns. Determine the winner
    int mSkippedTurns = 0;

private:
    Common::Result CountWinner() const;

    bool IsInBounds(int row, int col) const
    {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }
};

}