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
        // std::cout << "finished expansion...\n";

        // Simulation
        NodeT& exploreNode = promisingNode.HasChildren() ? promisingNode.GetRandomChild() : promisingNode;
        // std::cout << "explore node is before\n";
        // std::cout << *exploreNode.GetState();

        // std::cout << "simulation...\n";
        auto evaluation = Model<Standard<TTraits>, TTraits>::Simulate(exploreNode);
    
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

    MoveT SimulationPolicy(StateT& simulateState, Common::Player playerTurn)
    {
        // Select a random move
        return simulateState.GetRandomLegalMove(playerTurn);
    }
};

}