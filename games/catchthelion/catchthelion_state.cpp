#include <iostream>
#include <memory>

#include "catchthelion_state.h"

namespace CatchTheLion
{

Common::Result CatchTheLionState::EvaluateState(const CatchTheLionMove &lastMove) const
{
    // std::cout << "Evaluating State\n";
    // std::cout << *this;
    // std::cout << "lastMove: " << lastMove << "\n";

    if (lastMove.player == Common::Player::NONE)
    {
        // std::cout << Common::Result::ONGOING << "\n";
        return Common::Result::ONGOING;
    }

    // If there's a drop, the game cannot be anything but ongoing
    if (lastMove.moveType == MoveType::DROP)
    {
        // std::cout << Common::Result::ONGOING << "\n";
        return Common::Result::ONGOING;
    }

    // Capturing the lion wins the game
    if (lastMove.capturedPieceType == Common::CatchTheLionPieceType::LION)
    {
        // std::cout << PlayerToResult(lastMove.player) << "\n";
        return PlayerToResult(lastMove.player);
    }

    // Lion to back rank (not in check) wins the game
    if (lastMove.pieceType == Common::CatchTheLionPieceType::LION)
    {
        switch (lastMove.player)
        {
            case Common::Player::PLAYER1:
                if (lastMove.row == 3) return Common::Result::PLAYER1_WIN;
                break;
            case Common::Player::PLAYER2:
                if (lastMove.row == 0) return Common::Result::PLAYER2_WIN;
                break;
            default:
                std::runtime_error("Lion move cannot have player of NONE");
        }
    }

    // TODO: Determine if draw due to repetition

    // std::cout << Common::Result::ONGOING << "\n";
    return Common::Result::ONGOING;  
};

CatchTheLionMove CatchTheLionState::GetRandomLegalMove(Common::Player player) const
{
    CatchTheLionMove legalMoves[MAX_MOVES];
    int nLegalMoves = GetLegalMoves(player, legalMoves);

    return legalMoves[rand() % nLegalMoves];
}

int CatchTheLionState::GetLegalMoves(Common::Player player, CatchTheLionMove moves[MAX_MOVES]) const
{
    int found = 0;

    // Determine if we are moving up or down
    int destRow;
    int const (&drops)[3] = std::invoke([&]()->int const(&)[3] {
        switch(player)
        {
        case Common::Player::PLAYER1:
            destRow = ROWS - 1;
            return mPlayer1Drops;
        case Common::Player::PLAYER2:
            destRow = 0;
            return mPlayer2Drops;
        default:
            throw std::runtime_error("Should only be player 1 or player 2 in GetLegalMoves");
        }
    });

    // Get all the MOVES
    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLS; ++col)
        {
            const auto& piece = mPosition[row][col];
            if (piece.player == player)
            {
                // Determine what moves we can make
                switch (piece.pieceType)
                {
                case Common::CatchTheLionPieceType::CHICK:
                    found = AddChickLegalMoves(player, destRow, row, col, found, moves);
                    break;
                case Common::CatchTheLionPieceType::ELEPHANT:
                    found = AddElephantLegalMoves(player, row, col, found, moves);
                    break;
                case Common::CatchTheLionPieceType::GIRAFFE:
                    found = AddGiraffeLegalMoves(player, row, col, found, moves);
                    break;
                case Common::CatchTheLionPieceType::LION:
                    found = AddLionLegalMoves(player, row, col, found, moves);
                    break;
                case Common::CatchTheLionPieceType::HEN:
                    found = AddHenLegalMoves(player, row, col, found, moves);
                    break;
                case Common::CatchTheLionPieceType::NONE:
                    break;
                }
            } else if (piece.player == Common::Player::NONE)
            {
                // Determine what drops we can make
                found = AddLegalDrops(player, drops, row, col, found, moves);
            }
        }
    }

    // std::cout << "Found " << found << " moves\n";
    // for (int i = 0; i < found; ++i)
    // {
    //     std::cout << moves[i] << "\n";
    // }

    return found;
}

CatchTheLionState CatchTheLionState::MakeMove(const CatchTheLionMove& move) const
{
    CatchTheLionState newState(*this);

    newState.SimulateMove(move);

    return newState;
}

