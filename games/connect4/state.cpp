#include <iostream>
#include <games/connect4/state.h>
#include <common/game_types.h>

namespace Connect4 
{

Common::Result Connect4State::EvaluateState(const Connect4Move& lastMove)
{
    if (lastMove.player == Common::Player::NONE)
    {
        return Common::Result::ONGOING;
    }

    // Check all the wins in the row
    for (int col = 0, counter = 0; col < COLS; ++col)
    {
        if (mPosition[lastMove.row][col].player == lastMove.player)
        {
            if (counter++ == WIN_COND) return Common::PlayerToResult(lastMove.player);
        } else counter = 0;
    }

    // Check all the wins in the col
    for (int row = 0, counter = 0; row < ROWS; ++row)
    {
        if (mPosition[row][lastMove.col].player == lastMove.player)
        {
            if (counter++ == WIN_COND) return Common::PlayerToResult(lastMove.player);
        } else counter = 0;
    }

    // Check top left to bottom right diagonal
    bool go_top = true, go_bot = true;
    for (int top_row = lastMove.row - 1, 
        top_col = lastMove.col - 1,
        bot_row = lastMove.row + 1,
        bot_col = lastMove.col + 1,
        counter = 1;
        go_top || go_bot;)
    {
        if (go_top && top_row >= 0 && top_col >= 0 
            && mPosition[top_row][top_col].player == lastMove.player) 
        {
            if (counter++ == WIN_COND) return Common::PlayerToResult(lastMove.player);
            else { --top_row; --top_col;}
        } else go_top = false;

        if (go_bot && bot_row < ROWS && bot_col < COLS 
            && mPosition[bot_row][bot_col].player == lastMove.player) 
        {
            if (counter++ == WIN_COND) return Common::PlayerToResult(lastMove.player);
            else { ++bot_row; ++bot_col; }
        } else go_bot = false;
    }

    // Check bottom left to top right diagonal
    go_top = true, go_bot = true;
    for (int top_row = lastMove.row - 1,
        top_col = lastMove.col + 1,
        bot_row = lastMove.row + 1,
        bot_col = lastMove.col - 1,
        counter = 1;
        go_top || go_bot;)
    {
        if (go_top && top_row >= 0 && top_col < COLS
            && mPosition[top_row][top_col].player == lastMove.player)
        {
            if (counter++ == WIN_COND) return Common::PlayerToResult((lastMove.player));
            else { --top_row; ++top_col; }
        } else go_top = false;

        if (go_bot && bot_row < ROWS && bot_col >= 0 
            && mPosition[bot_row][bot_col].player == lastMove.player) 
        {
            if (counter++ == WIN_COND) return Common::PlayerToResult(lastMove.player);
            else { ++bot_row; --bot_col; }
        } else go_bot = false;
    }

    // Could be a draw if we are in the last row and its filled
    if (lastMove.row == 0)
    {
        for (int col = 0; col < COLS; ++col)
            if (mPosition[lastMove.row][col].player == Common::Player::NONE) return Common::Result::ONGOING;
        return Common::Result::DRAW;
    }

    return Common::Result::ONGOING;
}

// Puts all the possible moves the given player can make in this scenario into 
// the given moves array. It is the caller's responsibility to ensure that the moves
// array is sufficiently large enough
// Returns the number of moves found
int Connect4State::GetLegalMoves(Common::Player player, Connect4Move moves[MAX_MOVES]) const
{
    // For each column, find the lowest row
    int found = 0;

    for (int col = 0; col < COLS; ++col)
    {
        for (int row = ROWS - 1; row >= 0; --row) {
            if (mPosition[row][col].player == Common::Player::NONE)
            {
                moves[found++] = Connect4Move(player, row, col);
                break;
            }
        }
    }

    return found;
}

// Returns a copy of the current state after the move is made
// Does not affect the current state
// Assumes the given move is valid
// RVO should ensure returned state is not copied again
Connect4State Connect4State::MakeMove(const Connect4Move& move) const
{
    Connect4State newState = Connect4State(mPosition);
    newState.mPosition[move.row][move.col] = move.player;
    return newState;
}

// Makes a move, modifying the current state
// Assumes the given move is valid
void Connect4State::SimulateMove(const Connect4Move& move)
{
    mPosition[move.row][move.col] = move.player;
}

// True if the positions are equal
bool operator==(const Connect4State& lhs, const Connect4State& rhs)
{
    for (int i = 0; i < Connect4State::ROWS; ++i)
    {
        for (int j = 0; j < Connect4State::COLS; ++j)
        {
            if (lhs.mPosition[i][j].player != rhs.mPosition[i][j].player) return false;
        }
    }
    return true;
}

// Prints the current position
std::ostream& operator<<(std::ostream& os, const Connect4State& state)
{
    for (int i = 0; i < Connect4State::ROWS; ++i)
    {
        for (int j = 0; j < Connect4State::COLS; ++j)
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