#include "linesofaction_state.hpp"

namespace LinesOfAction
{

inline static int TryStoreLegalMove(LinesOfActionMove moves[LinesOfActionState::MAX_MOVES], int found, const std::optional<LinesOfActionMove>& move);

// A win is determined when all of a player's pieces are connected.
// If 2 players make a group on the same turn, the mover wins.
Common::Result LinesOfActionState::EvaluateState(const LinesOfActionMove& lastMove) const
{
    if (lastMove.player == Common::Player::NONE) return Common::Result::ONGOING;

    // Do a DFS and see if we can find all the remaining pieces connected
    int row_q[STARTING_PIECES];
    int col_q[STARTING_PIECES];
    row_q[0] = lastMove.row;
    col_q[0] = lastMove.col;

    bool visited_row[STARTING_PIECES] = {};
    bool visited_col[STARTING_PIECES] = {};
    visited_row[row_q[0]] = true;
    visited_col[col_q[0]] = true;

    int q_size = 1;
    int q_index = 0;
    while (q_index < q_size) {
        // Visit all neighbours
        const int& row = row_q[q_index];
        const int& col = col_q[q_index];

        if (IsSamePlayer(row + 1, col, lastMove.player) && !visited_row[row + 1] && !visited_col[col]) {
            row_q[q_size] = row + 1;
            col_q[q_size] = col;
            visited_row[row + 1] = true;
            visited_col[col] = true;
            ++q_size;
        }

        if (IsSamePlayer(row - 1, col, lastMove.player) && !visited_row[row - 1] && !visited_col[col]) {
            row_q[q_size] = row - 1;
            col_q[q_size] = col;
            visited_row[row - 1] = true;
            visited_col[col] = true;
            ++q_size;
        }

        if (IsSamePlayer(row, col + 1, lastMove.player) && !visited_row[row] && !visited_col[col + 1]) {
            row_q[q_size] = row;
            col_q[q_size] = col + 1;
            visited_row[row] = true;
            visited_col[col + 1] = true;
            ++q_size;
        }

        if (IsSamePlayer(row, col - 1, lastMove.player) && !visited_row[row] && !visited_col[col - 1]) {
            row_q[q_size] = row;
            col_q[q_size] = col - 1;
            visited_row[row] = true;
            visited_col[col - 1] = true;
            ++q_size;
        }

        ++q_index;
    }

    if (q_size == mPlayerRemainingPieces[static_cast<int>(lastMove.player)]) {
        return Common::PlayerToResult(lastMove.player);
    }
    else {
        return Common::Result::ONGOING;
    }
}

LinesOfActionMove LinesOfActionState::GetRandomLegalMove(Common::Player player) const
{
    LinesOfActionMove legalMoves[MAX_MOVES];
    int nLegalMoves = GetLegalMoves(player, legalMoves);
    return legalMoves[rand() % nLegalMoves];
}

int LinesOfActionState::GetNumLegalMoves(Common::Player player) const
{
    LinesOfActionMove legalMoves[MAX_MOVES];
    return GetLegalMoves(player, legalMoves);
}

int LinesOfActionState::GetLegalMoves(Common::Player player, LinesOfActionMove moves[MAX_MOVES]) const
{
    int found = 0;

    // Calculate how many pieces are in each row and col
    int inRow[SIZE] = {}; // inRow[0] = number of pieces in row 0
    int inCol[SIZE] = {}; // inCol[0] = number of pieces in col 0
    // top left to bottom right diagonals. inDiag1[SIZE - 1] = Main diagonal
    // inDiag1[0] = bottom left square
    // inDiag1[SIZE * 2 - 2] = top right square
    // A coordinate row, col is indexed by inDiag1[col - row + SIZE - 1]
    int inDiag1[SIZE * 2 - 1] = {};

    // bottom left to top right diagonals. inDiag2[SIZE - 1] = Main diagonal
    // inDiag2[0] = top left square
    // inDiag2[SIZE * 2 - 2] = bottom right square
    // A coordinate row, col is indexed by inDiag2[row + col]
    int inDiag2[SIZE * 2 - 1] = {};
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (mPosition[row][col].player != Common::Player::NONE) {
                inRow[row]++;
                inCol[col]++;
                inDiag1[col - row + SIZE - 1]++;
                inDiag2[row + col]++;
            }
        }
    }

    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (mPosition[row][col].player == player) {
                // TODO: Possible to dispatch template in while loop?
                // found = LinesOfAction::TryStoreLegalMove(moves, found, TryGetLegalMove<Common::Direction::W>(row, col, player, inRow[row]));
                found = TryStoreLegalMove(moves, found, TryGetLegalMove<Common::Direction::W>(row, col, player, inRow[row]));

                found = TryStoreLegalMove(moves, found, TryGetLegalMove<Common::Direction::E>(row, col, player, inRow[row]));

                found = TryStoreLegalMove(moves, found, TryGetLegalMove<Common::Direction::N>(row, col, player, inCol[col]));

                found = TryStoreLegalMove(moves, found, TryGetLegalMove<Common::Direction::S>(row, col, player, inCol[col]));

                found = TryStoreLegalMove(moves, found, TryGetLegalMove<Common::Direction::NE>(row, col, player, inDiag2[row + col]));

                found = TryStoreLegalMove(moves, found, TryGetLegalMove<Common::Direction::SW>(row, col, player, inDiag2[row + col]));

                found = TryStoreLegalMove(moves, found, TryGetLegalMove<Common::Direction::NW>(row, col, player, inDiag1[col - row + SIZE - 1]));

                found = TryStoreLegalMove(moves, found, TryGetLegalMove<Common::Direction::SE>(row, col, player, inDiag1[col - row + SIZE - 1]));
            }
        }
    }

    // If no legal moves are found, we must pass which is also considered a legal move
    if (found == 0) {
        moves[found++] = LinesOfActionMove();
    }
    return found;
}

