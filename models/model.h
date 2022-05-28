#pragma once

#include <memory>
#include <utility>
#include <iostream>

#include "game_types.h"
#include "resource.h"
#include "node.h"
#include "node.cpp"

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
    
    MoveT DecideMove(Common::Resource& resource)
    {
        std::cout << "deciding move...\n";
        while (resource.UseResource())
        {
            static_cast<M*>(this)->ExecuteStrategy();
        }

        std::cout << "DECIDED MOVE\n";
        // mRoot->LogChildStats();

        // int i;
        // std::cin >> i;
        
        mRoot = mRoot->GetMostVisitedChild();
        mRoot->NullParent();

        return mRoot->GetLastMove();
    }
    
    void NotifyOfOpponentMove(MoveT& move)
    {
        mRoot = mRoot->GetChild(move);
        // mRoot = std::move(mRoot->GetChild(move));
        mRoot->NullParent();
    }

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

    void BackPropagate(NodeT& node, Common::Result result);

    void BackPropagateProven(NodeT& node, Common::Result result);

    Common::Result Minimax(StateT& state, const MoveT& lastMove, int depth, Common::Result alpha, Common::Result beta, Common::Player player);

    Model(Common::Player player, const StateT& state)
    : mPlayer(player)
    , mRoot(std::make_unique<NodeT>(state, Common::Player::PLAYER1, nullptr, MoveT()))
    {}

protected:
    Common::Player mPlayer;
    std::unique_ptr<NodeT> mRoot;
};

}

#include "model.cpp" // Template definitions