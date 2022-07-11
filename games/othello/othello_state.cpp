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
    
    return DetermineWinner();
}

OthelloMove OthelloState::GetRandomLegalMove(Common::Player player) const
{
    OthelloMove legalMoves[MAX_MOVES];
    int nLegalMoves = GetLegalMoves(player, legalMoves);
    return legalMoves[rand() % nLegalMoves];
}


// NOTE: This is actually very slow since we do not optimise as we check every
// single square. However, the paper (MCTS Minimax Hybrids) also had a very 
// slow othello implementation so this should be fine
int OthelloState::GetLegalMoves(Common::Player player, OthelloMove legalMoves[MAX_MOVES]) const
{
    int found = 0;
    
    Common::Player otherPlayer = Common::GetOtherPlayer(player);

    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLS; ++col)
        {
            if (mPosition[row][col].player != Common::Player::NONE) continue;

            // Determine if this is adjacent to an opponent's piece
            for (int d = NW; d != END; ++d)
            {
                Direction dir = static_cast<Othello::Direction>(d);
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
                    if (mPosition[stepRow][stepCol].player == Common::Player::NONE) break;

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
            
            nextSquare:;
        }
    }

    // If no moves, we must pass (which is also considered a move)
    if (found == 0)
    {
        legalMoves[found++] = OthelloMove();
    }

    return found;
}

// The assumption here is that our move is valid (flanks pieces)
OthelloState OthelloState::MakeMove(const OthelloMove& move) const
{
    OthelloState newState(*this);

    if (move.player == Common::Player::NONE)
    {
        newState.SkipTurn();
        return newState;
    }

    newState.ResetSkippedTurns();

    newState.mPosition[move.row][move.col].player = move.player;
    
    // Flip the pieces until we reach the flank piece
    const Step& step = Directions[move.direction];
    int stepRow = move.row + step.row;
    int stepCol = move.col + step.col;
    while (stepRow != move.flankRow && stepCol != move.flankCol)
    {
        newState.mPosition[step.row][step.col].player = move.player;

        stepRow += step.row;
        stepCol += step.col;
    }

    return newState;
}

void OthelloState::SimulateMove(const OthelloMove& move)
{
    if (move.player == Common::Player::NONE)
    {
        SkipTurn();
        return;
    }

    ResetSkippedTurns();

    mPosition[move.row][move.col].player = move.player;
    
    // Flip pieces until we reach flank piece
    const Step& step = Directions[move.direction];
    int stepRow = move.row + step.row;
    int stepCol = move.col + step.col;
    while (stepRow != move.flankRow && stepCol != move.flankCol)
    {
        mPosition[step.row][step.col].player = move.player;
        stepRow += step.row;
        stepCol += step.col;
    }
}

Common::Result OthelloState::DetermineWinner() const
{
    int player1Pieces = 0;
    int player2Pieces = 0;
    for (int row = 0; row < ROWS; ++row)
        for (int col = 0; col < COLS; ++col)
        {
            switch (mPosition[row][col].player)
            {
            case Common::Player::PLAYER1:
                ++player1Pieces;
                break;
            case Common::Player::PLAYER2:
                ++player2Pieces;
                break;
            default:
                return Common::Result::ONGOING;
                break;
            }
        }

    if (player1Pieces == player2Pieces) return Common::Result::DRAW;
    else if (player1Pieces > player2Pieces) return Common::Result::PLAYER1_WIN;
    else return Common::Result::PLAYER2_WIN;    
}

bool operator==(const OthelloState& lhs, const OthelloState& rhs)
{
    if (lhs.mSkippedTurns != rhs.mSkippedTurns) return false;
    
    for (int i = 0; i < OthelloState::ROWS; ++i)
    {
        for (int j = 0; j < OthelloState::COLS; ++j)
        {
            if (lhs.mPosition[i][j] != rhs.mPosition[i][j]) return false;
        }
    }

    return true;
}


std::ostream& operator<<(std::ostream& os, const OthelloState& state)
{
    for (int i = 0; i < OthelloState::ROWS; ++i)
    {
        for (int j = 0; j < OthelloState::COLS; ++j)
        {
            switch (state.mPosition[i][j].player)
            {
            case Common::Player::PLAYER1:
                os << "\033[1;34mX\033[0m";
                break;
            case Common::Player::PLAYER2:
                os << "\033[1;31mO\033[0m";
                break;
            case Common::Player::NONE:
                os << " ";
                break;
            default:
                break;
            }
            os << " | ";
        }
        os << "\n";
    }
return os;
}


}