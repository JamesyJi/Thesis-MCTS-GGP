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

static std::ostream& operator<<(std::ostream& os, Direction direction)
{
    switch(direction)
    {
        case NW: return os << "NW";
        case N: return os << "N";
        case NE: return os << "NE";
        case E: return os << "E";
        case SE: return os << "SE";
        case S: return os << "S";
        case SW: return os << "SW";
        case W: return os << "W";
        case END: return os << "END";
    }
}

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

struct CaptureInfo
{
    Direction direction;
    int flankRow;
    int flankCol;
 
    static const int MAX_CAPTURES = 34;  // https://puzzling.stackexchange.com/questions/31896/othello-most-number-of-legal-moves-in-a-given-turn

    friend bool operator==(const CaptureInfo lhs, const CaptureInfo rhs)
    {
        return lhs.direction == rhs.direction &&
            lhs.flankRow == rhs.flankRow &&
            lhs.flankCol == rhs.flankCol;
    }

    friend bool operator!=(const CaptureInfo lhs, const CaptureInfo rhs)
    {
        return !(lhs == rhs);
    }
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
    OthelloMove(Common::Player player, int row, int col, std::vector<CaptureInfo> captures)
    : OthelloMove(player, row, col)
    {
        for (auto& capture : captures)
        {
            captureInfos[numCaptures++] = capture;
        }
    }

    friend bool operator==(const OthelloMove& lhs, const OthelloMove& rhs)
    {   
        // std::cout << lhs << "\n";
        // std::cout << rhs << "\n";

        if (lhs.player != rhs.player ||
            lhs.row != rhs.row ||
            lhs.col != rhs.col ||
            lhs.numCaptures != rhs.numCaptures) 
        {
            return false;
        }

        for (int i = 0; i < lhs.numCaptures; ++i)
        {
            if (lhs.captureInfos[i] != rhs.captureInfos[i]) {
                return false;
            }
        }

        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const OthelloMove& state) {
        os << "OthelloMove " << state.player << " " << state.row << " " << state.col << " " << state.numCaptures << "\n";
        for (int i = 0; i < state.numCaptures; ++i) {
            auto &info = state.captureInfos[i];
            os << "Capture: " << info.direction << " " << info.flankRow << " " << info.flankCol << "\n";
        }
        return os;
    }

    inline void CaptureInDirection(Direction dir, int flankRow, int flankCol)
    {
        captureInfos[numCaptures++] = CaptureInfo{dir, flankRow, flankCol};
    }

    Common::Player player;
    int row = 0;
    int col = 0;

    // Stores info about directions we captured in
    // Stored clockwise from NW (this assumption is very important as its how
    // we can do efficient comparisons!!!)
    CaptureInfo captureInfos[CaptureInfo::MAX_CAPTURES];
    int numCaptures = 0;
};

}