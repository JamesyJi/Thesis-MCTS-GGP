#ifndef GAMES_CONNECT4_STATE_H_
#define GAMES_CONNECT4_STATE_H_

#include <common/pieces.h>
#include <interfaces/state.h>
#include <games/connect4/move.h>

namespace Connect4 
{

class Connect4State : public Interfaces::State<Connect4State, Connect4Move>
{
public:
    static const int ROWS = 6;
    static const int COLS = 7;
    static const int WIN_COND = 4; // Required number of consecutive pieces to win
    static const int MAX_MOVES = 7; // Maximum number of possible moves at any given time

    Connect4State(const Common::Piece position[ROWS][COLS])
    {
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                mPosition[row][col] = position[row][col];
    }
    
    ~Connect4State(){}
    
    Common::Result EvaluateState();
    Common::Result EvaluateState(const Connect4Move&);
    int GetLegalMoves(Common::Player, Connect4Move[MAX_MOVES]) const;
    Connect4State MakeMove(const Connect4Move&) const;
    void SimulateMove(const Connect4Move&);
    void Print();
    bool Equals();

private:
    Common::Piece mPosition[ROWS][COLS];
};

}

#endif