void CatchTheLionState::SimulateMove(const CatchTheLionMove& move)
{
    // std::cout << "SimulateMove " << move << "\n";
    switch (move.moveType)
    {
    case MoveType::DROP:
        mPosition[move.row][move.col] = Common::CatchTheLionPiece(move.player, move.pieceType);
        DecrDrop(move.player, move.pieceType);
        break;
    case MoveType::MOVE:
        // Captured a piece
        // Do not increment move for capturing a lion
        if (move.capturedPieceType != Common::CatchTheLionPieceType::NONE)
        {
            mPosition[move.prevRow][move.prevCol] = Common::CatchTheLionPiece();
            if (move.capturedPieceType != Common::CatchTheLionPieceType::LION)
            {
                IncrDrop(move.player, move.capturedPieceType);
            }
        }
        
        // Promoting a CHICK
        if (move.pieceType == Common::CatchTheLionPieceType::CHICK)
        {
            switch (move.player)
            {
            case Common::Player::PLAYER1:
                if (move.row == ROWS - 1)
                {
                    mPosition[move.row][move.col] = Common::CatchTheLionPiece(move.player, Common::CatchTheLionPieceType::HEN);
                }
            case Common::Player::PLAYER2:
                if (move.row == 0)
                {
                    mPosition[move.row][move.col] = Common::CatchTheLionPiece(move.player, Common::CatchTheLionPieceType::HEN);
                }
            default:
                throw std::runtime_error("Move should be player 1 or player 2 in SimulateMove");
            }
        } else
        {
            mPosition[move.row][move.col] = Common::CatchTheLionPiece(move.player, move.pieceType);
        }
        break;
    }
}

void CatchTheLionState::UndoMove(const CatchTheLionMove& move)
{
    switch (move.moveType)
    {
        case MoveType::DROP:
            mPosition[move.row][move.col] = Common::CatchTheLionPiece();
            IncrDrop(move.player, move.pieceType);
            break;
        case MoveType::MOVE:
            mPosition[move.prevRow][move.prevCol] = Common::CatchTheLionPiece(move.player, move.pieceType);

            if (move.capturedPieceType == Common::CatchTheLionPieceType::NONE)
            {
                mPosition[move.row][move.col] = Common::CatchTheLionPiece();
            } else
            {
                mPosition[move.row][move.col] = Common::CatchTheLionPiece(Common::GetOtherPlayer(move.player), move.capturedPieceType);
                DecrDrop(move.player, move.capturedPieceType);
            }
            break;
    }
}

// PRECONDITION: Player cannot be NONE
// Given row and col position of a Chick, add all legal moves and return the new found
int CatchTheLionState::AddChickLegalMoves(Common::Player player, int destRow, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const
{
    // Cannot move if it is on the final row
    if (player == Common::Player::PLAYER1)
    {
        if (destRow == ROWS - 1) return found;
    } else if (player == Common::Player::PLAYER2)
    {
        if (destRow == 0) return found;
    }

    auto &destPiece = mPosition[destRow][col];

    // Cannot move into itself
    if (destPiece.player == player) return found;

    if (destPiece.player == Common::Player::NONE)
    {
        moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::CHICK, row, col, destRow, col);
        return found;
    } else {
        moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::CHICK, row, col, destRow, col, destPiece.pieceType);
        return found;
    }
}

int CatchTheLionState::AddElephantLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const
{
    // Check top left, top right, bottom left, bottom right
    for (int i = 0; i < NUM_ELEPHANT_DIRECTIONS; ++i)
    {
        auto& step = ElephantDirections[i];
        int newRow = step.row + row;
        int newCol = step.col + col;
        if (IsInBounds(newRow, newCol))
        {
            auto &destPiece = mPosition[newRow][newCol];
            if (destPiece.player == player)
            {
                continue;
            }
            
            if (destPiece.player == Common::Player::NONE)
            {
                moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::ELEPHANT, row, col, newRow, newCol);
            } else
            {
                moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::ELEPHANT, row, col, newRow, newCol, destPiece.pieceType);
            }
        }
    }

    return found;
}

int CatchTheLionState::AddGiraffeLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const
{
    // Check top left, top right, bottom left, bottom right
    for (int i = 0; i < NUM_GIRAFFE_DIRECTIONS; ++i)
    {
        auto& step = GiraffeDirections[i];
        int newRow = step.row + row;
        int newCol = step.col + col;
        if (IsInBounds(newRow, newCol))
        {
            auto &destPiece = mPosition[newRow][newCol];
            if (destPiece.player == player)
            {
                continue;
            }
            
            if (destPiece.player == Common::Player::NONE)
            {
                moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::GIRAFFE, row, col, newRow, newCol);
            } else
            {
                moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::GIRAFFE, row, col, newRow, newCol, destPiece.pieceType);
            }
        }
    }

    return found;
}

