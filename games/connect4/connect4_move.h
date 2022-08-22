#pragma once

namespace Connect4
{

// Empty is 0
// Board size is 6 high, 7 wide
// 0, 0 top left
// 5, 6, bottom right
// Moves are defined by: (x, y, z) where:
//      x: player1 or 2
//      y: row index (0 to 5)
//      x: col index (0 to 6)
struct Connect4Move
{
    Connect4Move()
    : player(Common::Player::NONE)
    {}

    Connect4Move(Common::Player player, int row, int col)
    : player(player)
    , row(row)
    , col(col)
    {}

    friend bool operator==(const Connect4Move& lhs, const Connect4Move& rhs)
    {
        return lhs.player == rhs.player && lhs.row == rhs.row && lhs.col == rhs.col;
    }

    friend std::ostream& operator<<(std::ostream& os, const Connect4Move& move)
    {
        os << "Connect4Move " << move.player << " " << move.row << " " << move.col;
        return os;
    }

    Common::Player player;
    int row;
    int col;
};

}