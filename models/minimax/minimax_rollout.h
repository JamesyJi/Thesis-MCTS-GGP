#pragma once

#include "model.h"

namespace Models::Minimax
{

template <typename TTraits, auto DepthFunc>
class MinimaxRollout : public Model<MinimaxRollout<TTraits, DepthFunc>, TTraits>
{
public:
    using StateT = typename TTraits::StateT;
    using MoveT = typename TTraits::MoveT;
    using NodeT = MCTS::Node<StateT, MoveT>;

    MinimaxRollout(const StateT& state, Games::GameState& gameState)
        : Model<MinimaxRollout<TTraits, DepthFunc>, TTraits>(state, gameState)
    {
    }

    ~MinimaxRollout() {}

    void ExecuteStrategy()
    {
        // Selection
        NodeT& promisingNode = SelectBestChild();
        StateT& promisingState = promisingNode.GetStateRef();

        if (promisingState.EvaluateState(promisingNode.GetLastMove()) == Common::Result::ONGOING)
        {
            promisingNode.ExpandNode();
        }

        // Simulation
        NodeT& exploreNode = promisingNode.HasChildren() ? promisingNode.GetRandomChild() : promisingNode;
        auto evaluation = Model<MinimaxRollout<TTraits, DepthFunc>, TTraits>::Simulate(exploreNode);


        // Back Propagation
        this->BackPropagate(exploreNode, evaluation);
    }

    NodeT& SelectBestChild()
    {
        NodeT* bestChild = this->mRoot.get();
        while (bestChild->HasChildren())
        {
            bestChild = &bestChild->GetHighestScoreChild();
        }

        return *bestChild;
    }

    MoveT SimulationPolicy(StateT& simulateState, const Common::Player playerTurn) const
    {
        int bestMove = -1;
        Common::Result bestEval = Common::PlayerToResult(Common::GetOtherPlayer(playerTurn));

        const auto& compareBetterEval = std::invoke([&]() -> std::function<bool(Common::Result, Common::Result)>
            {
                switch (playerTurn)
                {
                case Common::Player::PLAYER1:
                    return Common::operator>;
                case Common::Player::PLAYER2:
                    return Common::operator<;
                default:
                    throw std::runtime_error("Should only be player 1 or 2 in MinimaxRollout Simulation Policy");
                } });

        // Minimax options to determine an optimal move
        MoveT legalMoves[StateT::MAX_MOVES];
        int nLegalMoves = simulateState.GetLegalMoves(playerTurn, legalMoves);
        for (int i = 0; i < nLegalMoves; ++i)
        {
            simulateState.SimulateMove(legalMoves[i]);
            auto evaluation = this->MinimaxAB(simulateState, legalMoves[i],

                // TODO: How to get depth from state?
                // DepthFunc(mGameState),
                DepthFunc(this->mGameState),
                Common::Result::PLAYER2_WIN,
                Common::Result::PLAYER1_WIN,
                Common::GetOtherPlayer(playerTurn));
            simulateState.UndoMove(legalMoves[i]);

            if (compareBetterEval(evaluation, bestEval))
            {
                bestEval = evaluation;
                bestMove = i;
            }
        }

        switch (bestMove)
        {
        case -1:
            return legalMoves[rand() % nLegalMoves];
        default:
            return legalMoves[bestMove];
        }
    }
};

}