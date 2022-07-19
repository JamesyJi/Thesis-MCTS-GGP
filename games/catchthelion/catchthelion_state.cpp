#include <iostream>
#include <memory>

#include "catchthelion_state.h"

namespace CatchTheLion
{

Common::Result CatchTheLion::EvaluateState(const CTLMove &lastMove)
{
    if (lastMove.player == Common::Player::NONE)
    {
        return Common::Result::ONGOING;
    }

    // If there's a drop, the game cannot be anything but ongoing
    if (lastMove.moveType == MoveType::DROP)
    {
        return Common::Result::ONGOING;
    }

    // Capturing the lion wins the game
    if (lastMove.capturedPiece == CTLPieceType::LION)
    {
        return PlayerToResult(lastMove.player);
    }

    // Lion to back rank (not in check) wins the game
    if (lastMove.piece == CTLPieceType::LION)
    {
        switch (lastMove.player)
        {
            case Common::Player::PLAYER1:
                if (lastMove.row == 3) return Common::Result::PLAYER1_WIN;
                break;
            case Common::Player::PLAYER2:
                if (lastMove.row == 0) return Common::Result::PLAYER2_WIN;
                break;
        }
    }

    // TODO: Determine if draw due to repetition

    return Common::Result::ONGOING;  
};

CatchTheLionMove CatchTheLion::GetRandomLegalMove(Common::Player player) const
{

}

int CatchTheLionState::GetLegalMoves(Common::Player player, CTLMove moves[MAX_MOVES]) const
{
    int found = 0;

    // Determine if we are moving up or down
    int destRow;
    switch (player)
    {
        case Common::Player::PLAYER1:
            destRow = row + 1;
            break;
        case Common::Player::PLAYER2:
            destRow = row - 1;
            break;
        default:
            throw "Should only be player1 or player2 in GetLegalMoves";
    }

    // Get all the MOVES
    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLS; ++col)
        {
            const auto& piece = mPosition[row][col];
            if (piece.player == player)
            {
                // This is a piece we could move
                switch (piece.pieceType)
                {
                case CTLPieceType::CHICK;
                    found = AddChickLegalMoves(player, destRow, row, col, found, moves);
                    break;
                case CTLPieceType::ELEPHANT:
                    found = AddElephantLegalMoves(player, row, col, found, moves);
                    break;
                case CTLPieceType::GIRAFFE:
                    found = AddGiraffeLegalMoves(player, row, col, found, moves);
                    break;
                case CTLPieceType::LION:
                    found = AddLionLegalMoves(player, row, col, found, moves);
                    break;
                case CTLPieceType::HEN:
                    found = AddHenLegalMoves(player, row, col, found, moves);
                    break;
                case CTLPieceType::NONE:
                    break;
                }
            }
        }
    }

    // Get all the DROPS
}

// PRECONDITION: Player cannot be NONE
// Given row and col position of a Chick, add all legal moves and return the new found
int CatchTheLion::AddChickLegalMoves(Common::Player player, int destRow, int row, int col, int found, CTLMove moves[MAX_MOVES]) const
{
    // Cannot move if it is on the final row
    if constexpr (player == Common::Player::PLAYER1)
    {
        if (destRow == ROWS - 1) return found;
    } else if constexpr (player == Common::Player::PLAYER2)
    {
        if (destRow == 0) return found;
    }

    auto &destPiece = mPosition[destRow][col];

    // Cannot move into itself
    if (destPiece.player == player) return found;

    if (destPiece.player == Common::Player::NONE)
    {
        moves[found++] = CTLMove(player, piece, row, col, destRow, col, CTLPieceType::NONE);
        return found;
    } else {
        moves[found++] = CTLMove(player, piece, row, col, destRow, col, destPiece.pieceType);
        return found;
    }
}

int CatchTheLion::AddElephantLegalMoves(Common::Player player, int row, int col, int found, CTLMove moves[MAX_MOVES]) const
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
                moves[found++] = CTLMove(player, piece, row, col, newRow, newCol, Common::Piece::NONE);
            } else
            {
                moves[found++] = CTLMove(player, piece, row, col, newRow, newCol, destPiece.pieceType);
            }
        }
    }

    return found;
}

int CatchTheLion::AddGiraffeLegalMoves(Common::Player player, int row, int col, int found, CTLMove moves[MAX_MOVES]) const
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
                moves[found++] = CTLMove(player, piece, row, col, newRow, newCol, Common::Piece::NONE);
            } else
            {
                moves[found++] = CTLMove(player, piece, row, col, newRow, newCol, destPiece.pieceType);
            }
        }
    }

    return found;
}

int CatchTheLion::AddLionLegalMoves(Common::Player player, int row, int col, int found, CTLMove moves[MAX_MOVES]) const
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
                moves[found++] = CTLMove(player, piece, row, col, newRow, newCol, Common::Piece::NONE);
            } else
            {
                moves[found++] = CTLMove(player, piece, row, col, newRow, newCol, destPiece.pieceType);
            }
        }
    }

    return found;
}

int CatchTheLion::AddHenLegalMoves(Common::Player player, int row, int col, int found, CTLMove moves[MAX_MOVES]) const
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
                moves[found++] = CTLMove(player, piece, row, col, newRow, newCol, Common::Piece::NONE);
            } else
            {
                moves[found++] = CTLMove(player, piece, row, col, newRow, newCol, destPiece.pieceType);
            }
        }
    }

    return found;
}

}