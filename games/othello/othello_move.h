#pragma once

// 0,0 is top left
// ROW - 1, COL - 1 is bottom right

#include <vector>
#include <iostream>

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
    [Direction::NW] = {-1, -1},
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

    // Used for ease of testing
    OthelloMove(Common::Player player, int row, int col, int captures[NUM_DIRECTIONS])
    : OthelloMove(player, row, col)
    {
        for (int i = 0; i < NUM_DIRECTIONS; ++i)
        {
            numCaptures[i] = captures[i];
        }
    }

    friend bool operator==(const OthelloMove& lhs, const OthelloMove& rhs)
    {
        for (int dir = 0; dir != END; ++dir)
        {
            if (lhs.numCaptures[dir] != rhs.numCaptures[dir]) return false;
        }

        return lhs.player == rhs.player &&
            lhs.row == rhs.row &&
            lhs.col == rhs.col;
    }

    friend std::ostream& operator<<(std::ostream& os, const OthelloMove& state) {
        os << "OthelloMove " << state.player << " " << state.row << " " << state.col << " ";
        for (int i = 0; i < NUM_DIRECTIONS; ++i) {
            // Direction dir = static_cast<Direction>
            os << state.numCaptures[i] << ", ";
        }
        os << "\n";
        return os;
    }

    inline void CaptureInDirection(Direction dir, int numCaptured)
    {
        numCaptures[dir] = numCaptured;
    }

    Common::Player player;
    int row = 0;
    int col = 0;

    // Represents the number of pieces we captured in a certain direction
    // numCaptures[NW] = 2 means we captured 2 pieces (our flank piece is 3 pieces away)
    // in the NW direction
    int numCaptures[NUM_DIRECTIONS]{0};

};

}