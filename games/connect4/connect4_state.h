#pragma once

#include <iostream>
#include "pieces.h"
#include "connect4_move.h"

namespace Connect4 
{

class Connect4State
{

public:
    static const int ROWS = 6;
    static const int COLS = 7;
    static const int MAX_MOVES = 7; // Maximum number of possible moves at any given time
    static const int WIN_COND = 4; // Required number of consecutive pieces to win

    Connect4State()
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = Common::Piece();        
    }

    Connect4State(const Common::Piece position[ROWS][COLS])
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = position[row][col];
    }

    Connect4State(const Connect4State& other)
    : Connect4State(other.mPosition)
    {}
    
    ~Connect4State(){}

    Common::Result EvaluateState(const Connect4Move& move);
    int GetLegalMoves(Common::Player player, Connect4Move[MAX_MOVES]) const;
    Connect4State MakeMove(const Connect4Move&) const;
    void SimulateMove(const Connect4Move&);
    void UndoMove(const Connect4Move&);

    friend bool operator==(const Connect4State& lhs, const Connect4State& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Connect4State& state);

    // TODO: assignment overload

private:
    Common::Piece mPosition[ROWS][COLS];
};

}
