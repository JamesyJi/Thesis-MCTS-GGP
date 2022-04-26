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

template<typename M, typename Traits>
class Model
{
public:
    using GameStateT = TTraits::GameStateT;
    using MoveT = TTraits::MoveT;
    using NodeT = TTraits::NodeT;
    
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


// template<typename GameState, typename Move>
// class Model
// {
// public:
//     using GState = MCTS::State<GameState, Move>;
//     using GNode = MCTS::Node<GameState, Move>;

//     Model(Common::Player player, GState& state)
//     : mPlayer(player)
//     {}

//     ~Model(){}

//     GameState& DecideMove(Common::Resource&);

//     void ExecuteStrategy() = 0;
//     virtual GNode& SelectBestChild() = 0;
//     virtual void BackPropagate() = 0;

// protected:
//     Common::Player mPlayer;
//     GNode& mRoot;
// };

}
