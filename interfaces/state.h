#ifndef INTERFACES_STATE_H_
#define INTERFACES_STATE_H_

#include <common/game_types.h>
#include <games/connect4/move.h>

namespace Interfaces
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
    virtual void Print() = 0;
    virtual bool Equals() = 0;
};

}

#endif