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

    Standard(Common::Player player, const StateT& state, const Games::GameState& gameState)
    : Model<Standard<TTraits>, TTraits>(player, state, gameState)
    {}

    ~Standard(){}

    void ExecuteStrategy()
    {
        // Selection
        // std::cout << "selection...\n";
        NodeT& promisingNode = SelectBestChild();
        StateT& promisingState = promisingNode.GetStateRef();

        // Expansion
        if (promisingState.EvaluateState(promisingNode.GetLastMove()) == Common::Result::ONGOING)
        {
            // std::cout << "expansion...\n";
            promisingNode.ExpandNode();
        }

        // Simulation
        NodeT& exploreNode = promisingNode.HasChildren() ? promisingNode.GetRandomChild() : promisingNode;
        // std::cout << "explore node is before\n";
        // std::cout << *exploreNode.GetState();

        auto evaluation = Simulate(exploreNode);
    
        // std::cout << "explore node is after\n";
        // std::cout << *exploreNode.GetState();

        // Back Propagation
        this->BackPropagate(exploreNode, evaluation);
    }

    NodeT& SelectBestChild()
    {
        // std::cout << "SelectBestChild()\n";
        NodeT& bestChild = *this->mRoot;

        while (bestChild.HasChildren())
        {
            bestChild = bestChild->GetHighestScoreChild();
        }

        return bestChild;
    }

    Common::Result Simulate(NodeT& node)
    {
        StateT simulateState = node.GetStateCopy();
        auto playerTurn = node.GetPlayerTurn();
        MoveT move = node.GetLastMove();
        
        MoveT legalMoves[StateT::MAX_MOVES];
        int nLegalMoves;
        while (simulateState.EvaluateState(move) == Common::Result::ONGOING)
        {
            // std::cout << simulateState;
            // std::cout << "==============\n";
            nLegalMoves = simulateState.GetLegalMoves(playerTurn, legalMoves);
            move = legalMoves[rand() % nLegalMoves];
            simulateState.SimulateMove(move);
            playerTurn = Common::GetOtherPlayer(playerTurn);
        }

        // std::cout << simulateState;            
        // std::cout << "==============\n";

        return simulateState.EvaluateState(move);
    }
};

}