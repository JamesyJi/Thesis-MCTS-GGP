#pragma once

#include "model.h"

#define N_VISITS 2

namespace Models::Minimax
{

template<typename TTraits, auto DepthFunc>
class MinimaxSelection : public Model<MinimaxSelection<TTraits, DepthFunc>, TTraits>
{
public:
    using StateT = typename TTraits::StateT;
    using MoveT = typename TTraits::MoveT;
    using NodeT = MCTS::Node<StateT, MoveT>;

    MinimaxSelection(Common::Player player, const StateT& state, Games::GameState& gameState)
    : Model<MinimaxSelection<TTraits, DepthFunc>, TTraits>(player, state, gameState)
    {}

    ~MinimaxSelection(){}

    void ExecuteStrategy()
    {
        // Selection
        NodeT& promisingNode = SelectBestChild();
        StateT& promisingState = promisingNode.GetStateRef();

        // std::cout << "Expansion\n";
        // Expansion
        if (promisingState.EvaluateState(promisingNode.GetLastMove()) == Common::Result::ONGOING)
        {
            promisingNode.ExpandNode();
        }

        // Simulation
        NodeT& exploreNode = promisingNode.HasChildren() ? promisingNode.GetRandomChild() : promisingNode;

        // std::cout << "Simulation\n";
        auto evaluation = this->Simulate(exploreNode);

        // Back Propagation
        this->BackPropagate(exploreNode, evaluation);
    }

    NodeT& SelectBestChild()
    {
        // std::cout << "Select best child\n";
        NodeT* bestChild = this->mRoot.get();

        while (bestChild->HasChildren())
        {
            bestChild = &bestChild->GetHighestScoreChild();

            // Perform minimax in selection phase after a certain number of visits
            if (bestChild->GetVisits() == N_VISITS)
            {
                auto evaluation = this->MinimaxAB(bestChild->GetStateRef(), bestChild->GetLastMove(), DepthFunc(this->mGameState), Common::Result::PLAYER2_WIN, Common::Result::PLAYER1_WIN, bestChild->GetPlayerTurn());
                this->BackPropagateProven(*bestChild, evaluation);
            }
        }

        return *bestChild;
    }

    Common::Result Simulate(NodeT& node)
    {
        this->mGameState.RunningSimulation();

        StateT simulateState = node.GetStateCopy();
        auto playerTurn = node.GetPlayerTurn();
        MoveT move = node.GetLastMove();
        
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

        return simulateState.EvaluateState(move);
    }
};

}