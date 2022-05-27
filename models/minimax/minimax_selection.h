#pragma once

#include "model.h"

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
    
        auto evaluation = Simulate(exploreNode);
    }

    NodeT& SelectBestChild()
    {
        NodeT* bestChild = this->mRoot.get();

        while (bestChild->HasChildren())
        {
            bestChild = &bestChild->GetHighestScoreChild();
            
            switch (bestChild->GetValue())
            {
                // Perform minimax in selection phase after a certain number of visits
                if (bestChild->GetVisits() == N_VISITS)
                {
                    // TODO
                }
            }

            if (bestChild->GetValue() == std::numeric_limits<int>::max() || bestChild->GetValue() == std::numeric_limits<int>)
        }

        return *bestChild;
    }


};

}