int CatchTheLionState::AddLionLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const
{
    // Check top left, top right, bottom left, bottom right
    for (int i = 0; i < NUM_LION_DIRECTIONS; ++i)
    {
        auto& step = LionDirections[i];
        int newRow = step.row + row;
        int newCol = step.col + col;
        if (IsInBounds(newRow, newCol))
        {
            auto &destPiece = mPosition[newRow][newCol];
            if (destPiece.player == player)
            {
                continue;
            }
            
            if (destPiece.player == Common::Player::NONE)
            {
                moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::LION, row, col, newRow, newCol);
            } else
            {
                moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::LION, row, col, newRow, newCol, destPiece.pieceType);
            }
        }
    }

    return found;
}

int CatchTheLionState::AddHenLegalMoves(Common::Player player, int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const
{
    // Check top left, top right, bottom left, bottom right
    auto& henDirections = player == Common::Player::PLAYER1 ? HenDirectionsPlayer1 : HenDirectionsPlayer2;

    for (int i = 0; i < NUM_HEN_DIRECTIONS; ++i)
    {
        auto& step = henDirections[i];
        int newRow = step.row + row;
        int newCol = step.col + col;
        if (IsInBounds(newRow, newCol))
        {
            auto &destPiece = mPosition[newRow][newCol];
            if (destPiece.player == player)
            {
                continue;
            }
            
            if (destPiece.player == Common::Player::NONE)
            {
                moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::HEN, row, col, newRow, newCol);
            } else
            {
                moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::HEN, row, col, newRow, newCol, destPiece.pieceType);
            }
        }
    }

    return found;
}

// Adds all legal drops available to the given player for a specific square on the board
int CatchTheLionState::AddLegalDrops(Common::Player player, int const (&drops)[3], int row, int col, int found, CatchTheLionMove moves[MAX_MOVES]) const
{
    // CHICK
    if (drops[Common::CatchTheLionPieceType::CHICK] > 0) {
        moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::CHICK, row, col);
    }

    // ELEPHANT
    if (drops[Common::CatchTheLionPieceType::ELEPHANT] > 0) {
        moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::ELEPHANT, row, col);
    }

    // GIRAFFE
    if (drops[Common::CatchTheLionPieceType::GIRAFFE] > 0) {
        moves[found++] = CatchTheLionMove(player, Common::CatchTheLionPieceType::GIRAFFE, row, col);
    }

    return found;
}

std::ostream& operator<<(std::ostream& os, const CatchTheLionState& state)
{
    // Print player 1 drops
    os << "P1 Drops\n";
    os << Common::CatchTheLionPieceType::CHICK << ": ";
    os << state.mPlayer1Drops[Common::CatchTheLionPieceType::CHICK] << ", ";
    os << Common::CatchTheLionPieceType::ELEPHANT << ": ";
    os << state.mPlayer1Drops[Common::CatchTheLionPieceType::ELEPHANT] << ", ";
    os << Common::CatchTheLionPieceType::GIRAFFE << ": ";
    os << state.mPlayer1Drops[Common::CatchTheLionPieceType::GIRAFFE] << "\n";

    // Print the board
    for (int i = 0; i < CatchTheLionState::ROWS; ++i)
    {
        for (int j = 0; j < CatchTheLionState::COLS; ++j)
        {
            auto &piece = state.mPosition[i][j];
            switch (piece.player)
            {
            case Common::Player::PLAYER1:
                os << "\033[1;34m" << piece << "\033[0m";
                break;
            case Common::Player::PLAYER2:
                os << "\033[1;31m" << piece << "\033[0m";
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

    // Print player 2 drops
    os << "P2 Drops\n";
    os << Common::CatchTheLionPieceType::CHICK << ": ";
    os << state.mPlayer2Drops[Common::CatchTheLionPieceType::CHICK] << ", ";
    os << Common::CatchTheLionPieceType::ELEPHANT << ": ";
    os << state.mPlayer2Drops[Common::CatchTheLionPieceType::ELEPHANT] << ", ";
    os << Common::CatchTheLionPieceType::GIRAFFE << ": ";
    os << state.mPlayer2Drops[Common::CatchTheLionPieceType::GIRAFFE] << "\n";

    return os;
}

}