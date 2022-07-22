#pragma once

#include <memory>
#include <utility>
#include <iostream>

#include "game_types.h"
#include "resource.h"
#include "node.h"
#include "node.cpp"
#include "game_state.h"

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

        // std::cout << "enter a number to continue\n";
        // int i;
        // std::cin >> i;
        
        mRoot = mRoot->DecideOnBestChild();
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
        return static_cast<M*>(this)->SelectBestChild();
    }

    Common::Result Simulate(NodeT& node)
    {
        return static_cast<M*>(this)->Simulate(node);
    }

    void BackPropagate(NodeT& node, Common::Result result);

    void BackPropagateProven(NodeT& node, Common::Result result);

    static Common::Result MinimaxAB(StateT& state, const MoveT& lastMove, int depth, Common::Result alpha, Common::Result beta, Common::Player player);

    Model(Common::Player player, const StateT& state, Games::GameState& gameState)
    : mPlayer(player)
    , mRoot(std::make_unique<NodeT>(state, Common::Player::PLAYER1, nullptr, MoveT()))
    , mGameState(gameState)
    {};

protected:
    const Common::Player mPlayer;
    std::unique_ptr<NodeT> mRoot;
    Games::GameState& mGameState;
};

// Backpropagates results
template<typename M, typename TTraits>
void Model<M, TTraits>::BackPropagate(NodeT& node, Common::Result result)
{
    auto winnerloser = Common::GetWinnerAndLoser(result);

        NodeT* curNode = &node;
        while (curNode != nullptr)
        {
            if (curNode->IsProven())
            {
                curNode = curNode->GetParent();
                continue;
            }

            if (std::get<1>(winnerloser) == curNode->GetPlayerTurn())
            {
                curNode->IncrValue();
            } else if (std::get<0>(winnerloser) == curNode->GetPlayerTurn()) {
                curNode->DecrValue();
            }

            curNode->Visit();
            curNode = curNode->GetParent();
        }
}

// Backpropagates proven results
template<typename M, typename TTraits>
void Model<M, TTraits>::BackPropagateProven(NodeT& node, Common::Result result)
{
    if (result == Common::Result::ONGOING || result == Common::Result::DRAW)
    {
        return;
    }

    auto curPlayer = node.GetPlayerTurn();
    auto otherPlayer = Common::GetOtherPlayer(curPlayer);

    NodeT* curNode;

    if (result == Common::PlayerToResult(curPlayer))
    {
        // The player who moved into this turn lost
        node.template ProveResult<Common::Proven::LOSS>();
        curNode = node.GetParent();
    } else if (result == Common::PlayerToResult(otherPlayer))
    {
        // The player who moved into this turn won
        node.template ProveResult<Common::Proven::WIN>();
        curNode = node.GetParent();
        if (curNode != nullptr) {
            curNode->template ProveResult<Common::Proven::LOSS>();
            curNode = curNode->GetParent();
        }
    }

    // Try to propagate everything up the tree as far as possible by checking
    // to see if all children nodes are proven
    while (curNode != nullptr)
    {
        if (!curNode->TryProveWinFromChildren())
        {
            return;
        }

        // Node has been proven to be a win. The prior move must be a loss
        curNode = curNode->GetParent();
        if (curNode != nullptr)
        {
            curNode->template ProveResult<Common::Proven::LOSS>();
            curNode = curNode->GetParent();
        }
    }
}

template<typename M, typename TTraits>
Common::Result Model<M, TTraits>::MinimaxAB(StateT& state, const MoveT& lastMove, int depth, Common::Result alpha, Common::Result beta, Common::Player player)
{

    if (depth == 0 || state.EvaluateState(lastMove) != Common::Result::ONGOING) return state.EvaluateState(lastMove);

    MoveT legalMoves[StateT::MAX_MOVES];
    int nLegalMoves = state.GetLegalMoves(player, legalMoves);
    
    switch (player)
    {
        case Common::Player::PLAYER1:
        {
            Common::Result maxEval = Common::Result::PLAYER2_WIN;

            for (int i = 0; i < nLegalMoves; ++i)
            {
                state.SimulateMove(legalMoves[i]);
                Common::Result evaluation = MinimaxAB(state, legalMoves[i], depth - 1, alpha, beta, Common::GetOtherPlayer(player));
                state.UndoMove(legalMoves[i]);    
                if (evaluation > maxEval) maxEval = evaluation;
                if (maxEval > alpha) alpha = maxEval;
                if (beta <= alpha) break;
            }

            return maxEval;
        }
        case Common::Player::PLAYER2:
        {
            Common::Result minEval = Common::Result::PLAYER1_WIN;
            
            for (int i = 0; i < nLegalMoves; ++i)
            {
                state.SimulateMove(legalMoves[i]);
                Common::Result evaluation = MinimaxAB(state, legalMoves[i], depth - 1, alpha, beta, Common::GetOtherPlayer(player));
                state.UndoMove(legalMoves[i]);
                if (evaluation < minEval) minEval = evaluation;
                if (minEval < beta) beta = minEval;
                if (beta <= alpha) break;
            }

            return minEval;
        }
        default:
            throw "player's turn cannot be none in minimax";
    }
}

}
