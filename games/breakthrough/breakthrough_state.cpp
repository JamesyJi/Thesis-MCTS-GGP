#include "breakthrough_state.h"

namespace Breakthrough
{

// A win is determined when a player reaches the row farthest from them or
// when they have captured all the opponent's pieces.
Common::Result BreakthroughState::BreakthroughState::EvaluateState(const BreakthroughMove& lastMove)
{
    switch (lastMove.player)
    {
        case Common::Player::NONE:
            return Common::Result::ONGOING;                  
        case Common::Player::PLAYER1:
            if (lastMove.row == ROWS - 1 || mPlayer2RemainingPieces == 0) 
            {
                return Common::Result::PLAYER1_WIN;
            }
            return Common::Result::ONGOING;
        case Common::Player::PLAYER2:
            if (lastMove.row == 0 || mPlayer1RemainingPieces == 0)
            {
                return Common::Result::PLAYER2_WIN;
            }
            return Common::Result::ONGOING;
    }
}

BreakthroughMove BreakthroughState::GetRandomLegalMove(Common::Player player) const
{
    BreakthroughMove legalMoves[MAX_MOVES];
    int nLegalMoves = GetLegalMoves(player, legalMoves);
    // if (nLegalMoves == 0) {
    //     std::cout << "0 legal moves...\n";
    //     std::cout << *this;
    //     assert (nLegalMoves != 0);
    // }
    return legalMoves[rand() % nLegalMoves];
}

int BreakthroughState::GetLegalMoves(Common::Player player, BreakthroughMove moves[MAX_MOVES]) const
{
    int found = 0;

    int direction = player == Common::Player::PLAYER1 ? 1 : -1; 

    // TODO: Inefficient implementation. Should track position of pieces on the board instead
    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLS; ++col)
        {
            if (mPosition[row][col].player == player) 
            {
                // Find what squares they can move into
                int newRow = row + direction;

                // Diagonal Left
                int diagonalLeftCol = col - 1;
                if (IsInBounds(newRow, diagonalLeftCol) && mPosition[newRow][diagonalLeftCol].player != player)
                {
                    bool capture = mPosition[newRow][diagonalLeftCol].player != Common::Player::NONE;
                    moves[found++] = BreakthroughMove(player, row, col, newRow, diagonalLeftCol, capture);
                }

                // Straight
                if (IsInBounds(newRow, col) && mPosition[newRow][col].player == Common::Player::NONE)
                {
                    moves[found++] = BreakthroughMove(player, row, col, newRow, col, false);
                }

                // Diagonal Right
                int diagonalRightCol = col + 1;
                if (IsInBounds(newRow, diagonalRightCol) && mPosition[newRow][diagonalRightCol].player != player)
                {
                    bool capture = mPosition[newRow][diagonalRightCol].player != Common::Player::NONE;
                    moves[found++] = BreakthroughMove(player, row, col, newRow, diagonalRightCol, capture);
                }
            }
        }
    }

    return found;
}

// Returns a copy of the current state after the move is made
// Does not affect the current state
// Assumes the given move is valid
// RVO should ensure returned state is not copied again
BreakthroughState BreakthroughState::MakeMove(const BreakthroughMove& move) const
{
    BreakthroughState newState(*this);

    newState.mPosition[move.prevRow][move.prevCol].player = Common::Player::NONE;
    newState.mPosition[move.row][move.col].player = move.player;
    if (move.capture) {
        switch (move.player)
        {
        case Common::Player::PLAYER1:
            newState.DecrementPlayer2RemainingPieces();
            break;
        case Common::Player::PLAYER2:
            newState.DecrementPlayer1RemainingPieces();
            break;
        default:
            throw "Move was not player 1 or player 2";
            break;
        }
    }
    return newState;
}

// Makes a move, modifying the current state
// Assumes the given move is valid
void BreakthroughState::SimulateMove(const BreakthroughMove& move)
{
    mPosition[move.prevRow][move.prevCol].player = Common::Player::NONE;
    mPosition[move.row][move.col].player = move.player;
    if (move.capture) {
        switch (move.player)
        {
        case Common::Player::PLAYER1:
            --mPlayer2RemainingPieces;
            break;
        case Common::Player::PLAYER2:
            --mPlayer1RemainingPieces;
            break;
        default:
            throw "Move was not player 1 or player 2";
            break;
        }
    }

}

// Given a move, undoes it
// Assumes the given move is valid
void BreakthroughState::UndoMove(const BreakthroughMove& move)
{
    if (move.capture) {
        mPosition[move.row][move.col].player = Common::GetOtherPlayer(move.player);
    } else {
        mPosition[move.row][move.col].player = Common::Player::NONE;
    }

    mPosition[move.prevRow][move.prevCol].player = move.player;
}

// Prints the current position
std::ostream& operator<<(std::ostream& os, const BreakthroughState& state)
{
    for (int i = 0; i < BreakthroughState::ROWS; ++i)
    {
        for (int j = 0; j < BreakthroughState::COLS; ++j)
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