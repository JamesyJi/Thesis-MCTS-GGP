#pragma once

/**
 * 0, 0 is top left
 * ROW - 1, COL - 1 is bottom right
 * PLAYER 1 starts first
 * PLAYER 1 is on the sides, PLAYER 2 is on the top/bottom
 */

namespace LinesOfAction
{

struct LinesOfActionMove
{
    LinesOfActionMove()
        : player(Common::Player::NONE)
    {}

    LinesOfActionMove(Common::Player player, int prevRow, int prevCol, int row, int col, bool capture)
        : player(player), prevRow(prevRow), prevCol(prevCol), row(row), col(col), capture(capture)
    {}

    friend bool operator==(const LinesOfActionMove& lhs, const LinesOfActionMove& rhs) {
        return lhs.player == rhs.player && lhs.prevRow == rhs.prevRow && lhs.prevCol == rhs.prevCol && lhs.row == rhs.row && lhs.col == rhs.col && lhs.capture == rhs.capture;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinesOfActionMove& move)
    {
        os << move.player << " ";
        os << move.prevRow << " ";
        os << move.prevCol << " ";
        os << move.row << " ";
        os << move.col << " ";
        os << move.capture;

        return os;
    }

    Common::Player player;
    int prevRow;
    int prevCol;
    int row;
    int col;
    bool capture;
};
};