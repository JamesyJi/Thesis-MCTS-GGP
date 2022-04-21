#ifndef MCTS_STATE_H_
#define MCTS_STATE_H_

#include <common/game_types.h>
#include <games/connect4/move.h>

namespace MCTS
{

class State
{
public:
    virtual ~State(){}

    virtual Common::Result EvaluateState() = 0;
    virtual Common::Result EvaluateState(const Move&) = 0;
    virtual int GetLegalMoves(Common::Player, Move[]) const = 0;
    virtual State MakeMove(const Move&) const = 0;
    virtual void SimulateMove(const Move&) = 0;
    
    virtual State& operator=(const State&) = 0;
};

}

#endif