#pragma once

// 0,0 is top left
// ROW - 1, COL - 1 is bottom right

namespace Othello
{

struct Step
{
    int row;
    int col;
};

enum Direction {
    NW,
    N,
    NE,
    E,
    SE,
    S,
    SW,
    W,
    END // Helps us terminate loops
};

const int NUM_DIRECTIONS = 8;

// Should cycle through all the directions clockwise from NW to W
const Step Directions[NUM_DIRECTIONS] = 
{
    [Direction::NW] = {-1, 1},
    [Direction::N] = {-1, 0},
    [Direction::NE] = {-1, 1},
    [Direction::E] = {0, 1},
    [Direction::SE] = {1, 1},
    [Direction::S] = {1, 0},
    [Direction::SW] = {1, -1},
    [Direction::W] = {0, -1}
};

struct OthelloMove
{
    OthelloMove()
    : player(Common::Player::NONE)
    {}

    OthelloMove(Common::Player player, int row, int col)
    : player(player)
    , row(row)
    , col(col)
    {}

    friend bool operator==(const OthelloMove& lhs, const OthelloMove& rhs)
    {
        for (int dir = 0; dir != END; ++dir)
        {
            if (lhs.directions[dir] != rhs.directions[dir]) return false;
        }

        return lhs.player == rhs.player &&
            lhs.row == rhs.row &&
            lhs.col == rhs.col;
    }

    void CaptureInDirection(Direction dir)
    {
        directions[dir] = true;
    }

    Common::Player player;
    int row = 0;
    int col = 0;
    bool directions[NUM_DIRECTIONS]{}; // True if we captured in that direction
};

}