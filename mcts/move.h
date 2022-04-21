#ifndef MCTS_MOVE_H_
#define MCTS_MOVE_H_

#include <common/game_types.h>

namespace MCTS
{

struct Move
{
    Move(Common::Player player)
    : player(player)
    {}
    
    Common::Player player;
};

}

#endif