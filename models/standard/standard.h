#pragma once

#include "model.h"

namespace Models::Standard
{

template<typename TTraits>
class Standard : public Model<Standard<TTraits>, TTraits>
{
public:
    using StateT = typename TTraits::StateT;
    using MoveT = typename TTraits::MoveT;
    using NodeT = MCTS::Node<StateT, MoveT>;

    Standard(Common::Player player, const StateT& state)
    : Model<Standard<TTraits>, TTraits>(player, state)
    {}

    ~Standard(){}

    void ExecuteStrategy()
    {
        // Selection
        NodeT& promisingNode = SelectBestChild();
        
        // Expansion
        if (promisingNode.EvaluateState(promisingNode.mLastMove))
        {
            promisingNode.ExpandNode();
        }

        // Simulation
        NodeT* exploreNode;
        if (promisingNode.HasChildren()) exploreNode = promisingNode;
        else exploreNode = promisingNode;

        auto evaluation = Simulate(exploreNode);
    
        // Back Propagation
        BackPropagate(exploreNode, evaluation);
    }

    NodeT& SelectBestChild()
    {
        NodeT& bestChild = this->mRoot;

        while (bestChild.HasChildren())
        {
            bestChild = bestChild.GetHighestScoreChild();
        }

        return bestChild;
    }

    Common::Result Simulate(NodeT& node)
    {
        StateT& simulateState = node.GetState();
        auto playerTurn = node.GetPlayerTurn();
        MoveT& move = node.GetLastMove();
        
        MoveT legalMoves[StateT::MAX_MOVES];
        int nLegalMoves;
        while (simulateState.EvaluateState(move) == Common::Result::ONGOING)
        {
            nLegalMoves = simulateState.GetLegalMoves(playerTurn, legalMoves);
            move = legalMoves[rand() % nLegalMoves];
            simulateState.SimulateMove(move);
            playerTurn = Common::GetOtherPlayer(playerTurn);
        }

        return simulateState.EvaluateState(move);
    }

    void BackPropagate(NodeT& node, Common::Result result)
    {
        auto winnerloser = Common::GetWinnerAndLoser(result);

        NodeT* curNode = node;
        while (curNode != nullptr)
        {
            switch (curNode->GetPlayerTurn())
            {
                case std::get<0>(winnerloser):
                    curNode->IncrValue();
                    break;
                case std::get<1>(winnerloser):
                    curNode->DecrValue();
                    break;
            }

            curNode->Visit();
            curNode = curNode->GetParent();
        }
    }
};

}