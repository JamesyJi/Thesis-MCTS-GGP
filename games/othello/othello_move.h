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

    OthelloMove(Common::Player player, int row, int col, Direction direction, int flankRow, int flankCol)
    : player(player)
    , row(row)
    , col(col)
    , flankRow(flankRow)
    , flankCol(flankCol)
    {}

    friend bool operator==(const OthelloMove& lhs, const OthelloMove& rhs)
    {
        return lhs.player == rhs.player &&
            lhs.row == rhs.row &&
            lhs.col == rhs.col &&
            lhs.flankRow == rhs.flankRow &&
            lhs.flankCol == rhs.flankCol;
    }

    Common::Player player;
    int row;
    int col;
    Direction direction; // Which direction we captured in
    
    // The flanking row/col between which we captured pieces
    int flankRow;
    int flankCol;

};

}