/**
 * Returns a copy of the current state after the move is made
 * Does not affect the current state
 * Assumes the given move is valid
 * RVO should ensure returned state is not copied again
*/
LinesOfActionState LinesOfActionState::MakeMove(const LinesOfActionMove& move) const {
    LinesOfActionState newState(*this);

    newState.SimulateMove(move);

    return newState;
}

// Makes a move, modifying the current state
// Assumes the given move is valid
void LinesOfActionState::SimulateMove(const LinesOfActionMove& move) {
    mPosition[move.prevRow][move.prevCol].player = Common::Player::NONE;
    mPosition[move.row][move.col].player = move.player;
    if (move.capture) {
        mPlayerRemainingPieces[static_cast<int>(Common::GetOtherPlayer(move.player))]--;
    }
}

/**
 * Given a move, undoes it. Assumes the given move is valid
*/
void LinesOfActionState::UndoMove(const LinesOfActionMove& move) {
    if (move.capture)
    {
        mPosition[move.row][move.col].player = Common::GetOtherPlayer(move.player);
        mPlayerRemainingPieces[static_cast<int>(Common::GetOtherPlayer(move.player))]++;
    }
    else {
        mPosition[move.row][move.col].player = Common::Player::NONE;
    }

    mPosition[move.prevRow][move.prevCol].player = move.player;
}

// Prints the current position
std::ostream& operator<<(std::ostream& os, const LinesOfActionState& state) {
    for (int row = 0; row < LinesOfActionState::SIZE; ++row) {
        for (int col = 0; col < LinesOfActionState::SIZE; ++col) {
            switch (state.mPosition[row][col].player)
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

inline static int TryStoreLegalMove(LinesOfActionMove moves[LinesOfActionState::MAX_MOVES], int found, const std::optional<LinesOfActionMove>& move) {
    if (move.has_value()) {
        moves[found++] = std::move(move.value());
    }
    return found;
}
}