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

    Standard(Common::Player player, const StateT& state, Games::GameState& gameState)
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

        // std::cout << "simulation...\n";
        auto evaluation = this->Simulate(exploreNode);
    
        // std::cout << "explore node is after\n";
        // std::cout << *exploreNode.GetState();

        // Back Propagation
        // std::cout << "backpropagation...\n";
        this->BackPropagate(exploreNode, evaluation);
    }

    NodeT& SelectBestChild()
    {
        // std::cout << "SelectBestChild()\n";
        NodeT* bestChild = this->mRoot.get();

        while (bestChild->HasChildren())
        {
            bestChild = &bestChild->GetHighestScoreChild();
        }

        return *bestChild;
    }

    Common::Result Simulate(NodeT& node)
    {
        this->mGameState.RunningSimulation();

        StateT simulateState = node.GetStateCopy();

        auto playerTurn = node.GetPlayerTurn();
        MoveT move = node.GetLastMove();
        
        MoveT legalMoves[StateT::MAX_MOVES];
        while (simulateState.EvaluateState(move) == Common::Result::ONGOING)
        {
            // std::cout << simulateState;
            // std::cout << "==============\n";
            move = simulateState.GetRandomLegalMove(playerTurn);
            simulateState.SimulateMove(move);
            playerTurn = Common::GetOtherPlayer(playerTurn);
        }

        // std::cout << simulateState;            
        // std::cout << "==============\n";
        // std::cout << "finished\n";
        return simulateState.EvaluateState(move);
    }
};

}