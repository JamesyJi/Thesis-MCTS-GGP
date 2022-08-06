#pragma once

// Player 1 starts at top of board (0)
// Player 2 starts at bottom of board (ROW - 1)
// 0, 0 is top left
// ROW - 1, COL - 1 is bottom right

namespace Breakthrough
{

struct BreakthroughMove
{
    BreakthroughMove()
    : player(Common::Player::NONE)
    {}

    BreakthroughMove(Common::Player player, int prevRow, int prevCol, int row, int col, bool capture)
    : player(player)
    , prevRow(prevRow)
    , prevCol(prevCol)
    , row(row)
    , col(col)
    , capture(capture)
    {}

    friend bool operator==(const BreakthroughMove& lhs, const BreakthroughMove& rhs)
    {
        return lhs.player == rhs.player
            && lhs.prevRow == rhs.prevRow
            && lhs.prevCol == rhs.prevCol
            && lhs.row == rhs.row
            && lhs.col == rhs.col
            && lhs.capture == rhs.capture;
    }

    friend std::ostream& operator<<(std::ostream& os, const BreakthroughMove& move)
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

}