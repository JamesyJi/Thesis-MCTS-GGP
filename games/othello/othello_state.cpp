#include <iostream>
#include <memory>

#include "othello_state.h"

namespace Othello
{

Common::Result OthelloState::EvaluateState(const OthelloMove& lastMove)
{
    if (lastMove.player == Common::Player::NONE)
    {
        if (mSkippedTurns != 2)
        {
            return Common::Result::ONGOING;
        }
    }
    
    return CountWinner();
}

// NOTE: This is actually very slow since we do not optimise as we check every
// single square. However, the paper (MCTS Minimax Hybrids) also had a very 
// slow othello implementation so this should be fine
int OthelloState::GetLegalMoves(Common::Player player, OthelloMove[MAX_MOVES] legalMoves) const
{
    int found = 0;
    
    Common::Player otherPlayer = Common::Player::GetOtherPlayer(player);

    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLS; ++col)
        {
            if (mPosition[row][col].player != Common::Player::NONE) continue;

            // Determine if this is adjacent to an opponent's piece
            for (int dir = NW; dir != END; ++dir)
            {
                int stepRow = row + Directions[dir].row;
                int stepCol = col + Directions[dir].col;
                
                if (!IsInBounds(stepRow, stepCol)) continue;

                if (mPosition[stepRow][stepCol].player != otherPlayer) continue;

                // We can potentially place a piece here as it's in a valid 
                // square and adjacent to the opponent.
                // However before we do, we need to check if it "flanks" the opponent's pieces
                stepRow += Directions[dir].row;
                stepCol += Directions[dir].col;
                while (IsInBounds(stepRow, stepCol))
                {
                    if (mPosition[stepRow][stepCol] == Common::Player::NONE) break;

                    if (mPosition[stepRow][stepCol].player == player)
                    {
                        // Found a flanking piece
                        legalMoves[found++] = OthelloMove(player, row, col, dir, stepRow, stepCol);
                        goto nextSquare;
                    }

                    stepRow += Directions[dir].row;
                    stepCol += Directions[dir].col;
                }
            }

            nextSquare:
        }
    }

    return found;
}

OthelloState OthelloState::MakeMove(const OthelloMove& move) const
{
    OthelloState newState(*this);

    newState.mPosition[move.row][move.col]
}


Common::Result CountWinner() const
{
    int player1Pieces = 0;
    int player2Pieces = 0;
    for (int row = 0; row < ROWS; ++row)
        for (int col = 0; col < COLS; ++col)
        {
            switch (mPosition[row][col].player)
            {
            case Common::Player::PLAYER1:
                ++player1Pieces
                break;
            case Common::Player::PLAYER2:
                ++player2Pieces;
                break;
            default:
                break;
            }
        }

    if (player1Pieces == player2Pieces) return Common::Result::DRAW;
    else if (player1Pieces > player2Pieces) return Common::Result::PLAYER1_WIN;
    else return Common::Result::PLAYER2_WIN;    
}

}