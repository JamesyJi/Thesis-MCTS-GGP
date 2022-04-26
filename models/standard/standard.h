#pragma once

#include "models/model.h"

namespace Models::Standard
{

template<typename TTraits>
class Standard : public Model<Standard<TTraits>, TTraits>
{
public:
    using GameStateT = TTraits::GameStateT;
    using MoveT = TTraits::MoveT;
    using NodeT = TTraits::NodeT;  

    Standard(Common::Player player, GameStateT& state)
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
        NodeT& exploreNode;
        if (promisingNode.HasChildren()) exploreNode = promisingNode
        else exploreNode = promisingNode;

        auto evaluation = Simulate(exploreNode);
    
        // Back Propagation
        BackPropagate(exploreNode, evaluation);
    }

    NodeT& SelectBestChild()
    {
        NodeT& bestChild = mRoot;

        while (bestChild.HasChildren())
        {
            bestChild = bestChild.GetHighestScoreChild();
        }

        return bestChild;
    }

    Common::Result Simulate(NodeT& node)
    {
        GameStateT& simulateState = node.GetState();
        auto playerTurn = node.GetPlayerTurn();
        MoveT& move = node.GetLastMove();
        
        Move[GameStateT::MAX_MOVES] legalMoves;
        int nLegalMoves;
        while (simulateState.EvaluateState(move) == Common::Result::ONGOING)
        {
            nLegalMoves = simulateState.GetLegalMoves(playerTurn, legalMoves);
            move = legalMoves[rand() % nLegalMoves];
            simualteState.SimulateMove(move);
            playerTurn = Common::GetOtherPlayer(playerTurn);
        }

        return simulateState.EvaluateState(move);
    }

    void BackPropagate()
    {
        
    }
};

}