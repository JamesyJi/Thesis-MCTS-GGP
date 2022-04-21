#ifndef MCTS_STATE_H_
#define MCTS_STATE_H_

#include <common/game_types.h>
#include <games/connect4/move.h>

namespace MCTS
{

template <typename GameState, typename Move>
class State
{
public:
    virtual ~State(){}

    virtual Common::Result EvaluateState() = 0;
    virtual Common::Result EvaluateState(const Move&) = 0;
    virtual int GetLegalMoves(Common::Player, Move[]) const = 0;
    virtual GameState MakeMove(const Move&) const = 0;
    virtual void SimulateMove(const Move&) = 0;
    
    virtual GameState& operator=(const GameState&) = 0;
    virtual friend bool operator==(const Connect4State&, const Connect4State&) = 0;
    virtual friend ostream& operator<<(ostream& os, const GameState&) = 0;
};

}

#endif