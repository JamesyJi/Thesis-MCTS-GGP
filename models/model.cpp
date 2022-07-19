#include <iostream>

#include "model.h"

namespace Models
{

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

    NodeT* curNode = nullptr;

    if (result == Common::PlayerToResult(curPlayer))
    {
        // The player who moved into this turn lost
        node.template ProveResult<Common::Proven::LOSS>();
        curNode = node.GetParent();
    } else
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