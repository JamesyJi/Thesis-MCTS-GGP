#pragma once

#include "common/game_types.h"
#include "common/resource.h"
#include "mcts/state.h"
#include "mcts/node.h"

namespace Models
{

template<typename TGameState, typename TMove>
struct Traits
{
    using GameStateT = TGameState;
    using MoveT = TMove;
    using NodeT = MCTS::Node<TGameState, TMove>;
};

template<typename M, typename TTraits>
class Model
{
public:
    using GameStateT = typename TTraits::GameStateT;
    using MoveT = typename TTraits::MoveT;
    using NodeT = typename TTraits::NodeT;
    
    MoveT DecideMove(Common::Resource& resource);
    
    void ExecuteStrategy()
    {
        static_cast<M*>(this)->ExecuteStrategy();
    }

    NodeT& SelectBestChild()
    {
        static_cast<M*>(this)->SelectBestChild();
    }

    Common::Result Simulate(NodeT& node)
    {
        static_cast<M*>(this)->Simulate(node);
    }

    void BackPropagate(NodeT& node, Common::Result result)
    {
        static_cast<M*>(this)->BackPropagate(node, result);
    }


protected:
    Model(Common::Player player, GameStateT& state)
    : mPlayer(player)
    {}

    Common::Player mPlayer;
    NodeT mRoot;
};

}
