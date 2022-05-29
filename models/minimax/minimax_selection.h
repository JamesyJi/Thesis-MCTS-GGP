#pragma once

#include "model.h"

#define DEPTH 4
#define N_VISITS 2

namespace Models::Minimax
{

template<typename TTraits>
class MinimaxSelection : public Model<MinimaxSelection<TTraits>, TTraits>
{
public:
    using StateT = typename TTraits::StateT;
    using MoveT = typename TTraits::MoveT;
    using NodeT = MCTS::Node<StateT, MoveT>;

    MinimaxSelection(Common::Player player, const StateT& state)
    : Model<MinimaxSelection<TTraits>, TTraits>(player, state)
    {}

    ~MinimaxSelection(){}

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
    
        auto evaluation = this->Simulate(exploreNode);

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
            if (bestChild->GetVisits() == N_VISITS)
            {
                auto evaluation = this->MinimaxAB(bestChild->GetStateRef(), bestChild->GetLastMove(), DEPTH, Common::Result::PLAYER2_WIN, Common::Result::PLAYER1_WIN, bestChild->GetPlayerTurn());
                this->BackPropagateProven(*bestChild, evaluation);
            }
        }

        return *bestChild;
    }
};

}