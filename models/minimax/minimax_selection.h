#pragma once

#include "model.h"

#define N_VISITS 2

namespace Models::Minimax
{

template <typename TTraits, auto DepthFunc>
class MinimaxSelection : public Model<MinimaxSelection<TTraits, DepthFunc>, TTraits>
{
public:
    using StateT = typename TTraits::StateT;
    using MoveT = typename TTraits::MoveT;
    using NodeT = MCTS::Node<StateT, MoveT>;

    MinimaxSelection(const StateT& state, Games::GameState& gameState)
        : Model<MinimaxSelection<TTraits, DepthFunc>, TTraits>(state, gameState)
    {
    }

    ~MinimaxSelection() {}

    void ExecuteStrategy()
    {
        // Selection
        NodeT& promisingNode = SelectBestChild();
        StateT& promisingState = promisingNode.GetStateRef();

        // Expansion
        if (promisingState.EvaluateState(promisingNode.GetLastMove()) == Common::Result::ONGOING)
        {
            promisingNode.ExpandNode();
        }

        // Simulation
        NodeT& exploreNode = promisingNode.HasChildren() ? promisingNode.GetRandomChild() : promisingNode;
        auto evaluation = Model<MinimaxSelection<TTraits, DepthFunc>, TTraits>::Simulate(exploreNode);

        // Back Propagation
        this->BackPropagate(exploreNode, evaluation);
    }

    NodeT& SelectBestChild()
    {
        NodeT* bestChild = this->mRoot.get();

        while (bestChild->HasChildren())
        {
            bestChild = &bestChild->GetHighestScoreChild();

            // Perform minimax in selection phase after a certain number of visits
            if (!bestChild->AlreadyMinimaxed() && bestChild->GetVisits() >= N_VISITS)
            {
                auto evaluation = this->MinimaxAB(
                    bestChild->GetStateRef(),
                    bestChild->GetLastMove(),
                    // DepthFunc(static_cast<std::size_t>(bestChild->GetBranchingFactor())),
                    DepthFunc(this->mGameState),
                    Common::Result::PLAYER2_WIN,
                    Common::Result::PLAYER1_WIN,
                    bestChild->GetPlayerTurn()
                );
                this->BackPropagateProven(*bestChild, evaluation);
                bestChild->FlagAsAlreadyMinimaxed();
            }
        }

        return *bestChild;
    }

    MoveT SimulationPolicy(StateT& simulateState, const Common::Player playerTurn) const
    {
        // Select a random move
        return simulateState.GetRandomLegalMove(playerTurn);
    }
};

}