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

            Direction dir;
            if (!IsAdjacentToOtherPlayer(player, row, col, &dir)) continue;

            OthelloMove move(player, row, col);
            if (!FindUpdateCaptureDirections(player, row, col, dir, move)) continue;

            legalMoves[found++] = move;
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
    std::cout << "make move " << move.row << " " << move.col << " " << move.direction << " " << move.flankRow << " " << move.flankCol << "\n";
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
    std::cout << "step.row = " << step.row << " step.col = " << step.col << "\n"; 
    while (stepRow != move.flankRow && stepCol != move.flankCol)
    {
        std::cout << "stepRow = " << stepRow << " stepCol = " << stepCol << "\n";
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

// Precondition: row, col are in bounds
// Returns true if this move would be adjacent to the other player.
// It will also update the direction the first opponent was discovered in
bool OthelloState::IsAdjacentToOtherPlayer(Common::Player otherPlayer, int row, int col, Direction *opponentDirection) const
{
    for (int d = NW; d != END; ++d)
    {
        Direction dir = static_cast<Direction>(d);
        int checkRow = row + Directions[dir].row;
        int checkCol = col + Directions[dir].col;
        if (!IsInBounds(checkRow, checkCol)) continue;
        
        if (mPosition[checkRow][checkCol].player != otherPlayer) continue;
        
        *opponentDirection = dir;
        return true;
    }

    return false;
}

// Precondition: All directions before this are not adjacent to an opponent
// Returns true if this would result in a capture
// It will update the move with all the captures in all directions
// NOTE: We can pass in a starting direction for optimisation as we know the
// prior directions have not been checked
bool OthelloState::FindUpdateCaptureDirections(Common::Player player, int row, int col, Direction dir, OthelloMove &move) const
{
    bool foundCapture = false;

    for (int d = dir; d != END; ++d)
    {
        dir = static_cast<Direction>(d);
        // Check if this would flank pieces.
        Step& step = Directions[dir];
        
        // Adjacent should be opponent,
        int checkRow = row + step.row;
        int checkCol = col + step.col;
        if (!IsInBounds(checkRow, checkCol) || mPosition[checkRow][checkCol] != Common::GetOtherPlayer(player))
        {
            return false;
        }

        // We should have a piece in this direction afterwards
        checkRow += step.row;
        checkCol += step.col;
        while (IsInBounds(checkRow, checkCol))
        {
            if (mPosition[checkRow][checkCol].player == player)
            {
                // Found a capture!
                move.CaptureInDirection(dir);
                foundCapture = true;
                break;
            }
            checkRow += step.row;
            checkCol += step.col;
        }
    }
    
    return foundCapture;
}




}