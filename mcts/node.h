#ifndef MCTS_NODE_H_
#define MCTS_NODE_H_

#include <mcts/state.h>
#include <common/game_types.h>

namespace MCTS
{

class Node
{
public:
    Node(State& state, Common::Player player, Node& parent)
    : mState(state)
    , mPlayer(player)
    , mParent(parent)
    , 
    {}

private:
    State& mState;
    Player mPlayer;
    Node* const mParent;
};

}

#endif