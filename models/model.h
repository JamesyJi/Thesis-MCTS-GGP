#pragma once

#include <memory>

#include "game_types.h"
#include "resource.h"
#include "node.h"


namespace Models
{

template<typename TState, typename TMove>
struct Traits
{
    using StateT = TState;
    using MoveT = TMove;
};

template<typename M, typename TTraits>
class Model
{
public:
    using StateT = typename TTraits::StateT;
    using MoveT = typename TTraits::MoveT;
    using NodeT = MCTS::Node<StateT, MoveT>;
    
    MoveT DecideMove(Common::Resource& resource);
    
    void NotifyOfOpponentMove(MoveT& move);

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

    Model(Common::Player player, const StateT& state)
    : mPlayer(player)
    , mRoot(std::make_unique<StateT>(state), player, nullptr, MoveT())
    {}

protected:
    Common::Player mPlayer;
    NodeT mRoot;
};

}
