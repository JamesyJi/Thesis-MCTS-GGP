#pragma once

#include <optional>

#include "pieces.h"
#include "direction.hpp"
#include "linesofaction_move.hpp"

namespace LinesOfAction
{

class LinesOfActionState
{

public:
    static const int SIZE = 8;
    static const int MAX_MOVES = 12 * 28; // 12 pieces, each piece could move a max of 28 times (not really though)
    static const int STARTING_PIECES = 12;

    LinesOfActionState()
    {
        mPlayerRemainingPieces[static_cast<int>(Common::Player::PLAYER1)] = STARTING_PIECES;
        mPlayerRemainingPieces[static_cast<int>(Common::Player::PLAYER2)] = STARTING_PIECES;

        for (int row = 1; row < SIZE - 1; ++row) {
            mPosition[row][0] = Common::Piece(Common::Player::PLAYER1);
            mPosition[row][SIZE - 1] = Common::Piece(Common::Player::PLAYER1);
        }

        for (int col = 1; col < SIZE - 1; ++col) {
            mPosition[0][col] = Common::Piece(Common::Player::PLAYER2);
            mPosition[SIZE - 1][col] = Common::Piece(Common::Player::PLAYER2);
        }

        for (int row = 1; row < SIZE - 1; ++row) {
            for (int col = 1; col < SIZE - 1; ++col) {
                mPosition[row][col] = Common::Piece();
            }
        }

        mPosition[0][0] = Common::Piece();
        mPosition[0][SIZE - 1] = Common::Piece();
        mPosition[SIZE - 1][0] = Common::Piece();
        mPosition[SIZE - 1][SIZE - 1] = Common::Piece();
    }

    LinesOfActionState(const Common::Piece position[SIZE][SIZE], int player1RemainingPieces, int player2RemainingPieces)
    {
        for (int row = 0; row < SIZE; ++row)
            for (int col = 0; col < SIZE; ++col)
                mPosition[row][col] = position[row][col];

        mPlayerRemainingPieces[static_cast<int>(Common::Player::PLAYER1)] = player1RemainingPieces;
        mPlayerRemainingPieces[static_cast<int>(Common::Player::PLAYER2)] = player2RemainingPieces;
    }

    LinesOfActionState(const LinesOfActionState& other)
        : LinesOfActionState(
            other.mPosition
            , other.mPlayerRemainingPieces[static_cast<int>(Common::Player::PLAYER1)]
            , other.mPlayerRemainingPieces[static_cast<int>(Common::Player::PLAYER2)]
        )
    {}

    Common::Result EvaluateState(const LinesOfActionMove& lastMove) const;
    LinesOfActionMove GetRandomLegalMove(Common::Player player) const;
    int GetNumLegalMoves(Common::Player player) const;
    int GetLegalMoves(Common::Player player, LinesOfActionMove moves[MAX_MOVES]) const;
    LinesOfActionState MakeMove(const LinesOfActionMove&) const;
    void SimulateMove(const LinesOfActionMove&);
    void UndoMove(const LinesOfActionMove&);

    friend bool operator==(const LinesOfActionState& lhs, const LinesOfActionState& rhs);
    friend std::ostream& operator<<(std::ostream& os, const LinesOfActionState& state);

private:
    inline bool IsInBounds(int row, int col) const {
        return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
    }

    inline bool IsSamePlayer(int row, int col, Common::Player player) const {
        return IsInBounds(row, col) && mPosition[row][col] == player;
    }

    /**
     * Attempts to get the legal move and returns it if possible (else returns a nullopt).
     * 1. Can only move distance squares in that direction
     * 2. Can jump over own pieces
     * 3. Cannot jump over opponent pieces
     * 4. Can capture opponent pieces
    */
    template <Common::Direction direction>
    inline std::optional<LinesOfActionMove> TryGetLegalMove(int row, int col, const Common::Player player, int distance) const {
        if (distance == 0) return std::nullopt;

        auto& step = Common::DirectionToStep<direction>::value;
        if (!IsInBounds(row + distance * step.first, col + distance * step.second)) return std::nullopt;

        int prevRow = row;
        int prevCol = col;

        // Check all the inbetween steps
        row += step.first;
        col += step.second;

        while (distance > 1) {
            if (mPosition[row][col].player == Common::GetOtherPlayer(player)) return std::nullopt;

            row += step.first;
            col += step.second;
            --distance;
        }

        // Final step cannot be your own piece
        if (mPosition[row][col].player == player) {
            return std::nullopt;
        }
        else {
            return std::make_optional<LinesOfActionMove>(LinesOfActionMove(player, prevRow, prevCol, row, col, mPosition[row][col].player == Common::GetOtherPlayer(player)));
        }
    }

private:
    Common::Piece mPosition[SIZE][SIZE];
    int mPlayerRemainingPieces[static_cast<int>(Common::Player::PLAYER_TOTAL)];
};
};